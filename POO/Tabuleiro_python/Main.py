from Tabuleiro import Tabuleiro

valores = list(map(int, input().split()))

t1 = Tabuleiro(valores)
t1.imprime_tab()

movimentos = input()
t1.move(movimentos)

print("Posicao final:", t1.verifica_tab())