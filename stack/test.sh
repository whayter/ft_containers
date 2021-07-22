#!/bin/sh

mkdir -p out
./ft_stack > out/ft_stack.txt
./std_stack > out/std_stack.txt
diff -s out/ft_stack.txt out/std_stack.txt