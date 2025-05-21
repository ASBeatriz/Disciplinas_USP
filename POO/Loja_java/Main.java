import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("");

        Loja loja = new Loja();

        Scanner scan = new Scanner(System.in);

        while (scan.hasNextLine()) {
            // faz a leitura dos comandos
            String linha = scan.nextLine();
            String[] comando = linha.split(",");

            if(comando[0].equals("I")){
                long cod = Long.parseLong(comando[2]);
                String nome = comando[3];

                if(comando[1].equals("Livro")){
                    // I, Livro, código, Nome do livro, Autor 1, Editora, Ano, Edição, páginas, idioma
                    
                    Livro livro = new Livro(cod, nome);
                    livro.set_autor(comando[4]);
                    livro.set_editora(comando[5]);
                    livro.set_ano(Integer.parseInt(comando[6]));
                    livro.set_edicao(Integer.parseInt(comando[7]));
                    livro.set_paginas(Integer.parseInt(comando[8]));
                    livro.set_idioma(comando[9]);
                    loja.inserir(livro);
                }
                else if(comando[1].equals("CD")){
                    // I, CD, código, Título do álbum, Cantor ou banda, Número de trilhas, Gravadora, Ano
                    
                    CD cd = new CD(cod, nome);
                    cd.set_cantor(comando[4]);
                    cd.set_numTrilhas(Integer.parseInt(comando[5]));
                    cd.set_gravadora(comando[6]);
                    cd.set_ano(Integer.parseInt(comando[7]));
                    loja.inserir(cd);
                }
                else if(comando[1].equals("DVD")){
                    // I, DVD, código, Nome do filme, Diretor, idioma, Gênero, Ano, Nacionalidade
                    
                    DVD dvd = new DVD(cod, nome);
                    dvd.set_diretor(comando[4]);
                    dvd.set_idioma(comando[5]);
                    dvd.set_genero(comando[6]);
                    dvd.set_ano(Integer.parseInt(comando[7]));
                    dvd.set_nacionalidade(comando[8]);
                    loja.inserir(dvd);
                }
            }
            else if(comando[0].equals("A")){
                // A, código, quantidade

                long cod = Long.parseLong(comando[1]);
                int qtde = Integer.parseInt(comando[2]);
                loja.adicionar(cod, qtde);
            }
            else if(comando[0].equals("V")){
                // V, código, quantidade
    
                long cod = Long.parseLong(comando[1]);
                int qtde = Integer.parseInt(comando[2]);
                loja.vender(cod, qtde);

            }
            else if(comando[0].equals("P")){
                System.out.println("Procurando: " + comando[1]);
                // P, código
                // P, Nome
                try{
                    long cod = Long.parseLong(comando[1]);
                    loja.procura(cod);
                }
                catch(NumberFormatException e){
                    loja.procura(comando[1]);
                }
            }
            else if(comando[0].equals("S")){
                loja.sumario();
            }
        }

        scan.close();
    }
}


/*

------- Inserir produtos: --------
I, Livro, código, Nome do livro, Autor 1, Editora, Ano, Edição, páginas, idioma

I, CD, código, Título do álbum, Cantor ou banda, Número de trilhas, Gravadora, Ano

I, DVD, código, Nome do filme, Diretor, idioma, Gênero, Ano, Nacionalidade
 

------- Adicionar produtos no estoque: ---------
A, código, quantidade

-------- Vender produtos do estoque: ----------
V, código, quantidade

-------- Procurar produtos: ------------
P, código
P, Nome

------- Sumário da loja: -----------
S

*/