// public/private = controle de acesso da classe, atributo ou método 
public class Cadeira {
    private String posicao;
    private boolean ocupado;

    // Contrutor
    public Cadeira(){
        posicao = "em pe";
        ocupado = false;
    }
    // Pode ter mais de um constructor
    public Cadeira(String pos, boolean ocup){
        this.posicao = pos;
        this.ocupado = ocup;
    }

    public void sentar(){   
        if((!ocupado) && posicao.equals("em pe")) ocupado = true;
    }
    public void levantar(){
        ocupado = false;
    }
    public void virar(){
        if (posicao == "em pe") posicao = "invertido";
        else posicao = "em pe";
    }
    public String get_posicao(){
        return this.posicao;
    }

    public boolean get_ocupado(){
        return this.ocupado;
    }
}

//  VERIFICAR COM OS SLIDES DO PROF!!
