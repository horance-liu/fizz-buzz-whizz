-module(fizz_buzz).
-export([play/1]).

times(N) -> 
    fun(X) -> (X rem N) =:= 0 end.

contains(N) -> 
    fun(X) -> lists:member(N, integer_to_list(X)) end.

rule(Pred, Action) -> 
    fun(N) ->
       case Pred(N) of
            true  -> { true, Action(N)};
            false -> false
       end
    end.

'OR'([])    -> fun(_) -> false end;
'OR'([H|T]) ->
    fun(N) ->
        case H(N) of
            {true, A1} -> {true, A1};
            false      -> ('OR'(T))(N)
        end
    end.

'AND'(Rules) ->
    'AND'(Rules, fun(A1, A2) -> A1 ++ A2 end, "").

'AND'([], _, Acc) -> fun(_) -> {true, Acc} end;
'AND'([H|T], Op, Acc) ->
    fun(N) ->
        case H(N) of
            {true, A} -> ('AND'(T, Op, Op(A, Acc)))(N); 
            false -> false
        end
    end.

play(L) ->
    R1_3 = rule(times(3), fun(_) -> "Fizz"  end),
    R1_5 = rule(times(5), fun(_) -> "Buzz"  end),
    R1_7 = rule(times(7), fun(_) -> "Whizz" end),

    R1 = 'OR'([R1_3, R1_5, R1_7]),
   
    R2 = 'OR'(['AND'([R1_3, R1_5, R1_7]),
               'AND'([R1_3, R1_5]),
               'AND'([R1_3, R1_7]),
               'AND'([R1_5, R1_7])]),
   
    R3 = rule(contains(3), fun(_) -> "Fizz" end),
    Rd = rule(fun(_) -> true end, fun(N) -> N end),
    Spec = 'OR'([R3, R2, R1, Rd]),
    
    [Spec(I) || I <- L].
