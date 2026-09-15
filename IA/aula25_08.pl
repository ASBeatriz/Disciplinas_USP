% Tirei foto do que o prof colocou na lousa, no inicio da aula

% Função append
my_append([], L, L).
my_append([H|L1], L2, [H|L3]) :-
    my_append(L1, L2, L3).
    

% ...

% alcancavel e conectada
% ...