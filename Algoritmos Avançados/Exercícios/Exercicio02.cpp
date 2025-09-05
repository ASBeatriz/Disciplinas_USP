#include <iostream>
#include <set>
#include <string>
using namespace std;

struct date{
    int dia;
    int mes;
    int ano;

    bool operator<(const date& data) const{
        if(ano != data.ano) return ano < data.ano;
        else if(mes != data.mes) return mes < data.mes;
        else return dia < data.dia;
    }
};

struct workDay{
    date data;
    float ganho;
};

struct dateOrder{
    bool operator()(const workDay &d1, const workDay &d2) const{
        return d1.data < d2.data;
    }
};

struct moneyOrder{
    bool operator()(const workDay &d1, const workDay &d2) const{
        return d1.ganho > d2.ganho;
    }
};


int main(){
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        set<workDay, moneyOrder> workDays;
        float ganhoTotal = 0;
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            char sdia[3], smes[3], sano[5];
            int dia, mes, ano;
            float ganho;

            // Leitura da data e do valor
            getchar();
            fgets(sdia, 3, stdin); getchar();
            fgets(smes, 3, stdin); getchar();
            fgets(sano, 5, stdin);
            cin >> ganho;
            dia = atoi(sdia);
            mes = atoi(smes);
            ano = atoi(sano);

            // cout << dia << " " << mes << " " << ano << endl; //debug
            
            // Adiciona o dia de trabalho em um set
            workDay wd;
            wd.data.ano = ano;
            wd.data.mes = mes;
            wd.data.dia = dia;
            wd.ganho = ganho;
            workDays.insert(wd);
            ganhoTotal += ganho;
        }

        // Algoritmo guloso - monta o subset com os maiores ganhos
        set<workDay, dateOrder> subSet;
        float subSetSum = 0;
        for(auto it:workDays){
            subSetSum += it.ganho;
            subSet.insert(it);
            if(subSetSum > ganhoTotal/2) break;
        }

        // Imprime a saída
        int size = subSet.size();

        cout << size << (size > 1 ? " dias (" : " dia (");

        for(auto it = subSet.begin(); it != subSet.end(); it++){
            printf("%02d/%02d/%04d", it->data.dia, it->data.mes, it->data.ano);
            if(next(it) != subSet.end()) cout << ", ";
            else cout << ")";
        }
        float percentage = ((float)size/workDays.size())*100;
        printf(" | soma=%.2f | %.2f%% dos dias totais\n", subSetSum, percentage); 
    }
}