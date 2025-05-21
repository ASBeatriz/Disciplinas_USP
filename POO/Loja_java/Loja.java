import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Loja {
    // lista com os produtos inseridos (acervo)
    private List<Produto> acervo;

    // quantidade de produtos no acervo
    int tam_acervo;     

    // quantidade total de livros, cd e dvd
    int qtde_livro;
    int qtde_cd;
    int qtde_dvd;

    public Loja(){
        qtde_cd = qtde_dvd = qtde_livro = tam_acervo = 0;
        acervo = new ArrayList<>();
    }

    // FUNÇÕES PRINCIPAIS

    // Função para inserir um produto no acervo
    public void inserir(Produto prod){
        System.out.println("Operação inserir " + prod.get_tipo() + ": " + prod.get_codigo());
        
        if(busca_acervo(prod.get_codigo()) == -1){
            acervo.add(prod);
            tam_acervo++;
            System.out.println("Operação realizada com sucesso\n");
        }
        else System.out.println("***Erro: Código já cadastrado: " + prod.get_codigo());
    }

    // Função para adcicionar (comprar) um produto na loja
    public void adicionar(long codigo, int qtde){
        System.out.println("Operação de compra: " + codigo);

        // Busca para encontrar o produto no acervo
        int pos = busca_acervo(codigo);
        if(pos != -1){
            acervo.get(pos).add_qtde(qtde);
            incrementa_qtde_tipo(acervo.get(pos), qtde);
            System.out.println("Operação realizada com sucesso: " + codigo + "\n");
        }
        else
            System.out.println("***Erro: Código inexistente: " + codigo + "\n");
    }

    // Função de busca pelo código
    public void procura(long cod){
        int pos = busca_acervo(cod);
        if(pos != -1){
            System.out.println("Encontrado:");
            acervo.get(pos).print();
        }
        else System.out.println("Produto não encontrado: " + cod);

        System.out.println("");
    }

    // Função de busca pelo titulo
    public void procura(String titulo){

        // busca do produto pelo titulo
        for(int i=0; i<tam_acervo; i++){
            if(acervo.get(i).get_titulo().equals(titulo)){
                System.out.println("Encontrado:");
                acervo.get(i).print();
                 System.out.println("");
                return;
            }
        }

        System.out.println("Produto não encontrado: " + titulo + "\n");
    }

    // Função para vender uma quantidade de um produto da loja
    public void vender(long codigo, int qtde){
        System.out.println("Operação de venda: " + codigo);
        
        int pos = busca_acervo(codigo);
        if(pos != -1){
            if(acervo.get(pos).get_qtde() >= qtde){
                acervo.get(pos).add_qtde(-qtde);
                incrementa_qtde_tipo(acervo.get(pos), -qtde);
                System.out.println("Operação realizada com sucesso: " + codigo + "\n");
            }
            else 
                System.out.println("***Erro: Estoque insuficiente: " + codigo + " Quantidade: " + qtde + "\n");
        }
        else 
            System.out.println("***Erro: Código inexistente: " + codigo + "\n");
    }

    // Função para imprimir o sumário da Loja
    public void sumario(){
        System.out.println("Operação de sumarização: ");
        // Ordem: Livro, CD, DVD

        // filtra para deixar apenas os livros
        List<Produto> livros = acervo.stream().filter(prod -> prod.get_tipo() == "livro").collect(Collectors.toList());
        for (Produto produto : livros) {
            produto.print();
            System.out.println("Quantidade: " + produto.qtde + "\n");
        }
        System.out.println("Quantidade de Livros: " + qtde_livro + "\n");

        // filtra para deixar apenas os CDs
        List<Produto> CDs = acervo.stream().filter(prod -> prod.get_tipo() == "CD").collect(Collectors.toList());
        for (Produto produto : CDs) {
            produto.print();
            System.out.println("Quantidade: " + produto.qtde + "\n");
        }
        System.out.println("Quantidade de CDs: " + qtde_cd + "\n");

        // filtra para deixar apenas os DVDs
        List<Produto> DVDs = acervo.stream().filter(prod -> prod.get_tipo() == "DVD").collect(Collectors.toList());
        for (Produto produto : DVDs) {
            produto.print();
            System.out.println("Quantidade: " + produto.qtde + "\n");
        }
        System.out.println("Quantidade de DVDs: " + qtde_dvd + "\n\n");

    }

    // FUNÇÕES AUXILIARES

    // função auxiliar para incrementar a quantidade de um tipo de produto no acervo
    private void incrementa_qtde_tipo(Produto prod, int qtde){
        if(prod.get_tipo() == "livro") qtde_livro += qtde;
        else if(prod.get_tipo() == "CD") qtde_cd += qtde;
        else if(prod.get_tipo() == "DVD") qtde_dvd += qtde;
    }

    // função auxiliar para realizar a busca de um produto no acervo. Retorna sua posição ou -1 caso não exista.
    private int busca_acervo(long codigo){
        for(int i=0; i<tam_acervo; i++){
            if(acervo.get(i).get_codigo() == codigo){
                return i;
            }
        }
        return -1;
    }

}

// Ideia: fazer uma "lista" de produtos inseridos aqui? (objetos das classes livros/cd/dvd)