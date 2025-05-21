public class ArvAVL extends ArvBin {

    public ArvAVL(int len){
        super(len);
    }

    @Override
    public Boolean insert(String nome){
        // faz a inserção normalmente   
        if(!super.insert(nome)) return false;

        int pos = find(nome);
        verifica_desbal(pos);

        // System.out.println("apos um insert em avl:");
        // toString();
        return true;
    }

    private void verifica_desbal(int pos){
        int i = pos;

        while(true){
            int lh = height(i*2+1);   // altura da árvore esquerda
            int rh = height(i*2+2);   // altura da árvore direita
            int fator = lh - rh;
            if(fator >= 2){
                // System.out.println("OPA");
                // rotação direita em i

                // "empurra" a subárvore direita um nível para baixo à direita
                // print();
                empurrarParaDireitaSemPerder(i*2+2);
                // print();

                // atribui seu valor ao filho direito
                arvore[2*i+2] = arvore[i];

                // move o filho direito do filho esquerdo para o filho direito do filho esquerdo
                moverSubarvore(filho_dir(filho_esq(i)), filho_esq(filho_dir(i)));

                // atribui valor do filho esquerdo ao nó
                arvore[i] = arvore[filho_esq(i)];

                // move o filho esquerdo do filho esquerdo para cima
                moverSubarvore(filho_esq(filho_esq(i)), filho_esq(i));
            }   
            else if(fator <= -2){
                // rotação esquerda em i

                // "empurra" a subárvore esquerda um nível para baixo à esquerda
                // print();
                empurrarParaEsquerdaSemPerder(i*2+2);
                // print();

                // atribui seu valor ao filho esquerdo
                arvore[2*i+1] = arvore[i];

                // move o filho esquerdo do filho direito para o filho direito do filho esquerdo
                moverSubarvore(filho_esq(filho_dir(i)), filho_dir(filho_esq(i)));

                // atribui valor do filho esquerdo ao nó
                arvore[i] = arvore[filho_dir(i)];

                // move o filho esquerdo do filho esquerdo para cima
                moverSubarvore(filho_dir(filho_dir(i)), filho_dir(i));
            }
            
            if(i == 0) break;
            else i = antecessor(i);
        }
    }

    private void empurrarParaDireitaSemPerder(int raiz) {
        if (raiz >= arvore.length || arvore[raiz] == null) return;

        int destino = 2 * raiz + 2;
        empurrarTudoParaFrente(raiz, destino); // abre caminho à direita

        // moverSubarvore(raiz, destino);   // move a subárvore da raiz para a nova posição
        arvore[raiz] = null;
    }

    private void empurrarParaEsquerdaSemPerder(int raiz) {
        if (raiz >= arvore.length || arvore[raiz] == null) return;

        int destino = 2 * raiz + 1;
        empurrarTudoParaFrente(raiz, destino); // abre caminho à direita

        // moverSubarvore(raiz, destino);   // move a subárvore da raiz para a nova posição
        arvore[raiz] = null;
    }

    public void empurrarTudoParaFrente(int origem, int destino) {
        if (origem >= len || arvore[origem] == null)
            return;


        // Primeiro, empurra os filhos
        empurrarTudoParaFrente(filho_esq(origem), filho_esq(destino));
        empurrarTudoParaFrente(filho_dir(origem), filho_dir(destino));

        // Agora que os filhos já foram empurrados, empurra o nó atual
        // System.out.println("origem: " + origem + "(" + arvore[origem] + ")" + " destino: " + destino);
        arvore[destino] = arvore[origem];
        arvore[origem] = null;
    }


}
