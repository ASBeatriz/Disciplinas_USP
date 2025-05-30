import sys
from Graph  import Graph
    
entrada = sys.stdin.read()
graph = Graph(entrada)
cities = graph.get_keys()
for city in cities:
    graph.dijkstra(city)
    graph.print(city)
    print("---------------------------------------------")



