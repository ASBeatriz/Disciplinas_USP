#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <float.h>
using namespace std;

struct sistema{
    float x;
    float y;
    string nome;
    int indice; 
};

struct tunel{
    int sis1;
    int sis2;
    float dist;
};

struct ParPontos {
    int i, j;
    float dist;
};

// Estrutura Union-Find para implementar Kruskal
struct UnionFind {
    vector<int> pai, rank;
    UnionFind(int n) {
        pai.resize(n);
        rank.resize(n, 0);
        // seta o representante de cada subconjunto
        for (int i = 0; i < n; i++) pai[i] = i;
    }

    int find(int x) {
        if (pai[x] == x) return x;
        return pai[x] = find(pai[x]); 
    }

    bool unite(int a, int b) {
        int pai_a = find(a);
        int pai_b = find(b);
        if (pai_a == pai_b) return false;
        // se os pais (representante) forem diferentes, faz o pai com o maior rank ser pai do outro
        if (rank[pai_a] < rank[pai_b]) swap(pai_a, pai_b);
        pai[pai_b] = pai_a;
        if (rank[pai_a] == rank[pai_b]) rank[pai_a]++;  // faz o desempate no rank
        return true;
    }
};

// Calcula distância euclidiana entre dois pontos
float distancia(const sistema& a, const sistema& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Força bruta para casos pequenos
ParPontos bruteForce(vector<sistema>& pontos, int inicio, int fim) {
    ParPontos minPar;
    minPar.dist = FLT_MAX;
    
    for (int i = inicio; i < fim; i++) {
        for (int j = i + 1; j < fim; j++) {
            float d = distancia(pontos[i], pontos[j]);
            cout << "[bruteforce] ANALISANDO " << pontos[i].nome << " " << pontos[j].nome << " dist: " << d;
            cout << " atual: " << minPar.dist << endl;


            if (d <= minPar.dist) {
                if(d == minPar.dist){
                    // cout << "\n IGUAL: " << d << endl;
                    if(pontos[i].nome > pontos[minPar.i].nome){
                        cout << "NAO TROCAR\n";
                        continue;
                    }
                }

                minPar.dist = d;
                minPar.i = pontos[i].indice;
                minPar.j = pontos[j].indice;
            }
        }
    }
    return minPar;
}

// Verifica se alguma par de pontos na faixa central pode ser o minPair
ParPontos verificaFaixa(vector<sistema>& faixa, float d, ParPontos& minPar, vector<sistema>& pontos) {
    // Ordena a faixa por coordenada y
    sort(faixa.begin(), faixa.end(), [](const sistema& a, const sistema& b) {
        return a.y < b.y;
    });
    
    // Verifica apenas pontos próximos em y
    for (size_t i = 0; i < faixa.size(); i++) {
        for (size_t j = i + 1; j < faixa.size() && (faixa[j].y - faixa[i].y) < d; j++) {
            float dist = distancia(faixa[i], faixa[j]);
            cout << "             ANALISANDO " << faixa[i].nome << " " << faixa[j].nome << " dist: " << dist;
            cout << " atual: " << minPar.dist << endl;
            if (dist <= minPar.dist) {
                if(dist == minPar.dist){
                    cout << "\n IGUAL: \n";
                    // cout << faixa[i].nome << " " << pontos[minPar.i].nome << endl;
                    if(faixa[i].nome > pontos[minPar.i].nome){
                        cout << "NAO TROCAR\n";
                        continue;
                    }
                }
                // else cout << "\n DIFERENTE: " << minPar.dist << " " << dist << endl;

                minPar.dist = dist;
                minPar.i = faixa[i].indice;
                minPar.j = faixa[j].indice;
            }
        }
    }
    return minPar;
}

// Algoritmo de divisão e conquista
ParPontos closestPair(vector<sistema>& pontos, int inicio, int fim) {
    // Caso base: poucos pontos, usa força bruta
    if (fim - inicio <= 3) {
        return bruteForce(pontos, inicio, fim);
    }
    
    // Divisão
    int meio = inicio + (fim - inicio) / 2;
    sistema pontoMeio = pontos[meio];
    
    // Conquista
    ParPontos parEsq = closestPair(pontos, inicio, meio);
    ParPontos parDir = closestPair(pontos, meio, fim);
    
    // Encontra o menor entre as duas metades
    ParPontos minPar;
    if(parEsq.dist < parDir.dist) minPar = parEsq;
    else if (parEsq.dist < parDir.dist) minPar = parEsq;
    else{
        (pontos[parEsq.i].nome < pontos[parDir.i].nome) ? parEsq : parDir;
    }
    cout << "ESCOLHIDO: " << pontos[minPar.i].nome << endl;
    
    // Combinação
    vector<sistema> faixa;
    for (int i = inicio; i < fim; i++) {
        // Verifica pontos na faixa central que pode ser o par mais próximo
        if (abs(pontos[i].x - pontoMeio.x) < minPar.dist) {
            faixa.push_back(pontos[i]);
        }
    }
    
    return verificaFaixa(faixa, minPar.dist, minPar, pontos);
}


int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int qtde, qtdeImp, tensaoMax;
        vector <sistema> sistemasImp;
        vector <sistema> sistemas;
        vector <tunel> tuneis;

        cin >> qtde >> qtdeImp >> tensaoMax;

        for(int j=0; j<qtde; j++){
            sistema s;
            cin >> s.nome >> s.x >> s.y;
            s.indice = j; 

            if(j < qtdeImp)
                sistemasImp.push_back(s);

            sistemas.push_back(s);
        }

        // --------- Parte 1 ---------

        // Cria todas as arestas possíveis entre os sistemas importantes
        for (int i = 0; i < qtdeImp; i++) {
            for (int j = i + 1; j < qtdeImp; j++) {
                float d = distancia(sistemasImp[i], sistemasImp[j]);
                if (d <= tensaoMax) {
                    tuneis.push_back({i, j, d});
                }
            }
        }

        // Ordena os tuneis por tensão crescente
        sort(tuneis.begin(), tuneis.end(), [](const tunel& a, const tunel& b) {
            return a.dist < b.dist;
        });

        // Kruskal
        UnionFind dsu(qtdeImp);
        vector<tunel> resultado;
        float total = 0;

        for (auto& t : tuneis) {
            // verifica em cada aresta se é possível fazer a união dos subconjuntos
            if (dsu.unite(t.sis1, t.sis2)) {
                resultado.push_back(t);
                total += t.dist;
                if ((int)(resultado.size()) == qtdeImp - 1) break;
            }
        }

        // Imprime Resultado
        for (auto& e : resultado) {
            cout << sistemasImp[e.sis1].nome << ", " << sistemasImp[e.sis2].nome;
            printf(", %.2f\n", e.dist);
        }

        // --------- Parte 2 ---------

        // Cria cópia dos sistemas e ordena por x
        vector<sistema> pontos = sistemas;
        sort(pontos.begin(), pontos.end(), [](const sistema& a, const sistema& b) {
            return a.x < b.x;
        });
    
        ParPontos parMaisProximo = closestPair(pontos, 0, pontos.size());

        int s1, s2;
        if(parMaisProximo.i > parMaisProximo.j){
            s1 = parMaisProximo.j;
            s2 = parMaisProximo.i;
        }
        else{
            s2 = parMaisProximo.j;
            s1 = parMaisProximo.i;
        }
        
        cout << "Ponto de Ressonância: " << sistemas[s1].nome 
             << ", " << sistemas[s2].nome;
        printf(", %.2f\n", parMaisProximo.dist);

        cout << endl;
    }
}