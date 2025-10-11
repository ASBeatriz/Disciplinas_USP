#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <sstream>
using namespace std;

struct quest {
    int id;
    int endTime;
    int dur;
    vector<int> deps;
};

struct hero {
    string name;
    float vel;
    float freeTime;
    vector<int> quests;
};

void dfs(int q, vector<quest> &quests, bool *visited, list<int> &quests_ord){
    for(auto dep : quests[q].deps){
        if(visited[dep-1]) continue;

        dfs(dep, quests, visited, quests_ord);
    }
    visited[q] = true;
    quests_ord.push_back(q);
}

int main(){
    map<string, float> VEL;
    VEL["Aprendiz"] = 0.75;
    VEL["Aventureiro"] = 1;
    VEL["Cavaleiro"] = 1.2;
    VEL["Mestre"] = 1.5;
    VEL["Lenda"] = 2;
    // continuar

    int x;
    cin >> x;
    
    for(int i=0; i<x; i++){
        int h, q;
        cin >> h >> q;

        list<int> quests_ord;
        vector<quest> quests(q);
        vector<hero> heros;

        for(int j=0; j<h; j++){
            string nome, nivel;
            cin >> nome >> nivel;
            hero h = {.name = nome, .vel = VEL[nivel], .freeTime = 0.0};
            heros.push_back(h);
        }

        for(int j=0; j<q; j++){
            int id, t;
            cin >> id >> t;
            quests[id-1].dur = t;

            string line;
            getline(cin, line);
            istringstream is (line);
            int n;
            while( is >> n ) {
                // cout << n << "\n";
                if(n != 0) quests[id-1].deps.push_back(n);
            }
        }
        
        // Ord Topológica
        bool visited[q];
        for(int i=0; i<q; i++) visited[i] = false;
        
        for(int i=0; i<q; i++){
            if(visited[i]) continue;
            dfs(i, quests, visited, quests_ord);
        }

        // debug
        for(auto quest: quests_ord) cout << quest << " ";
        cout << endl;
        
        // Distribuição de quests
        for(int i=0; i<q; i++){
            // verificar as dependencias
            float minStartTime = 0.0;
            for(auto dep : quests[i].deps){
                if(minStartTime < quests[dep-1].endTime) minStartTime = quests[dep-1].endTime;
            }
            
            // calcula tempo de término de cada herói para aquela tarefa
            set<pair<float, int>> herosEndTimes;
            for(int j=0; j<h; j++){
                float endTime;
                hero h = heros[j];
                if(h.freeTime > minStartTime)
                    endTime = h.freeTime+(quests[i].dur / h.vel);
                else 
                    endTime = minStartTime+(quests[i].dur / h.vel);

                herosEndTimes.insert({endTime, j});
            }

            auto it = herosEndTimes.begin();
            quests[i].endTime = it->first;
            heros[it->second].freeTime = it->first;
            heros[it->second].quests.push_back(i);

            cout << "heroi: " << heros[it->second].name << ", tempo: " << it->first << endl;
        }

        // Saída
        float duration = 0.0;
        for(auto h : heros){
            cout << h.name << " = " << "{";
            for(auto q = h.quests.begin(); q != h.quests.end(); q++){
                cout << *q + 1;
                if(next(q) != h.quests.end()) cout << ",";
            }
            cout << "}\n";

            if(h.freeTime > duration) duration = h.freeTime;
        }
        printf("Tempo mínimo: %.2f\n", duration);
        if(i+1 < x) cout << endl;
    }
}

