% aresta(Origem, Destino).

aresta(a, b).
aresta(a, c).

aresta(b, d).
aresta(b, e).

aresta(c, f).

%          a
%         / \
%        b   c
%       / \   \
%      d   e   f





% dfs(Inicio, Objetivo, Caminho)
%
% Encontra um caminho entre Inicio e Objetivo
% usando busca em profundidade.

dfs(Inicio, Objetivo, Caminho) :-
    dfs_aux(Inicio, Objetivo, [Inicio], Caminho).


% Caso base:
% chegamos ao objetivo.
%
% O caminho está sendo armazenado na ordem
% inversa, então fazemos reverse no final.

dfs_aux(Objetivo, Objetivo, Visitados, Caminho) :-
    reverse(Visitados, Caminho).


% Caso recursivo:
% 1. Escolhemos um vizinho do atual.
% 2. Verificamos que ele ainda não foi visitado.
% 3. Continuamos a busca a partir dele.

dfs_aux(Atual, Objetivo, Visitados, Caminho) :-
    aresta(Atual, Proximo),
    \+ member(Proximo, Visitados),
    dfs_aux(Proximo, Objetivo, [Proximo|Visitados], Caminho).










% filhos(Atual, Visitados, NovosCaminhos)
%
% Encontra todos os vizinhos de Atual que ainda
% não estão no caminho atual.

filhos(Atual, Visitados, NovosCaminhos) :-

    findall(
        [Proximo, Atual | Visitados],

        (
            aresta(Atual, Proximo),
            \+ member(Proximo, Visitados)
        ),

        NovosCaminhos
    ).

% bfs(Inicio, Objetivo, Caminho)
%
% A fila inicialmente contém um único caminho:
% [[Inicio]]
%
% Cada elemento da fila é um caminho completo.

bfs(Inicio, Objetivo, Caminho) :-
    bfs_aux([[Inicio]], Objetivo, Caminho).


% CASO BASE
%
% A fila possui um primeiro caminho:
%
% [Objetivo | Resto]
%
% Se o primeiro elemento desse caminho é o objetivo,
% encontramos a solução.

bfs_aux([[Objetivo|Resto]|_], Objetivo, Caminho) :-
    reverse([Objetivo|Resto], Caminho).


% CASO RECURSIVO
%
% Pegamos o primeiro caminho da fila.
%
% [Atual|Resto] é o caminho que estamos expandindo.
%
% Outros = os demais caminhos que já estavam na fila.

bfs_aux([[Atual|Resto]|Outros], Objetivo, Caminho) :-

    % Encontramos todos os novos caminhos possíveis
    % a partir de Atual.
    filhos(Atual, Resto, NovosCaminhos),

    % Colocamos os novos caminhos no FINAL da fila.
    append(Outros, NovosCaminhos, NovaFila),

    % Continuamos a busca.
    bfs_aux(NovaFila, Objetivo, Caminho).
