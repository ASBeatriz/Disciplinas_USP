% caminho do cavalo

delta(2, 1).
delta(-2, 1).
delta(-2, -1).
delta(2, -1).
delta(1, 2).
delta(-1, 2).
delta(-1, -2).
delta(1, -2).

pode_ir([X1, Y1], [X2, Y2]) :-
    delta(Dx, Dy),
    X2 is Dx+X1, X2 < 9, X2 > 0,
    Y2 is Dy+Y1, Y2 < 9, Y2 > 0.

caminho_cav(I,F,C):-
    caminho_cav1(F,[I],C).


caminho_cav1(X,[X|L],[X|L]).

caminho_cav1(F,[C|Cs],Cam):-
    pode_ir(C,P),
    not(member(P,Cs)),
    caminho_cav1(F,[P,C|Cs],Cam).

% atravessar o rio (BFS?)

% auxiliares
inverte([],B,B).
inverte([H|T],Ac,B):- inverte(T,[H|Ac],B).

inverte(A,B):- inverte(A,[],B).

show([]).
show([A|R]):-
    writeln(A),
    show(R).

% implementação
plano(O,D,Pl) :-
    plano2([[O]],D,P),
    inverte(P,Pl),
    show(Pl).


plano2([[D|C]|_],D,[D|C]).