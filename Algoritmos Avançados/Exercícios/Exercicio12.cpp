#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct aresta{
    int a, b;
    int custo;
};

int find(int a, int *conj){
    if(a == conj[a]) return a;
    conj[a] = find(conj[a], conj);
    return conj[a];
}

int main(){
    int x;
    cin >> x;

    for(int i=0; i<x; i++){
        int n, m;
        cin >> n >> m;
    
        vector<aresta> arestas;
        set<int> custos;    // para controle da repetição de custos
        bool caminhoCorreto = true;
        
        // leitura das arestas
        for(int j=0; j<m; j++){
            int a, b, c;
            cin >> a >> b >> c;
            if(custos.find(c) != custos.end()){
                caminhoCorreto = false;
                // break;
            }
            
            custos.insert(c);
            aresta ares = {.a=a-1, .b=b-1, .custo = c};
            arestas.push_back(ares);
        }

        // caso tenha arestas de custos iguais
        if(!caminhoCorreto){
            cout << "Esse nao e o caminho correto para a Cidade Perdida de Z.\n\n";
            continue;
        }

        // Aplicar Kruskal

        // inicializa os conjuntos de cada vértice
        int conj[n];
        int rank[n];
        for(int i=0; i<n; i++){
            conj[i] = i;
            rank[i] = 1;
        }
        // ordenar as arestas por custo
        sort(arestas.begin(), arestas.end(), [](const aresta& a, const aresta& b){
            return a.custo < b.custo;
        });
        
        vector<aresta> arvore;
        for(auto a:arestas){
            int conjA = find(a.a, conj);
            int conjB = find(a.b, conj);
            if(conjA == conjB) continue;


            if(rank[conjA] >= rank[conjB]){
                rank[conjA]++;
                conj[conjB] = conjA;
            }
            else{
                rank[conjB]++;
                conj[conjA] = conjB;
            }

            arvore.push_back(a);
        }

        // Saída
        if((int)arvore.size() != n-1){
            cout << "O vale nao pode ser completamente atravessado.\n\n";
            continue;
        }

        int custoMin = 0;
        for(auto a:arvore) custoMin += a.custo;

        cout << "Custo minimo: " << custoMin << endl;
        cout << "Pontes reconstruidas:\n";

        for(auto a:arvore){
            if(a.a < a.b) cout << a.a+1 << " - " << a.b+1 << endl;
            else cout << a.b+1 << " - " << a.a+1 << endl;
        }
        cout << endl;
    }
}