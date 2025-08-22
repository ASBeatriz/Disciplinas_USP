#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

// função auxiliar
double rad(double x){
    return x*(M_PI/180);
}

int main(){
    int n;  
    double x,y;
    priority_queue <
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>> // ordem crescente
    > fila;

    cin >> n;
    cin >> x >> y;

    for(int i=0; i<n; i++){
        string usuario;
        cin >> usuario;

        double x_, y_;
        cin >> x_ >> y_;

        // Calcula a distância
        double R = 6371.0;
        double dist = 2*R*asin(sqrt(pow(sin((rad(x_) - rad(x))/2) , 2) + cos(rad(x_))*cos(rad(x))*pow(sin((rad(y_) - rad(y))/2), 2)));  // formulazinha básica :p

        // Adiciona na fila
        fila.push({dist, usuario});

        // Resgata melhor palpite
        double melhorPalpite = fila.top().first;
        printf("> [AVISO] MELHOR PALPITE: %.3fkm\n", melhorPalpite);
    }

    int i=1;
    cout << "\nRANKING\n-------\n";
    while(!fila.empty()){
        printf("%2d. %-20s : %6.3f km", i++, fila.top().second.c_str(), fila.top().first); 

        if(fila.top().first < 0.050) cout << " [FANTASTICO]";
        cout << endl;
        fila.pop();
    }

}