#!/bin/sh

STRT_STYLE="\033[0;32m"
END_STYLE="\033[0m"

log(){
    printf "\n${STRT_STYLE}$@${END_STYLE}\n"
}

execute_speed_test(){
    time > /dev/null 2>&1 "$1"
}

make fclean > /dev/null
make
make clean > /dev/null
make std_containers STD=1

mkdir -p out
./ft_containers > out/ft_containers.txt
./std_containers > out/std_containers.txt

log "comparing outputs:\n"
diff -s out/ft_containers.txt out/std_containers.txt

log "ft_container time execution:"
execute_speed_test ./ft_containers

log "std_container time execution:"
execute_speed_test ./std_containers
