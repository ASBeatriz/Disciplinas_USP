#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool find_path(int x, vector<vector<int>> &cap, vector<vector<int>> &occup, int n, vector<int> &added_v, vector<pair<int,int>> &added_pair){
    // caso base;
    if (x == n-1) return true;


    for(int i=0; i<n; i++){
        if(find(added_v.begin(), added_v.end(), i) != added_v.end()) continue;
        if(cap[x][i] == -1) continue;
        if(cap[x][i] - occup[x][i] <= 0) continue;

        added_v.push_back(x);
        added_v.push_back(i);

        if(find_path(i, cap, occup, n, added_v, added_pair)){
            added_pair.push_back({x,i});
            return true;
        }

    }

    return false;
}

int main(){
    int n,m;
    cin >> n >> m;

    // inicializa matrizes de ocupação e capacidade
    vector<vector<int>> cap(n, vector<int>(n, -1));
    vector<vector<int>> occup(n, vector<int>(n, 0));

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        cap[a-1][b-1] = c;
        cap[b-1][a-1] = 0;
    }

    // DEBUG
    // cout << "cap:\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout << cap[i][j] << " ";

    //     cout << endl;
    // }
 
    // cout << "occup:\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout << occup[i][j] << " ";

    //     cout << endl;
    // }


    // Algoritmo do fluxo máximo
    // s = 1, t = n
    
    int maxFluxo = 0;
    while(true){   
        vector<int> added_v;
        vector<pair<int,int>> added_pair;

        find_path(0, cap, occup, n, added_v, added_pair);

        if((int)added_pair.size() == 0) break;

        int menorDiff = INT_MAX;
        for(auto p:added_pair){
            int diff = cap[p.first][p.second] - occup[p.first][p.second];
            if(diff < menorDiff)
                menorDiff = diff;
        }

        // preencher as acupações (valor negativo na aresta inversa)
        for(auto p:added_pair){
            occup[p.first][p.second] += menorDiff;
            occup[p.second][p.first] -= menorDiff;
        }

        maxFluxo += menorDiff;
    }

    cout << maxFluxo << endl;

}
