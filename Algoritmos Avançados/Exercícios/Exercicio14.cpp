#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int tam = (int) s.length();
        char c = s[tam-1];
        int lastPos = -1;

        // percorre a string até achar um caractere igual ao último
        for(int j=0; j<tam-1; j++){
            if(s[j] == c){
                bool ehIgual = true;
                // quando achar, verifica se a sequência do inicio também se repete no fim
                for(int k=0; k<=j; k++){
                    if(s[j-k] != s[tam-1-k]){
                        ehIgual = false;
                        break;
                    }
                }
                if(!ehIgual) continue;

                // atualiza com a maior (última) sequência encontrada
                lastPos = j;
            }
        }

        if(lastPos != -1){
            string res = s.substr(0,lastPos+1);
            cout << res;
        }
        cout << endl;
    }
}