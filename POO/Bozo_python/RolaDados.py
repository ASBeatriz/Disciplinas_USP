from random import Random
from Dado import Dado

class RolaDados:
    # Construtor
    def __init__(self, n, seed):
        self.rand = Random()
        if seed != 0:
            self.rand.seed(seed)

        self.dados = []
        for _ in range (n):
            if seed != 0:
                self.dados.append(Dado(6, self.rand.randint(1, 10000)))
            else:
                self.dados.append(Dado())

        # Debug
        # for dado in self.dados:
        #     print(dado.getLado(), end=" ")
        # print("")

    
    def rolar(self, numeros):
        # Rolar todos os dados
        if numeros == "all":
            for dado in self.dados:
                dado.rolar()
        # Rolar dados selecionados
        else:
            for i in numeros:
                if i>0 and i<= len(self.dados):
                    self.dados[i-1].rolar()

        # Debug
        # for dado in self.dados:
        #     print(dado.getLado(), end=" ")
        # print("")
            
    def toString(self):
        ini, fim = 0, 7
        s = "1          2          3          4          5"
        print(s)
        for _ in range (5):
            s = ""
            for dado in self.dados:
                sd = dado.toString()
                s += sd[ini:fim] + "    "

            print(s)
            ini = ini + 8 
            fim = fim + 8
        print("")

    def getDados(self):
        return self.dados


# Teste
# rd = RolaDados(5)
# rd.rolar([1, 3])
# rd.toString()

