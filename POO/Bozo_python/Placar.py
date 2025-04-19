from Dado import Dado

class Placar:
    def __init__(self):
        self.placar = []
        for _ in range (10):
            self.placar.append(-1)  # -1 indica uma posição vazia

    def conta(self, pos, dados):
        s = 0
        for dado in dados:
            if dado.getLado() == pos:
                s = s + pos
        return s
    
    def check_full(self, dados):
        val = []
        for dado in dados:
            val.append(dado.getLado())
        val.sort()
        
        if (val[0] == val[1] and val[1] == val[2] and val[3] == val[4]) or (val[0] == val[1] and val[2] == val[3] and val[3] == val[4]):
            return 15
        else:
            return 0
    
    def check_seq(self, dados):
        val = []
        for dado in dados:
            val.append(dado.getLado())
        val.sort()

        for i in range (len(val) - 1):
            if val[i]+1 != val[i+1]:
                return 0
            
        return 20
    
    def check_quadra(self, dados):
        val = []
        for dado in dados:
            val.append(dado.getLado())
        val.sort()
        
        if (val[0] == val[1] and val[0] == val[2] and val[0] == val[3]) or (val[1] == val[2] and val[1] == val[3] and val[1] == val[4]):
            return 30
        else:
            return 0
    
    def check_quina(self, dados):
        val = []
        for dado in dados:
            val.append(dado.getLado())
        
        if (val[0] == val[1] and val[0] == val[2] and val[0] == val[3] and val[0] == val[4]):
            return 40
        else:
            return 0

    def add(self, posicao, dados):
        if self.placar[posicao-1] != -1:
            raise ValueError("Posição ocupada")
        
        match (posicao):
            case 1:
                k = self.conta(1, dados)

            case 2:
                k = self.conta(2, dados)
                
            case 3:
                k = self.conta(3, dados)
                
            case 4:
                k = self.conta(4, dados)
                
            case 5:
                k = self.conta(5, dados)
                
            case 6:
                k = self.conta(6, dados)
                
            # full
            case 7:
                k = self.check_full(dados)
                
            # sequencia
            case 8:
                k = self.check_seq(dados)
                
            # quadra
            case 9:
                k = self.check_quadra(dados)
                
            # quina
            case 10:
                k = self.check_quina(dados)

            case _:
                raise ValueError("valor de posicao invalido")
        
        self.placar[posicao - 1] = k
                
    def getScore(self):
        sum = 0
        for val in self.placar:
            if val != -1:
                sum = sum + val
        return sum

    def toString(self):
        for i in range (3):
            s = ""
            if (self.placar[i] != -1):
                num = f"{self.placar[i]:<4}" 
                s = " " + num + "  |   " 
            else:
                num = f"({i+1})"
                s = num + "    |   "

            
            if (self.placar[i+6] != -1):
                num = f"{self.placar[i+6]:<4}"  
                s = s + " " + num + "  |  "
            else:
                num = f"({i+7})"
                s = s + num + "    |  "


            if (self.placar[i+3] != -1):
                num = f"{self.placar[i+3]:<3}"  
                s = s + " " + num
            else:
                num = f"({i+4}) "
                s = s + num

            print(s)
            print("-------|----------|-------")

        if (self.placar[9] != -1):
            num = f"{self.placar[9]:<4}"  
            s = "       |    " + num + "  |"
        else:
            num = f"(10)"
            s = "       |   " + num + "   |"
        print(s)
        s = "       +----------+\n"
        print(s)


#        (1)    |   (7)    |   (4) 
# 	     --------------------------
# 	     (2)    |   20     |   (5) 
# 	     --------------------------
# 	     (3)    |   30     |   (6) 
#        --------------------------
#               |   (10)   |
#               +----------+ 


# Teste
# dados = []
# for _ in range (5):
#     dados.append(Dado())

# placar = Placar()
# # placar.add(7, dados)
# placar.toString()