import java.util.LinkedList;
import java.util.Queue;

public class ArvBin{
    protected String[] arvore;
    protected int num_elem;
    protected int len;
    private int last_pos;

    public ArvBin(int len){
        arvore = new String[len];
        for(int i=0; i<100; i++){
            arvore[i] = null;
        }
        this.len = len;
        this.num_elem = 0;
        this.last_pos = 0;
    }

    // Verifica se um elemento está na árvore e retorna sua posição no vetor. Retorna -1 caso o elemento não esxista.
    protected int find(String nome){
        int i=0;
        while(true){
            // encontrou o lugar do elemento
            if(arvore[i] == null){
                return -1;
            }

            if(nome.compareTo(arvore[i]) > 0) i = 2*i + 2;      // o novo nome vem depois
            else if(nome.compareTo(arvore[i]) < 0) i = 2*i + 1;     // o novo nome vem antes
            else return i;    // o novo nome é igual
        }
    }

    public Boolean insert(String nome){
        if(this.num_elem == 0){
            // System.out.println("zero elementos!");
            this.arvore[0] = nome;
            this.num_elem++;
            return true;
        }
        else{
            int i=0;
            while(true){
                // encontrou o lugar do elemento
                if(arvore[i] == null){
                    arvore[i] = nome;
                    this.num_elem++;
                    if (i > last_pos) last_pos = i;
                    return true;
                }

                if(nome.compareTo(arvore[i]) > 0) i = 2*i + 2;      // o novo nome vem depois
                else if(nome.compareTo(arvore[i]) < 0) i = 2*i + 1;     // o novo nome vem antes
                else return false;    // o novo nome é igual (ignora)
            }
        }
    }

    public void print(){
        for(int i=0; i <= len-1; i++){
            System.out.print(this.arvore[i] + " ");
        }
        System.err.println("");
    }

    public String toString(){
        String res = "digraph {\n";
        Queue<Integer> fila = new LinkedList<>(); // fila das posições para percorrer em BFS
        int i = 0;
        fila.add(i);
        while(!fila.isEmpty()){
            i = fila.poll();
            String elem = this.arvore[i];
            if(elem == null) continue;
            int i_esq = 2*i + 1;
            int i_dir = 2*i + 2;
            if(i_esq < len && arvore[i_esq] != null){
                fila.add(i_esq);
                res += "\"" + i + " " + elem + "\" ->\"" + i_esq + " " + arvore[i_esq] + "\" \n";
            }
            if(i_dir < len && arvore[i_dir] != null){
                fila.add(i_dir);
                res += "\"" + i + " " + elem + "\" ->\"" + i_dir + " " + arvore[i_dir] + "\" \n";
            }
            if(i == 0 && arvore[i_esq] == null && arvore[i_dir] == null){
                res += "\"" + i + " " + elem + "\" ";
            }
        }

        res += "}\n";
        return res;
    }

    public int len(){
        return num_elem;
    }

    public boolean remove(String nome){
        int pos = find(nome);
        if(pos == -1) return false;
        
        // se o nó só tem um filho ou nenhum
        if(arvore[pos*2 + 1] == null) moverSubarvore(pos*2 + 2, pos);
        
        else if(arvore[pos*2 + 2] == null) moverSubarvore(pos*2 + 1, pos);
        
        // se o nó tem dois filhos, substituir pelo maior da árvore esquerda
        else{
            int i = pos*2 + 1;
            while(true){
                if(arvore[i*2 + 2] == null){
                    arvore[pos] = arvore[i];
                    arvore[i] = null;
                    break;
                }
                else i = i*2 + 2;   // procurando o maior
            }
        }
        
        // System.out.println("");
        num_elem--;
        return true;
    }

    // função recursiva para substituir um nó removido por sua única subárvore
    protected void moverSubarvore(int orig, int dest) {
        if(orig >= len || dest >= len) return;
        // System.out.println(arvore[dest] + " eh substituido por " + arvore[orig]);
        arvore[dest] = arvore[orig];
        arvore[orig] = null;
        // move os filhos
        moverSubarvore((orig*2 + 1), (dest*2 + 1));
        moverSubarvore((orig*2 + 2), (dest*2 + 2));
    }

    protected int height(int pos){
        if(pos > len || arvore[pos] == null) return -1;
        
        return Math.max(height(pos*2+1) + 1, height(pos*2+2) + 1);
    }

    // função auxiliar que retorna a posição do antessor de um elemento no array dado a sua posição
    protected int antecessor(int i){
        if(i%2 == 0) return (i-2)/2;
        else return (i-1)/2;
    }

    protected int filho_esq(int i){
        return (i*2 + 1);
    }

    protected int filho_dir(int i){
        return (i*2 + 2);
    }
}