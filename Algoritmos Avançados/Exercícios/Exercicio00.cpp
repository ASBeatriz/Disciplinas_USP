// REFAZER COM MAP (OLHAR O QUE A PROF DEU NA AULA)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector <string> codigos;
    vector <float> precos;
    int qtd_prod;
    float valorCompra = 0.0;

    cin >> qtd_prod;

    for(int i=0; i<qtd_prod; i++){
        string cod;
        float preco;

        cin >> cod >> preco;

        if (find(codigos.begin(), codigos.end(), cod) != codigos.end()) {
            cout << "Produto com código " << cod << " já cadastrado.\n";
        } else {
            codigos.push_back(cod);
            precos.push_back(preco);
        }
    }

    // leitura das compras
    while(1){
        int n;
        cin >> n;
        if(n == -1) break;
        for(int i=0; i<n; i++){
            string cod;
            cin >> cod;
            if(cod[0] != '#') continue;
            float peso;
            cin >> peso;

            auto it = find(codigos.begin(), codigos.end(), cod);
            if(it == codigos.end()){
                cout << "Produto com código " << cod << " não cadastrado.\n";
            }
            else{
                size_t index = it - codigos.begin();
                valorCompra += precos[index]*peso;
            }
        }
        printf("R$%.2f\n", valorCompra);
        valorCompra = 0;
    }

}
