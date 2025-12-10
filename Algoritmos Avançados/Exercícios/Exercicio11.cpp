#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int x;
    cin >> x;
    for(int i=0; i<x; i++){
        int n,m;
        cin >> n >> m;

        // listas de adjacência
        vector<int> v[n];

        // inicializa os componentes de cada vertice
        int comp[n];
        for(int j=0; j<n; j++) comp[j] = -1;

        // leitura das arestas
        for(int j=0; j<m; j++){
            int a,b;
            cin >> a >> b;

            // preencher listas de adjacência
            v[a-1].push_back(b-1);
            v[b-1].push_back(a-1);
        }

        
        int nComp = 0;
        for(int j=0; j<n; j++){
            if(comp[j] != -1) continue;

            nComp++;
            queue<int> q;
            q.push(j);

            // Aplica BFS para achar os componentes
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                comp[curr] = nComp;

                for(int adj:v[curr]){
                    if(comp[adj] != -1) continue;

                    comp[adj] = nComp;
                    q.push(adj);
                }
            }
        }

        cout << nComp << endl;

    }
}