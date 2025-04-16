import math

class Tabuleiro:

    # Constructor
    def __init__(self, valores):
        # Calcula o tamanho do tabuleiro (lado)
        self.tam_tab = int(math.sqrt(len(valores)))

        # Cria a matriz que representa o tabuleiro
        self.tab = [valores[i*self.tam_tab : (i+1)*self.tam_tab] for i in range (self.tam_tab)]
        
        # Encontra a posição do zero
        self.zero_l, self.zero_c = self.encontra_zero((self.tab))

    # Função para verificar se o tabuleiro está na ordem correta
    def verifica_tab(self):
        for i, linha in enumerate(self.tab):
            for j, valor in  enumerate(linha):
                # Condição de alguma peça estar fora do lugar
                if valor != self.tam_tab*i + j:
                    return False
        return True
    
    def encontra_zero(self, tab):
        for i, linha in enumerate(tab):
            for j, valor in enumerate(linha):
                if valor == 0:
                    return i, j

    def move(self, sequencia):
        for i in range (len(sequencia)):
            self.aplica_movimento(sequencia[i])
            self.imprime_tab()

    def aplica_movimento(self, mov):
        # up
        if mov == 'u':
            if self.zero_l < (self.tam_tab - 1):
                self.tab[self.zero_l][self.zero_c] = self.tab[self.zero_l+1][self.zero_c]
                self.tab[self.zero_l+1][self.zero_c] = 0
                self.zero_l = self.zero_l + 1
        # down
        elif mov == 'd':
            # Trocar o 0 com o de cima
            if self.zero_l > 0 :
                self.tab[self.zero_l][self.zero_c] = self.tab[self.zero_l-1][self.zero_c]
                self.tab[self.zero_l-1][self.zero_c] = 0
                self.zero_l = self.zero_l - 1
         
        # left
        elif mov == 'l':
            # Trocar o 0 com o da direita
            if self.zero_c < self.tam_tab-1 :
                self.tab[self.zero_l][self.zero_c] = self.tab[self.zero_l][self.zero_c+1]
                self.tab[self.zero_l][self.zero_c+1] = 0
                self.zero_c = self.zero_c + 1
         
        # right
        elif mov == 'r':
            # Trocar o 0 com o da esquerda
            if self.zero_c > 0 :
                self.tab[self.zero_l][self.zero_c] = self.tab[self.zero_l][self.zero_c-1]
                self.tab[self.zero_l][self.zero_c-1] = 0
                self.zero_c = self.zero_c - 1
         
    # Função que imprime na tela o estado atual do tabuleiro
    def imprime_tab(self):
        for i in range (self.tam_tab): 
            for _ in range (self.tam_tab): 
                print("+------", end="")
            print("+")
            print("|  ", end="")
            
            for j in range (self.tam_tab):
                if self.tab[i][j] < 10 :
                    print(" ", end="")   # Consertar a formatação
                if self.tab[i][j] != 0 :
                    print(self.tab[i][j], end = "")
                else:
                    print(" ", end="")
                print("  |  ", end="")
                   
            print("\n", end="")
        
        for _ in range (self.tam_tab):
            print("+------", end="")
        print("+\n")
        

# [0, 1, 2, 3, 4, 5, 6, 7, 8]