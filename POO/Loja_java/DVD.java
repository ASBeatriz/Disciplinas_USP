public class DVD extends Produto{
    private String diretor;
    private String idioma;
    private String genero;
    private int ano;
    private String nacionalidade;

    public DVD(long codigo, String nome){
        super(codigo, nome);
        tipo = "DVD";
    }
    
    public void print() {
        /*
            DVD
            Código: 7899307921551
            Título: Tinker Bell E O Monstro Da Terra Do Nunca
            Diretor: John Doe
            Gênero: Animação
            Ano: 2003
            Nacionalidade: Estadunidense
            Idioma: PT-BR
         */

         System.out.println("DVD");
         System.out.println("Código: " + codigo);
         System.out.println("Título: " + titulo);
         System.out.println("Diretor: " + diretor);
         System.out.println("Gênero: " + genero);
         System.out.println("Ano: " + ano);
         System.out.println("Nacionalidade: " + nacionalidade);
         System.out.println("Idioma: " + idioma);
    }

    // I, DVD, código, Nome do filme, Diretor, idioma, Gênero, Ano, Nacionalidade

    public void set_diretor(String diretor){
        this.diretor = diretor;
    }

    public String get_diretor(){
        return this.diretor;
    }

    public void set_idioma(String idioma){
        this.idioma = idioma;
    }

    public String get_idioma(){
        return this.idioma;
    }
    
    public void set_genero(String genero){
        this.genero = genero;
    }

    public String get_genero(){
        return this.genero;
    }

    public void set_ano(int ano){
        this.ano = ano;
    }

    public int get_ano(){
        return this.ano;
    }

    public void set_nacionalidade(String nacionalidade){
        this.nacionalidade = nacionalidade;
    }

    public String get_nacionalidade(){
        return this.nacionalidade;
    }
}
