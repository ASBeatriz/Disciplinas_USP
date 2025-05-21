import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ArvBal extends ArvBin {

    public ArvBal(int len){
        super(len);
    }

    @Override
    public Boolean insert(String nome){
        // faz a inserção normalmente
        // System.out.println("Insere " + nome);
        if(!super.insert(nome)) return false;
        // System.out.println(toString());

        // lista de nomes ordenados
        List<String> nomes_ord = new ArrayList<>();
        percorre_emOrdem(0, nomes_ord);
        // System.out.println("nomes ord: " + nomes_ord + "\n");

        // limpa a árvore
        Arrays.fill(arvore, null);

        // Transforma em árvore balanceada
        turnToArvBal(nomes_ord, 0, num_elem-1, 0);
        // System.out.println("Rebalanceada:\n" + toString());

        return true;
    }

    @Override
    public boolean remove(String nome){
        // remove normalmente
        if(!super.remove(nome)) return false;   
        // System.out.println("Remove " + nome);
        // System.out.println(toString());

        // faz o balanciamento
        // lista de nomes ordenados
        List<String> nomes_ord = new ArrayList<>();
        percorre_emOrdem(0, nomes_ord);
        // System.out.println("nomes ord: " + nomes_ord + "\n");

        // Transforma em árvore balanceada
        turnToArvBal(nomes_ord, 0, num_elem-1   , 0);
        // System.out.println("Rebalanceada:\n" + toString());

        return true;
    }

    private void percorre_emOrdem(int i, List<String> nomes_ord){
        if(i >= len || arvore[i] == null) return;
        percorre_emOrdem(i*2+1, nomes_ord);
        nomes_ord.add(arvore[i]);
        percorre_emOrdem(i*2+2, nomes_ord);
    }

    // Constrói árvore balanceada a partir de uma lista ordenada com os nomes
    private void turnToArvBal(List<String> nomes_ord, int inicio, int fim, int indice) {
        if (inicio > fim || indice >= len) return;

        int meio = (inicio + fim) / 2;
        arvore[indice] = nomes_ord.get(meio);

        turnToArvBal(nomes_ord, inicio, meio-1, 2*indice+1);
        turnToArvBal(nomes_ord, meio+1, fim, 2*indice+2);
    }


}
