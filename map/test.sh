#!/bin/sh

mkdir -p out
./ft_map > out/ft_map.txt
./std_map > out/std_map.txt
diff -s out/ft_map.txt out/std_map.txt