-module(fizz_buzz_test).

-compile(export_all).
-import(fizz_buzz, [play/1]).

-include_lib("eunit/include/eunit.hrl").

rule1_3_test() ->
    io:format("~p~n", game:play([3])).
   % ?assertEqual(["Fizz"], game:play([3])).

rule1_5_test() ->
    ?assertEqual(["Buzz"], game:play([5])).

rule1_7_test() ->
    ?assertEqual(["Whizz"], game:play([7])).
