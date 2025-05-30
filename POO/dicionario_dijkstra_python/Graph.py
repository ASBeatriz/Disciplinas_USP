import math
from queue import PriorityQueue

class Graph:
    def __init__(self, entrada):
        self.graph = {}
        self.dist = {} # dicionario com as distâncias
        self.ant = {} # dicionario com os antecessores
        self.visited = {}

        linhas = entrada.strip().split('\n')
        for linha in linhas:
            lin = linha.strip().split()
            # Monta o grafo
            if len(lin) == 1:
                pai = lin[0]
                self.graph[pai] = {}
            else:
                self.graph[pai][lin[0]] = int(lin[1])
            
        # print(graph)


    # Função auxiliar para limpar os dicionários de distancia, anterior e visitados
    def clear_dics (self):
        self.visited = {}
        self.ant = {}
        self.dist = {}

    # Função para implementar o dijkstra e imprimir o resultado
    def dijkstra(self, orig):
        # limpa os dicionarios
        self.clear_dics()

        # fila de prioridade com as chaves e distância
        fila = PriorityQueue()  
        key_list1 = list(self.graph.keys())    
        key_list2 = []
        for key in key_list1:
            key_list2 += list(self.graph[key].keys())
        
        # lista com as chaves (cidades)
        all_keys = set(key_list1 + key_list2) 

        # inicializa a distância e o anterior de cada vértice
        for key in all_keys:
            if key == orig:
                fila.put((0, key))  # adiciona a origem na fila
                self.dist[key] = 0   # origem tem distância 0
            else:
                self.dist[key] = math.inf    # restante tem distância infinita
            self.ant[key] = None
            self.visited[key] = False

        # Loop que implementa a dijkstra
        while not fila.empty():
            pair = fila.get()
            this_dist, this_key = pair[0], pair[1]

            if not self.visited[this_key]:
                self.visited[this_key] = True

                # se o vértice atual não tiver sucessores, ignora
                if not this_key in self.graph.keys():
                    continue

                connected = list(self.graph[this_key].items()) # lista de caminhos que saem da cidade atual (cidade, distância)
                for path in connected:
                    path_key = path[0]
                    path_dist = path[1]

                    # verifica se precisa atualizar a distância da cidade
                    if path_dist + this_dist < self.dist[path_key]:
                        self.dist[path_key] = path_dist + this_dist
                        self.ant[path_key] = this_key
                        fila.put((self.dist[path_key], path_key))

        # print('distancia', self.dist)
        # print('anterior:', self.ant)

    # Retorna uma lista com as chaves primárias, na ordem na entrada
    def get_keys(self):
        return (list(self.graph.keys()))

    def print_caminho(self, key):
        if self.ant[key] == None:
            return
        self.print_caminho(self.ant[key])
        print(" -->", key, end="")


    def print(self, orig):
        keys = self.get_keys()
        for key_dest in keys:
            if key_dest == orig:
                continue

            print(orig, "para", key_dest)
            print("\tDistancia:", str(self.dist[key_dest]) + ",0")
            print("\tCaminho:", end=" ")
            self.print_caminho(key_dest)
            print('')

    