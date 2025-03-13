from datetime import date

class Pessoa:
    def __init__(self, nome, data_nascimento, peso, altura):
        self.nome = nome
        self.data_nascimento = data_nascimento
        self.peso = peso
        self.altura = altura
    
    def get_nome(self):
        return self.nome
        
    def set_nome(self, novo_nome):
        self.nome = novo_nome
        
    def get_peso(self):
        return self.peso
        
    def set_peso(self, novo_peso):
        self.peso = novo_peso
        
    def get_altura(self):
        return self.altura
        
    def set_altura(self, novo_altura):
        self.altura = novo_altura    
        
    def get_data_nascimento(self):
        return self.data_nascimento
        
    def set_data_nascimento(self, novo_data_nascimento):
        self.data_nascimento = novo_data_nascimento    
        
    def calc_idade(self):
        dia = int(self.data_nascimento[0:2])
        mes = int(self.data_nascimento[3:5])
        ano = int(self.data_nascimento[6:])
        data_atual = date.today()
        if mes < data_atual.month or (mes == data_atual.month and dia <= data_atual.day):
            idade = data_atual.year - ano
        else:
            idade = data_atual.year - ano - 1
        return idade

p1 = Pessoa("Bia", "13/08/2005", 55, 1.6)
print(p1.get_nome())
print(p1.calc_idade(), "anos")
print(p1.get_data_nascimento())
print(p1.get_altura())
print(p1.get_peso())

