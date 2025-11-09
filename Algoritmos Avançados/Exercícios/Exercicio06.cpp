#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>  

using namespace std;
pair<double, double> mid;
const double EPSILON = 1e-9;

// Determina o quadrante de um ponto
int quad(pair<double, double> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}

bool compare(pair<double, double> p1, pair<double, double> q1)
{
    pair<double, double> p = make_pair(p1.first - mid.first,
                                p1.second - mid.second);
    pair<double, double> q = make_pair(q1.first - mid.first,
                                q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second*q.first < q.second*p.first);
}

vector<pair<double, double>> bruteForceHull(vector<pair<double, double>> pontos){
    if(pontos.size() < 3) return pontos;
    
    // Verificar se todos os pontos são colineares
    bool todosColineares = true;
    if(pontos.size() > 2){
        for(int i = 2; i < pontos.size(); i++){
            double cross = (pontos[1].first - pontos[0].first) * (pontos[i].second - pontos[0].second) - 
                          (pontos[1].second - pontos[0].second) * (pontos[i].first - pontos[0].first);
            if(abs(cross) > 1e-9){
                todosColineares = false;
                break;
            }
        }
    }
    
    // Se são, retornar todos ordenados
    if(todosColineares){
        sort(pontos.begin(), pontos.end());
        return pontos;  
    }

    // Encontrar o ponto inicial (menor y, depois menor x)
    int minIdx = 0;
    for(int i = 1; i < pontos.size(); i++){
        if(pontos[i].second < pontos[minIdx].second || 
           (abs(pontos[i].second - pontos[minIdx].second) < 1e-9 && 
            pontos[i].first < pontos[minIdx].first)){
            minIdx = i;
        }
    }
    swap(pontos[0], pontos[minIdx]);
    
    pair<double, double> pivot = pontos[0];
    
    // Ordenar por ângulo polar
    sort(pontos.begin() + 1, pontos.end(), [pivot](pair<double, double> a, pair<double, double> b){
        double dx1 = a.first - pivot.first;
        double dy1 = a.second - pivot.second;
        double dx2 = b.first - pivot.first;
        double dy2 = b.second - pivot.second;
        
        double cross = dx1 * dy2 - dy1 * dx2;
        if(abs(cross) > 1e-9) return cross > 0;
        
        return dx1*dx1 + dy1*dy1 < dx2*dx2 + dy2*dy2;
    });
    
    // Graham Scan
    vector<pair<double, double>> hull;
    for(auto p : pontos){
        while(hull.size() > 1){
            auto p2 = hull.back();
            auto p1 = hull[hull.size()-2];
            
            double cross = (p2.first - p1.first) * (p.second - p1.second) - 
                         (p2.second - p1.second) * (p.first - p1.first);
            
            if(cross < 1e-9) hull.pop_back();
            else break;
        }
        hull.push_back(p);
    }
    
    return hull;
}

// Checa se a linha está cruzando o polígonon ou não
int orientation(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    double res = (b.second-a.second)*(c.first-b.first) - (c.second-b.second)*(b.first-a.first);
    
    if (abs(res) < EPSILON)  return 0;   
    if (res > 0)   return 1;
    return -1;
}


bool allColinearCombined(const vector<pair<double,double>>& a, const vector<pair<double,double>>& b){
    // se conjunto total tem <=2 pontos, é colinear por definição
    int n = a.size() + b.size();
    if(n <= 2) return true;

    // faz um array com todos os pontos
    vector<pair<double,double>> all;
    all.reserve(n);
    for(auto& p: a) all.push_back(p);
    for(auto& p: b) all.push_back(p);

    // verifica se são todos colineares
    pair<double,double> p0 = all[0];
    int idx = 1;

    pair<double,double> p1 = all[idx];
    for(int i = idx+1; i < all.size(); ++i){
        // calcula o produto vetorial
        double cross = (p1.first - p0.first)*(all[i].second - p0.second) - (p1.second - p0.second)*(all[i].first - p0.first);
        if(abs(cross) > EPSILON) return false;
    }
    return true;
}


vector<pair<double, double>> merge(vector<pair<double, double>> h1, vector<pair<double, double>> h2){
    int id1 = 0, id2 = 0, s1 = h1.size(), s2 = h2.size();

    // Caso especial: se a união de todos os pontos for colinear, retorna todos ordenados
    if(allColinearCombined(h1, h2)){
        vector<pair<double,double>> all;

        // cria um array com todos os pontos colineares
        all.reserve(s1+s2);
        for(auto &p: h1) all.push_back(p);
        for(auto &p: h2) all.push_back(p);
        
        // ordena por x ou y
        sort(all.begin(), all.end(), [](const pair<double,double>& a, const pair<double,double>& b){
            if (abs(a.first - b.first) > EPSILON) return a.first < b.first;
            return a.second < b.second;
        });
        
        return all;
    }

    // ponto mais a direita do h1
    for(int i=0; i<h1.size(); i++) if(h1[i].first > h1[id1].first) id1 = i;
    
    // ponto mais a esquerda do h2
    for(int i=0; i<h2.size(); i++) if(h2[i].first < h2[id2].first) id2 = i;

    // achando a tangente superior
    int ID1 = id1, ID2 = id2;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(h2[ID2], h1[ID1], h1[(ID1+1)%s1]) >=0)
            ID1 = (ID1 + 1) % s1;

        while (orientation(h1[ID1], h2[ID2], h2[(s2+ID2-1)%s2]) <=0)
        {
            ID2 = (s2+ID2-1)%s2;
            done = 0;
        }
    }

    int cima1 = ID1, cima2 = ID2;
    ID1 = id1, ID2=id2;
    done = 0;
    // achando a tangente inferior
    while (!done)
    {
        done = 1;
        while (orientation(h1[ID1], h2[ID2], h2[(ID2+1)%s2])>=0)
            ID2=(ID2+1)%s2;

        while (orientation(h2[ID2], h1[ID1], h1[(s1+ID1-1)%s1])<=0)
        {
            ID1=(s1+ID1-1)%s1;
            done=0;
        }
    }

    int baixo1 = ID1, baixo2 = ID2;
    vector<pair<double, double>> fecho;

    int ind = cima1;
    fecho.push_back(h1[cima1]);
    while (ind != baixo1)
    {
        ind = (ind+1)%s1;
        fecho.push_back(h1[ind]);
    }

    ind = baixo2;
    fecho.push_back(h2[baixo2]);
    while (ind != cima2)
    {
        ind = (ind+1)%s2;
        fecho.push_back(h2[ind]);
    }
    return fecho;

}

vector<pair<double, double>> divideAndConquer(vector<pair<double, double>> pontos){
    // caso base
    if(pontos.size() <= 5) return bruteForceHull(pontos);

    int m = pontos.size()/2;
    vector<pair<double, double>> left, right;
    for(int i=0; i<m; i++)              left.push_back(pontos[i]);
    for(int i=m; i<pontos.size(); i++)  right.push_back(pontos[i]);

    vector<pair<double, double>> hull1 = divideAndConquer(left);
    vector<pair<double, double>> hull2 = divideAndConquer(right);

    return merge(hull1, hull2);
}

vector<pair<double, double>> reordenarFecho(vector<pair<double, double>> fecho){
    if(fecho.size() < 3) return fecho;
    
    // Encontrar o ponto inicial (menor x, depois menor y)
    int start = 0;
    for(int i = 1; i < fecho.size(); i++){
        if(fecho[i].first < fecho[start].first || 
           (abs(fecho[i].first - fecho[start].first) < 1e-9 && 
            fecho[i].second < fecho[start].second)){
            start = i;
        }
    }
    
    // Reordenar começando do ponto inicial
    vector<pair<double, double>> resultado;
    for(int i = 0; i < fecho.size(); i++){
        resultado.push_back(fecho[(start + i) % fecho.size()]);
    }
    
    return resultado;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        
        vector<pair<double, double>> pontos;
        vector<pair<double, double>> fecho;

        for(int j=0; j<p; j++){
            double x, y; 
            cin>>x;
            cin>>y;
            pontos.push_back(make_pair(x, y));
        }

        // ordenar por x
        sort(pontos.begin(), pontos.end());
        
        // funsão de divisão e conquista
        fecho = divideAndConquer(pontos);

        fecho = reordenarFecho(fecho);

        cout << "Caso " << i+1 << ":" << endl;
        cout << "Tamanho do colar: " << fecho.size() << endl;
        cout << "Pedras ancestrais: ";
        
        cout << fixed << setprecision(4);
        for(int i = 0; i < fecho.size(); i++){
            cout << "(" << fecho[i].first << "," << fecho[i].second << ")";
            if(i < fecho.size() - 1) cout << ",";
        }
        cout << endl;
        
        if((i+1) < n) cout << endl;
    }
    cout << "\n";
}

