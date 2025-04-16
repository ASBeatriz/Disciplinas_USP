import java.util.Scanner;
    
    public class Main {
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);

            // Leitura do tabuleiro inicial
            String entrada = scan.nextLine();
            String[] entrada_div = entrada.split(" ");
            int[] valores = new int[entrada_div.length];
            
            for(int i=0; i<entrada_div.length; i++) valores[i] = Integer.parseInt(entrada_div[i]);

            Tabuleiro tab = new Tabuleiro(valores);
            tab.imprime_tab();
            
            // Leitura dos movimentos
            String moves = scan.nextLine();
            tab.move(moves);
            
            System.out.println("Posicao final: " + tab.verifica_tab());
            scan.close();
        }
    }