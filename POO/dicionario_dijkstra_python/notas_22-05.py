# chave:valor
dicio = {"A": 123, "B": 321, 30:20, "k":"j"}
print(dicio)
print(dicio["k"], dicio["A"])

dicio["novo"] = "valor :p"
print(dicio)

print() # /n

# args: é passado como uma lista
def funcao(a, b, *args, c = 0):
    print(a, b, args, c)

funcao(1, 2, 'a', 30, True, c=3)
funcao(1, 2, 'a', 30, True, 3)

# kwargs: dicionario
def funcao2(**kwargs):
    print(kwargs)

funcao2(Bia = 19, Lane = 21, Rejane = 47)

# Overloading de Operadores
# definindo uma comparação de objetos que, inicialmente, não existe
# contexto: método de uma classe que tenho get_nome
#  <
def __lt__ (self, outro):
    return self.get_nome() < outro.get_nome()
#  ==
def __eq__ (self, outro):
    return self.get_nome() == outro.get_nome()
# ...