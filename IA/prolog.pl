likes(john, mary).
likes(mary, skiing).
likes(john, skiing).
likes(john, flowers).
likes(mary, surprises).

likes(mary, food).
%likes(ana, food).
%likes(john, food).

likes(ana, X) :- likes(X, flowers).

likes(_, food).

area_circulo(Raio, Area) :- Area is Raio*Raio*3.14.

% ------------------------ 

% listas
% [Head|Rest]


% função find:

find(Y,[Y|_]).
% ou:
% find(Y, [H|_]) :- Y = H

find(Y, [_|R]) :- find(Y,R).


% função tamanho:

tam([], T) :- T=0.
tam([_|R], T) :- tam(R, T1), T is T1 + 1. 

% o professor passou uma segunda forma de fazer:
% entender isso aqui!!

tam2([H|T], N) :- tam2([H|T], 0, N).
tam2([], N, N).
tam2([H|T], Ac, N) :- 
    NAc is Ac + 1,
    tam2(T, NAc, N).





