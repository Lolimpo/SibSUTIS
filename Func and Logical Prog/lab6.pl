% 1
f1([],_,_,L1,L2,L3):-writeln(L1),
                    writeln(L2),
                    writeln(L3),!.
f1([H|T],A,B,L1,L2,L3):-H>B,
                       append(L3,[H],LR),
                       f1(T,A,B,L1,L2,LR).
f1([H|T],A,B,L1,L2,L3):-H>=A,
                        H=<B,
                        append(L2,[H],LR),
                        f1(T,A,B,L1,LR,L3).
f1([H|T],A,B,L1,L2,L3):-H<A,
                        append(L1,[H],LR),
                        f1(T,A,B,LR,L2,L3).
goal1:-write('[L]. A. B.-?'),
       read(L),
       read(A),
       read(B),
       (A>B,f1(L,B,A,[],[],[]);
       A<B,
       f1(L,A,B,[],[],[])).

% 2
f2([],_,LM,_):-writeln(LM),!.
f2([H|T],M,LM,P):-H=:=M,
                  P1 is P + 1,
                  append(LM,[P],LR),
                  f2(T,M,LR,P1).
f2([H|T],M,LM,P):-H<M,
                 P1 is P + 1,
                 f2(T,M,LM,P1).
f2([H|T],M,_,P):-H>M,
                 P1 is P + 1,
                 f2(T,H,[P],P1).
goal2:-write('[L].-?'),
       read([H|T]),
       f2([H|T],H,[],1).

% 3
maxel([],_,LM):-write(' '),
                writeln(LM),!.
maxel([[H,X]|T],M,LM):-X=:=M,
                       append([H],LM,LR),
                       maxel(T,X,LR).
maxel([[_,X]|T],M,LM):-X<M,
                       maxel(T,M,LM).
maxel([[H,X]|T],M,_):-X>M,
                      maxel(T,X,[H]).

% func
f3([],L):-  writeln(L),
            write('Count: '),
            writeln(L),
          maxel(L,-1,[]),!.
f3([H|T],L):-not(member([H,_],L)),
             f3(T,[[H,1]|L]).
f3([H|T],L):-member([H,X],L),
             X1 is X + 1,
             delete(L,[H,X],LN),
             f3(T,[[H,X1]|LN]).

goal3:-write('[L].-?'),
       read(L),
       f3(L,[]).
