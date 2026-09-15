% --------------------- LISTA ----------------------

% pertence
pertence(X, [X|_]).
pertence(X, [_|Ls]):-
    pertence(X, Ls).

% append
myappend([], X, X).
myappend([L|Ls], X, [L|R]) :- myappend(Ls, X, R).

% cardinalidade (nro de elementos)
cardinalidade([], 0).
cardinalidade([_|Ls], N):-
    cardinalidade(Ls, N1),
    N is N1 + 1.

    % outra forma (com recursão de cauda)
n_elementos([H|T], N) :- n_elementos([H|T], 0, N).

n_elementos([], N, N).
n_elementos([_|T], Ac, N):-
    NAc is Ac+1,
    n_elementos(T, NAc, N).


% remove uma ocorrência de X
remove(X, [X|R], R).
remove(X, [L|Ls], [L|R]) :- 
    remove(X, Ls, R).



aresta(a,b). aresta(a,c). aresta(a,d). aresta(a,e). aresta(d,j).
aresta(c,f). aresta(c,g). aresta(f,h). aresta(e,k). aresta(f,i).
aresta(x,y). aresta(y,z). aresta(z,x). aresta(y,u). aresta(z,v).

% a) escreva um predicado prolog conectado(No1, No2),
% que retorne verdadeiro se houver um caminho entre No1 e
% No2 no grafo.

conectado(N1, N2) :- aresta(N1, N2).
conectado(N1, N2) :-
    aresta(N1, N3),
    conectado(N3, N2).


% b) escreva um predicado que retorna um
% caminho entre dois nós, caminho(No1, No2,
% Caminho), usando busca em profundidade,
% evitando visitar um nó mais de uma vez.
caminho(N2, N2, Vis, Res) :- myappend(Vis, [N2], Res).

caminho(N1, N2, Vis, Cam) :-
    aresta(N1, N3),
    \+ pertence(N3, Vis),
    myappend(Vis, [N1], NewVis),
    caminho(N3, N2, NewVis, Cam).


% [] Entender a resolução das 8 rainhas



% [] Ver predicados auxiliares