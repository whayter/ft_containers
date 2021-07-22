#!/bin/sh

mkdir -p out
./ft_vector > out/ft_vector.txt
./std_vector > out/std_vector.txt
diff -s out/ft_vector.txt out/std_vector.txt