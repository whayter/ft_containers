#!/bin/sh

make fclean
make
make clean
make std_containers STD=1

mkdir -p out
./ft_containers > out/ft_containers.txt
./std_containers > out/std_containers.txt
diff -s out/ft_containers.txt out/std_containers.txt