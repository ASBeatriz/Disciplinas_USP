#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Utilização do merge sort pra contagem de inversões (representado pelo r nas funções)

int merge(vector<pair<int,int>> &pos, int ini, int m, int fim){
    int r=0;
    int n1 = m - ini + 1;
    int n2 = fim - m;

    // Cria vetores temporários
    vector<int> V1(n1), V2(n2);

    // Copia os dados do vetor original
    for (int i = 0; i < n1; i++)
        V1[i] = pos[ini + i].second;

    for (int j = 0; j < n2; j++)
        V2[j] = pos[m + 1 + j].second;

    
    // Realiza o merge
    int i=0, j=0, k=ini;
    while(true){
        if(i == n1 || j == n2) break;

        if(V2[j] <= V1[i]){
            r += n1-i;
            pos[k].second = V2[j]; 
            j++;
        }
        else{
            pos[k].second = V1[i]; 
            i++;
        }
        k++;
    }

    // Se algum vetor terminar primeiro, copia o restante do outro
    if(i < n1){
        for(;i<n1; i++){
            pos[k].second = V1[i];
            k++; 
        }
    }
    else if(j < n2){
        for(;j<n2; j++){
            pos[k].second = V2[j];
            k++; 
        }
    }

    return r;
}

int mergeSort(vector<pair<int,int>> &pos, int ini, int fim){
    int r = 0;
    
    // casos base
    if(ini == fim) return 0;
    if(fim == ini+1){
        if(pos[fim].second <= pos[ini].second){
            int t = pos[ini].second;
            pos[ini].second = pos[fim].second;
            pos[fim].second = t;
            r++;
        }

        return r;
    } 

    int m = (ini+fim)/2;

    r += mergeSort(pos, ini, m);
    r += mergeSort(pos, m+1, fim);

    r += merge(pos, ini, m, fim);

    return r;
}

int main(){
    // Leitura de entradas
    vector<pair<int,int>> ult;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        vector<pair<int,int>> positions; 
        int jog;
        
        cin >> jog;
        for(int j=0; j<jog; j++){
            int Si,Sf;
            cin >> Si >> Sf;
            positions.push_back({Si,Sf});
        }
        // Ordena o vetor em ordem crescente da primeira posição
        sort(positions.begin(), positions.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        });

        // Divisão e conquista
        ult.push_back({i, mergeSort(positions, 0, jog-1)});
    }

    sort(ult.begin(), ult.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    });

    for(auto p:ult) cout << p.first << " " << p.second << endl;
}