elemento(X, [H|T]) :- X = H.
elemento(X, [H|T]) :- elemento(X, T).

% É como se eu tivesse definindo o meu "resultado"; definindo o que deve ser verdade.
append([X|Xs], Y, [X|Zs]) :- append(Xs, Y, Zs).
append([], X, X).

origem(pt(X,Y)) :- X=0,Y=0.
dentro(pt(X,Y), R) :- X*X + Y*Y < R*R.

lista(
entrada(joao, 6041,
    entrada(jose, 4967,
        entrada(maria, 4454,
            entrada(rita, 4967, vazio))))
).

procure(entrada(Nome1, Num1, Resto), Nome, Num) :- Nome1 = Nome, Num1 = Num.
procure(entrada(Nome1, Num1, Resto), Nome, Num) :- procure(Resto, Nome, Num).

% Grafo
aresta(a, b).
aresta(b, c).
aresta(c, d).

conectado(A, C) :- aresta(A, C).
conectado(A, C) :- 
    conectado(A, B),
    aresta(B, C).

conectado(A, C) :- aresta(A, C).
conectado(A, C) :- 
    aresta(A, B),
    conectado(B, C).