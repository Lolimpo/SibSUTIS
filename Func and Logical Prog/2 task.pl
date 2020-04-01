use_module(library(clpfd)).
func(File):-
    open(File, read, Stream),
    read_line_to_string(Stream, String),
    split_string(String, " ", ",.", L),
    close(Stream),
    writeln(L),
    get_sizes(L, _, Sizes).
    

get_sizes([], _, Sizes):-
    writeln(Sizes),
    min_list(Sizes, Min, Pos),
    writeln(Min), writeln(Pos),
    open("text.txt", read, Stream),
    open("out.txt", append, Stream2),
    read_line_to_string(Stream, String),
    split_string(String, " ", ",.", L),
    nth0(Pos, L, Elem),
    writeln(Elem),
    writeln(Stream2, Elem),
    close(Stream), close(Stream2).
get_sizes([H|T], _, Sizes):-
    string_length(H, Len),
    append(Sizes, [Len], Res),
    get_sizes(T, _, Res).

min_list(Lst, Min, Ind) :-
   member(Min, Lst),
   \+((member(N, Lst), N < Min)),
   nth0(Ind, Lst, Min).