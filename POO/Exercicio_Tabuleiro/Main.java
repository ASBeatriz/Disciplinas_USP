import java.util.Scanner;
    
    public class Main {
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            int[][] mat = new int[3][3];

            // Leitura do tabuleiro inicial
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    mat[i][j] = scan.nextInt();
                }
            }
            scan.nextLine(); // tira o \n do buffer

            Tabuleiro tab = new Tabuleiro(mat);
            tab.imprime_tab();
            
            // Leitura dos movimentos
            String moves = scan.nextLine();
            tab.move(moves);
            
            System.out.println("Posicao final: " + tab.verifica_tab());
            scan.close();
        }
    }