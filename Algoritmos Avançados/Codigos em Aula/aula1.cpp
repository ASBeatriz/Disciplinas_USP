// Não foi o codigo gerado em aula, mas é uma revisão do que ela falou/deu
/*
template
list
vector
stack
map
pair
sort
struct, operator (overload)
functor
lambda
*/

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <utility>
using namespace std;

// Templates
    template <class C> void makeSound(C myClass){
        // Nesse caso, C é uma classe genérica que possui um método sound()
        myClass.sound();
    }

    template <typename T> T maior(T a, T b){
        // nesse caso, T é um tipo genérico que pode ser comparado
        return (a > b ? a : b);
    }

// Classes exemplos
    class classe1
    {
        public:
            void sound(){
                cout << "aaa\n";
            };
    };

    class classe2
    {
        public:
            void sound(){
                cout << "uuu\n";
            };
    };


int main(){
    // Testando Template
        cout << maior(2, 3) << endl;
        cout << maior(2.7, 2.3) << endl;

        classe1 c1;
        classe2 c2;
        makeSound(c1);
        makeSound(c2);

    // List
    // É uma lista duplamente encadeada. Rápida para inserção/remoção de elementos (no meio ou não). Lenta para acesso aleatório (por índice).
        list<int> lista = {0, 0};
        
        // inserir em uma posição
        auto it = lista.begin();
        advance(it, 1);
        lista.insert(it, 1);

        // inserir na frente ou atrás
        lista.push_front(2);
        lista.push_back(3);

        for(auto it : lista){
            cout << it << " ";
        }
        cout << endl;

    // Vector
    // Array (elementos de posição contígua na memória) de tamanho variável. Rápido para acesso aleatório (por índice). Lento para inserção/remoção de elementos no meio.
        vector<char> vetor = {'a', 'b'};

        // inserindo em uma posição
        vetor.insert(vetor.begin() + 1, 'c');   // esse +1 só é possível para o vector, não para o list
        // inserindo no fim
        vetor.push_back('d');

        for(int i=0; i<vetor.size(); i++){
            cout << vetor.at(i) << " ";
            // cout << vetor[i] << " ";        // alternativa: acessar valores diretamente com []
        }
        
        // também funciona:
        // for(auto it : vetor){
        //     cout << it << " ";
        // }

        cout << endl;
    
    
    // Map
    // É um conteiner que guarda pares no formato chave/valor, automaticamente ordenado pelos valores das chaves em ordem crescente. Cada chave é única e fixa (não pode ser alterada).
        map<int, string> m;

        // formas de adicionar pares chave-valor
        m.insert({1, "beto"});
        m[5] = "carlos";        // utilizando [] com o valor da chave

        // acessando elementos pela chave
        cout << m[1] << endl;
        cout << "AA " << m[3] << endl;
        cout << m.at(5) << endl;

        for(auto it : m){
            cout << it.first << " " << it.second << ", ";
        }

        cout << endl;

    // Pair
    // É um conteiner simples que guarda dois valores juntos. Um par de valores.
        pair <string, int> p;
        
        // formas de definir um par
        p = {"banana", 20};
        p = make_pair("banana", 20);

        // acessando elementos
        cout << p.first << " " << p.second << endl;
        
        // modificando elementos
        p.first = "maçã"; p.second = 25;
        cout << p.first << " " << p.second << endl;

    // ADICIONAR RESTANTE
    

    // Set
    
    cout << endl;
}   
