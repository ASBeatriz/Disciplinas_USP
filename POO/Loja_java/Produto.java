// Implementar as características básicas de um produto

public abstract class Produto {
    protected long codigo;
    protected int qtde;     // quantidade de exemplares no estoque
    protected String tipo;  // tipo do produto
    protected String titulo;  // titulo do produto

    public Produto(long codigo, String titulo){
        this.codigo = codigo;
        this.titulo = titulo;
        qtde = 0;
    }

    public void set_qtde(int qtde){
        this.qtde = qtde;
    }

    public void add_qtde(int qtde){
        this.qtde += qtde;
    }

    public int get_qtde(){
        return this.qtde;
    }

    public void set_codigo(long codigo){
        this.codigo = codigo;
    }

    public long get_codigo(){
        return this.codigo;
    }

    public void set_tipo(String tipo){
        this.tipo = tipo;
    }

    public String get_tipo(){
        return this.tipo;
    }

    public void set_titulo(String titulo){
        this.titulo = titulo;
    }

    public String get_titulo(){
        return this.titulo;
    }

    public abstract void print();
}
