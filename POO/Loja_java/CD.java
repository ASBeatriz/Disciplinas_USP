public class CD extends Produto {
    private String cantor;
    private int numTrilhas;
    private String gravadora;
    private int ano;

    public CD(long codigo, String nome){
        super(codigo, nome);
        tipo = "CD";
    }

    public void print(){
         /*
            CD
            Código: 8579715172
            Título: COLECAO MILTON NASCIMENTO
            Banda: Milton Nascimento
            Gravadora: Abril
            Ano: 2022
            trilhas: 10
            Quantidade: 0
         */

         System.out.println("CD");
         System.out.println("Código: " + codigo);
         System.out.println("Título: " + titulo);
         System.out.println("Banda: " + cantor);
         System.out.println("Gravadora: " + gravadora);
         System.out.println("Ano: " + ano);
         System.out.println("trilhas: " + numTrilhas);
    }

    // I, CD, código, Título do álbum, Cantor ou banda, Número de trilhas, Gravadora, Ano
    
    public void set_cantor(String cantor){
        this.cantor = cantor;
    }

    public String get_cantor(){
        return this.cantor;
    }

    public void set_numTrilhas(int numTrilhas){
        this.numTrilhas = numTrilhas;
    }

    public int get_numTrilhas(){
        return this.numTrilhas;
    }
    
    public void set_gravadora(String gravadora){
        this.gravadora = gravadora;
    }

    public String get_gravadora(){
        return this.gravadora;
    }

    public void set_ano(int ano){
        this.ano = ano;
    }

    public int get_ano(){
        return this.ano;
    }
}
