chessboard(N) :-
    between(1, N, I),
    print_row(I, N),
    nl,
    fail.
chessboard(_).


print_row(I, N) :-
    between(1, N, J),
    X is (I + J) mod 2,
    write(X),
    fail.
print_row(_, _).

countHorses(N, Result) :-
    N2 is N * N,
    (   N2 mod 2 =:= 0
    ->  Result is N2 / 2
    ;   Result is (N2 - 1) / 2
    ).

start(N):-
    chessboard(N), countHorses(N, Horses), write('horses = '),write(Horses).
