public class Tabuleiro {
    private int[][] tab;
    private int tam_tab;
    private int zero_l;
    private int zero_c;

    // Construtor
    public Tabuleiro(int[] valores){
        // Calcula o tamanho do tabuleiro
        tam_tab = (int)Math.sqrt(valores.length); 
        tab = new int[tam_tab][tam_tab];

        // Passa os valores para a matriz que representa o tabuleiro
        int k = 0;
        for(int i=0; i<tam_tab; i++){
            for(int j=0; j<tam_tab; j++){
                tab[i][j] = valores[k++];
            }
        }

        // Guarda a posição do zero no tabuleiro
        for(int i=0; i<tam_tab; i++){
            for(int j=0; j<tam_tab; j++){
                if (tab[i][j] == 0){
                    zero_l = i;
                    zero_c = j;
                    return;
                }
            }
        }
    }   

    // Função que verifica se o tabuleiro está na ordem correta
    public Boolean verifica_tab(){
        for(int i=0; i<tam_tab; i++){
            for(int j=0; j<tam_tab; j++){
                // Condição de alguma peça no lugar errado

                if (tab[i][j] != tam_tab*i+j) return false;
            }
        }
        return true;
    }

    // Função que decodifica a string recebida e chama a função que realiza o movimento
    public void move(String seq){
        for(int i=0; i<seq.length(); i++){
            char mov = seq.charAt(i);
            aplica_movimento(mov);
            imprime_tab();
        }
    }

    // Função que aplica o movimento no tabuleiro de acordo com o caractere recebido
    public void aplica_movimento(char mov){
        // up
        if(mov == 'u'){
            // Trocar o 0 com o de baixo
            if(zero_l < tam_tab-1){
                tab[zero_l][zero_c] = tab[zero_l+1][zero_c];
                tab[zero_l+1][zero_c] = 0;
                zero_l++; 
            }
        }
        // down
        else if(mov == 'd'){
            // Trocar o 0 com o de cima
            if(zero_l > 0){
                tab[zero_l][zero_c] = tab[zero_l-1][zero_c];
                tab[zero_l-1][zero_c] = 0;
                zero_l--;
            }
        }
        // left
        else if(mov == 'l'){
            // Trocar o 0 com o da direita
            if(zero_c < tam_tab-1){
                tab[zero_l][zero_c] = tab[zero_l][zero_c+1];
                tab[zero_l][zero_c+1] = 0;
                zero_c++;
            }
        }
        // right
        else if(mov == 'r'){
            // Trocar o 0 com o da esquerda
            if(zero_c > 0){
                tab[zero_l][zero_c] = tab[zero_l][zero_c-1];
                tab[zero_l][zero_c-1] = 0;
                zero_c--;
            }
        }
    }

    // Função que imprime na tela o estado atual do tabuleiro
    public void imprime_tab(){
        for(int i=0; i<tam_tab; i++){
            for(int k=0; k<tam_tab; k++) System.out.print("+------");
            System.out.println("+");
            System.out.print("|  ");
            
            for(int j=0; j<tam_tab; j++){
                if(tab[i][j] < 10)System.out.print(" ");   // Consertar a formatação
                System.out.print(tab[i][j]);
                System.out.print("  |  ");
                
            }   
            System.out.print("\n");
        }
        for(int k=0; k<tam_tab; k++) System.out.print("+------");
        System.out.println("+\n");
    }

}
