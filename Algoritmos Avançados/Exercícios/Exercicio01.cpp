#include <iostream>
using namespace std;

struct no {
    int id;
    bool diabetes;
    no *pai;
    no *mae;

    no(): diabetes(false), pai(NULL), mae(NULL) {};
    ~no(){
        delete pai;
        delete mae;
    }
};

class arvore {
private:
    no *busca(int id, no* atual){
        if(atual->id == id) return atual;

        no* resp = NULL;
        if(atual->mae != NULL) resp = busca(id, atual->mae);
        if(resp == NULL && atual->pai != NULL) resp = busca(id, atual->pai);

        return resp;
    }

public:
    no *raiz;
    arvore(){
        raiz = NULL;
    }
    ~arvore(){
        delete raiz;
    }

    void inserir(int id, bool diabetes, int pai, int mae){
        no *noMae = NULL;
        no *noPai = NULL;
        if(pai != -1){
            noPai = new no();
            noPai->id = pai;
        }
        if(mae != -1){
            noMae = new no();
            noMae->id = mae;
        }

        if(raiz == NULL){
            raiz = new no();
            raiz->id = id;
            raiz->diabetes = diabetes;
            raiz->pai = noPai;
            raiz->mae = noMae;
        }
        else{
            no *filho = busca(id, this->raiz);
            if (filho == NULL) return;
            filho->diabetes = diabetes;
            filho->mae = noMae;
            filho->pai = noPai;
        }
    }

    int calcula_herdeiros(no *inicio){
        if(inicio == NULL) return 0;

        int n=0;

        if(inicio->diabetes){
            if(inicio->mae != NULL  && inicio->mae->diabetes) n++;
            else if(inicio->pai != NULL  && inicio->pai->diabetes) n++;
        }

        n += calcula_herdeiros(inicio->mae); 
        n += calcula_herdeiros(inicio->pai);

        return n;
    }
};

int main(){
    arvore arv;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int qtde;
        cin >> qtde;

        for(int i=0; i<qtde; i++){

            int id, pai, mae;
            string diabetes;
            cin >> id >> diabetes >> pai >> mae;

            arv.inserir(id, (diabetes == "sim"), pai, mae);
        }

        int n = arv.calcula_herdeiros(arv.raiz);
        cout << n << endl;
    }

    return 0;
}
