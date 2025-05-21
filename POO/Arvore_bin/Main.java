import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        ArvBin arv = new ArvBin(100);
        ArvBal arvbal = new ArvBal(100);
        ArvAVL arvavl = new ArvAVL(100);
        Scanner scan = new Scanner(System.in);

        while (scan.hasNextLine()) {
            // faz a leitura dos comandos
            String linha = scan.nextLine();
            String[] comando = linha.split(" ");

            if(comando[0].equals("i")){
                arv.insert(comando[1]);
                arvbal.insert(comando[1]);
                arvavl.insert(comando[1]);
            }
            else if(comando[0].equals("d")){
                arv.remove(comando[1]);
                arvbal.remove(comando[1]);    
                arvavl.remove(comando[1]);
            }
        }

        scan.close();

        String digraph = arv.toString();
        String digraph_bal = arvbal.toString();
        String digraph_avl = arvavl.toString();
        System.out.println(digraph);
        System.out.println(digraph_bal);
        System.out.println(digraph_avl);
        // System.out.println(digraph_bal); // não consegui fazer a AVL 
    }
}
