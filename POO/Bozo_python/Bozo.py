from RolaDados import RolaDados
from Placar import Placar

class Bozo:
    
    def __init__(self):
        print("Digite a semente (zero para aleatório): ", end="")
        seed = int(input())
        rd = RolaDados(5, seed)
        placar = Placar()
        num_rodadas = 10
        placar.toString()

        for rodada in range (num_rodadas):
            print("****** Rodada", rodada+1)
            print("Pressione ENTER para lançar os dados")
            input()
            # Primeiro lançamento
            rd.rolar("all")
            rd.toString()

            # Primeira troca
            print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
            selecionados = set()
            entrada = input().split()
            for e in entrada:
                try:
                    selecionados.add(int(e))
                except ValueError:
                    pass
            selecionados = list(selecionados)
            rd.rolar(selecionados)
            rd.toString()

            # Segunda troca
            print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
            selecionados = set()
            entrada = input().split()
            for e in entrada:
                try:
                    selecionados.add(int(e))
                except ValueError:
                    pass
            selecionados = list(selecionados)
            rd.rolar(selecionados)
            rd.toString()

            # Escolha da posição
            print('\n\n')
            placar.toString()
            i = 0
            while(i == 0):
                try:
                    print("Escolha a posição que quer ocupar com essa jogada ===> ", end="")
                    pos = int(input())
                    i = 1
                    placar.add(pos, rd.getDados())
                except ValueError:
                    print("Valor inválido. Posição ocupada ou inexistente.")
                    i = 0
            print('\n\n')
            placar.toString()
                    
        print("***********************************")
        print("***")
        print("*** Seu escore final foi:", placar.getScore())
        print("***")
        print("***********************************")



if __name__ == "__main__":
    jogo = Bozo()