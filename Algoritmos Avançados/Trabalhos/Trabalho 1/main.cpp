#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct node {
    bool fimDePalavra;
    map <char, node*> filhos;

    node() : fimDePalavra(false) {};

    // destructor (liberação de memória)
    ~node(){
        for(auto& filho : filhos) delete filho.second;
    }
};

class Trie{
    public:
        node *raiz;

        Trie(){
            this->raiz = new node();
        }
        ~Trie(){
            delete raiz;
        }

        void insert(string palavra){
            node *noAtual = this->raiz;

            // loop para inserir os caracteres de uma palavra na Trie
            for(char c : palavra){
                // Se não achar o caractere, cria um novo nó com ele
                if(noAtual->filhos.find(c) == noAtual->filhos.end()){
                    noAtual->filhos[c] = new node();
                }
                noAtual = noAtual->filhos[c];
            }

            // Marca o último caractere como fim de palavra
            noAtual->fimDePalavra = true;
        }

        // Função para procurar uma substring na Trie. 
        // Retorna dois booleanos: o primeiro indicando se a substring existe e o segundo indicando se atingiu o fim de uma palavra.
        pair <bool, bool> search(string substring){

            node *noAtual = this->raiz;
            bool fim;
            for(auto c : substring){
                fim = false;

                if(noAtual->filhos.find(c) == noAtual->filhos.end())    
                    return {false, false};

                noAtual = noAtual->filhos[c];
                if(noAtual->fimDePalavra)
                    fim = true;
            }

            return {true, fim};
        }
};

// Função para realizar a busca de palavras dada uma posição inicial e uma direção específica
void buscaPalavras(Trie &trie, vector<vector<char>> grid, set<string> &encontradas, int lmax, int cmax, int l, int c, string substring, pair<int, int> direcao){
    // Tratamento dos limites da matriz
    if(l >= lmax || c >= cmax || l < 0 || c < 0) return;
    
    // Procura a próxima substring na Trie
    substring += grid[l][c];
    pair <bool, bool> resp = trie.search(substring);

    // Caso base (substring não existe)
    if(!resp.first) return;

    // Se alcançar o fim de palavra, adiciona-a no set
    if(resp.second) encontradas.insert(substring);

    // recursão para prosseguir a busca
    buscaPalavras(trie, grid, encontradas, lmax, cmax, l+direcao.first, c+direcao.second, substring, direcao); 
}


int main(){

    Trie trie;

    int l, c;
    cin >> l >> c;
    vector<vector <char>> grid(l, vector<char>(c));

    // Leitura do caça palavras
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            cin >> grid[i][j];
        }
    }

    int n;
    cin >> n;

    // Leitura das palavras do dicionário
    for(int i=0; i<n; i++){
        string palavra;
        cin >> palavra;
        trie.insert(palavra);
    }

    set<string> encontradas;

    // Percorre cada elemento da matriz (caça-palavras)
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){

            // Para cada letra da matriz, faz a busca em todas as direções possíveis
            for(int dirL=-1; dirL <= 1; dirL++){
                for(int dirC=-1; dirC <= 1; dirC++){
                    if(dirC == 0 && dirL == 0) continue;

                    // dirL e dirC ditam o incremento da linha e coluna, respectivamente, para seguir em uma das oito direções
                    buscaPalavras(trie, grid, encontradas, l, c, i, j, "", {dirL, dirC});
                }
            }
        }
    }

    cout << encontradas.size() << endl;
    for(auto p:encontradas) cout <<  p << endl;

    return 0;
}
