public class Livro extends Produto {
    private String autor;
    private String editora;
    private int ano;
    private int edicao;
    private int paginas;
    private String idioma;

    public Livro(long codigo, String nome){
        super(codigo, nome);
        tipo = "livro";
    }

    public void print() {
        /*
            Livro
            Código: 8522104999
            Título: Introdução á teoria da computação
            Autor: Michael Sipser
            Editora: Cengage Learning
            Edição: 1
            Ano: 2005
            Páginas: 612
            Idioma: PT-BR
         */

         System.out.println("Livro");
         System.out.println("Código: " + codigo);
         System.out.println("Título: " + titulo);
         System.out.println("Autor: " + autor);
         System.out.println("Editora: " + editora);
         System.out.println("Edição: " + edicao);
         System.out.println("Ano: " + ano);
         System.out.println("Páginas: " + paginas);
         System.out.println("Idioma: " + idioma);
    }

    // gets e sets

    public void set_autor(String autor){
        this.autor = autor;
    }

    public String get_autor(){
        return this.autor;
    }

    public void set_editora(String editora){
        this.editora = editora;
    }

    public String get_editora(){
        return this.editora;
    }

    public void set_ano(int ano){
        this.ano = ano;
    }

    public int get_ano(){
        return this.ano;
    }

    public void set_edicao(int edicao){
        this.edicao = edicao;
    }

    public int get_edicao(){
        return this.edicao;
    }

    public void set_paginas(int paginas){
        this.paginas = paginas;
    }

    public int get_paginas(){
        return this.paginas;
    }

    public void set_idioma(String idioma){
        this.idioma = idioma;
    }

    public String get_idioma(){
        return this.idioma;
    }
}
