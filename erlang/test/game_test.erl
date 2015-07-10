-module(game_test).

-compile(export_all).
-import(game, [play/1]).

-include_lib("eunit/include/eunit.hrl").

rule1_3_test() ->
    ?assert(["Fizz"] =:= game:play([3])).

rule1_5_test() ->
    ?assert(["Buzz"] =:= game:play([5])).

rule1_7_test() ->
    ?assert([Whizz] =:= game:play([5])).
