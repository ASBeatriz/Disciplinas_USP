#include <iostream>
#include <vector>

using namespace std;

bool dfs(int n, vector<vector<int>> &graph, vector<int> &tipo){
    if((int)graph[n].size() == 0){
        tipo[n] = 0;
        return false;
    }

    for(auto adj:graph[n]){
        // cout << "visitando " << adj << endl;
        
        if(dfs(adj, graph, tipo)){
            if(tipo[n] == -1){
                // cout << "eh perdedor\n";
                tipo[n] = 0;
            }
        }
        else{
            // cout << "eh vencedor\n";
            tipo[n] = 1;
        }
    }

    return tipo[n];
}

int main(){
    int x;
    cin >> x;

    for(int i=0; i<x; i++){
        int n, m, s;
        cin >> n >> m >> s;
        vector<vector<int>> graph(n);
        vector<int> tipo(n, -1); // 0 = perdedor, 1 = vencedor, -1 = ainda não visitado

        for(int j=0; j<m; j++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
        }

        dfs(s, graph, tipo);

        bool isAsh = false;
        for(auto adj:graph[s]){
            if(tipo[adj] == 0){
                isAsh = true;
                break;     
            }
        }

        if(isAsh) cout << "Ash\n";
        else cout << "Noir\n";
    }
}