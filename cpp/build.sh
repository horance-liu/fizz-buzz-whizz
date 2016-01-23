#!/bin/bash

################################################################################
function on_fail
{
  if [ $? -ne 0 ]; then
    echo "$1 fail"
    exit 1
  fi
}

################################################################################
function start_exec
{
  echo -e "\033[0;35;1m*********************************************************************\033[0m"
  echo -e "\033[0;35;1mstart to $1 \033[0m"
}

################################################################################
function exec_on_fail
{
  start_exec "run $1"
  $1
  on_fail "run $1"
}

################################################################################
# comment CC/CXX if you select GCC/G++ default.
################################################################################
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

################################################################################
start_exec "generate makefile"
cmake -E make_directory build
cmake -E chdir build cmake -DCMAKE_BUILD_TYPE=Debug ..

################################################################################
exec_on_fail "cmake --build build"
exec_on_fail "build/fizz-buzz-whizz-test"
