parent('John', 'Bob').
parent('Mary', 'Bob').
parent('Mary', 'Ann').
parent('Bob', 'Liz').
parent('Bob', 'Paul').
parent('Bob', 'Sam').
parent('Paul', 'Pat').
male('John').
male('Bob').
male('Paul').
male('Sam').
female('Mary').
female('Ann').
female('Liz').
female('Pat').

father(X,Y):-parent(X,Y),male(X).
mother(X,Y):-parent(X,Y),female(X).
brother(X,Y):-male(X),parent(Z,X),parent(Z,Y), X \= Y.
sister(X,Y):-female(X), parent(Z,X),parent(Z,Y), X \= Y.
grandson(X,Y):-male(X),parent(Z,X),parent(Y,Z).
aunt(X,Y):-parent(Z,Y), sister(X,Z).
hastwochildren(X):-parent(X,Y), parent(X,Z), Y @> Z.
successor(X):-father(X,Y),male(Y), !.

/*
father(X, 'Sam').
mother(_,'Bob').
sister(X,'Sam').
sister(_,'Liz').
brother(X,'Bob').
grandson(X,'Mary').
grandson('Paul',X).
aunt(X,'Sam').
 brother(X,'Ann');sister(X,'Ann'),parent(X,_).
hastwochildren(X).
successor('Bob').
*/
