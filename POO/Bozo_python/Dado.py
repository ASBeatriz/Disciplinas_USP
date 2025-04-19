from random import Random

class Dado:

    # Construtor
    def __init__(self, lados=6, seed=None):
        # atributos
        self.atual = None
        self.s010 = "|  *  |\n" # strings para desenhar dado
        self.s100 = "|*    |\n"
        self.s001 = "|    *|\n"
        self.s000 = "|     |\n"
        self.s101 = "|*   *|\n"
        self.s111 = "|* * *|\n"
        self.s___ = "+-----+\n"

        # comandos de inicialização
        self.lados = lados
        self.rand = Random()
        if seed is not None:
            self.rand.seed(seed)
        self.rolar()

    # Métodos
    def rolar(self):
        self.atual = self.rand.randint(1, self.lados)
        return self.atual

    def getLado(self):
        return self.atual

    def toString(self):
        if self.lados != 6:
            print("Nao ha representacao grafica para esse dado")
            return
        
        s = self.s___
        match self.atual:
            case 1:
                s = s + self.s000 + self.s010 + self.s000
            case 2:
                s = s + self.s100 + self.s000 + self.s001
            case 3:
                s = s + self.s100 + self.s010 + self.s001
            case 4:
                s = s + self.s101 + self.s000 + self.s101
            case 5:
                s = s + self.s101 + self.s010 + self.s101
            case 6:
                s = s + self.s111 + self.s000 + self.s111
        s = s + self.s___
        return s    
    

# Teste
# d = Dado(6, None)
# s = d.toString()
# print(s)

