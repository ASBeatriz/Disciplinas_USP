public class MeuPrograma {
    public static void main(String[] args){
        System.out.println("Hello World again!");
        Cadeira c1 = new Cadeira();
        Cadeira c2 = new Cadeira("invertido", false);
        System.out.println(c2.get_posicao());


        System.out.println("c1 esta " + (c1.get_ocupado() ? "ocupado" : "livre"));
        c1.sentar();
        System.out.println("c1 esta " + (c1.get_ocupado() ? "ocupado" : "livre"));
    }
}