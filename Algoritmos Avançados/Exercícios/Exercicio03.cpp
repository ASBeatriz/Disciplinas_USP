#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// Struct para representar um horário
struct Time{
    int h;
    int min;

    // Funções que define a comparação entre horários
    bool operator<(const Time& time) const{
        if(time.h != h) return h < time.h;
        else return min < time.min;
    }
    bool operator!=(const Time& time) const{
        return (h != time.h || min != time.min);
    }
};

// Struct para representar uma solicitação de aluguel
struct Request {
    int client;
    int model;
    Time startTime;
    Time endTime;
};

// Define a comparação entre solicitações por meio do horário de devolução
struct endTimeOrder{
    bool operator()(const Request& r1, const Request& r2) const{
        if(r1.endTime != r2.endTime)
            return r1.endTime < r2.endTime;
        else
            return r1.startTime < r2.startTime;
    }
};

int main(){
    
    int x;
    cin >> x;
    // Quantidade de casos de teste
    for(int i=0; i<x; i++){
        map<int, set<Request, endTimeOrder>> modelsRequests;
        map<int, vector<int>> modelsOccupation;
        int n, s;

        // Quantidade de modelos
        cin >> n;

        // Quantidade de solicitações
        cin >> s;
        for(int k=0; k<s; k++){
            int id, model;
            char _startH[6], _startMin[6], _endH[6], _endMin[6];

            cin >> id;
            getchar();
            fgets(_startH, 3, stdin); getchar();
            fgets(_startMin, 3, stdin); getchar();
            fgets(_endH, 3, stdin); getchar();
            fgets(_endMin, 3, stdin);
            cin >> model;

            int startH = atoi(_startH), startMin = atoi(_startMin), endH = atoi(_endH), endMin = atoi(_endMin);

            Request r;
            r.client = id;
            r.startTime.h = startH;
            r.startTime.min = startMin;
            r.client = id;
            r.endTime.h = endH;
            r.endTime.min = endMin;
            modelsRequests[model].insert(r);
        }

        // Calculando o Resultado
        for(auto m:modelsRequests){

            int qtd = 0;
            Time last = {.h=0, .min=0};
            for(auto c:m.second){
                if(last < c.startTime || !(last != c.startTime)){
                    qtd++;
                    modelsOccupation[m.first].push_back(c.client);
                    last = c.endTime;
                }
                // cout << endl;
            }
        }

        // Resultado
        for(int m=1; m<=n; m++){
            int size = modelsOccupation[m].size();
            cout << m << ": " << size;
            if (size){
                cout << " = ";
                for(int idxClient = 0; idxClient < size; idxClient++){
                    int c = modelsOccupation[m].at(idxClient);
                    cout << c;
                    if(idxClient != size - 1) cout << ", ";
                }
            }
            if(m != n) cout << " | ";   
        }
        cout << endl;
    }

}