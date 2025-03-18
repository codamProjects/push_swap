#!/bin/bash

make re

END="\e[3;94m"
GREEN="\e[32m"
RED="\e[31m"
TEXT="\e[96m"
NOCOLOR="\e[0m"

UNAME="$(uname -s)"

if [[ "$UNAME" = "Linux" ]]; then
	OS="./checker_linux"
else
	OS="./checker_Mac"
fi

#check if there are 2 arguments
if [ "$#" -ne 2 ]; then
	printf "${TEXT}Need 2 ints as arguments${NOCOLOR}\n"
	exit 1
fi

#make of ints of those arguments
num1=$(( $1 + 0 ))
num2=$(( $2 + 0 ))

#check if the arguments are greater than 0
if ! [[ "$num1" =~ ^[1-9][0-9]*$ ]]; then
	printf "${TEXT}list size must be greater than 0${NOCOLOR}\n"
	exit 1
fi

if ! [[ "$num2" =~ ^[1-9][0-9]*$ ]]; then
	printf "${TEXT}#loops must be greater than 0${NOCOLOR}\n"
	exit 1
fi

#create list to fill with num1 integers, randomly genarated by a python script
#than run this list through push_swap, check it and print the result
#make until num2 more lists
declare -a lists
TOTAL_MOVES=0
TOTAL_SETS=0
MOST_MOVES=0
for ((i=0; i<$num2; i++)); do
	while true; do
		ARG=$(python my_num_list.py $num1)
		if [[ ! " ${lists[@]} " =~ " ${ARG} " ]]; then
			lists+=($ARG)
			break
		fi
	done
	OUTPUT=$(./push_swap $ARG)
	CHECK=$(./push_swap $ARG | $OS $ARG)
	OWN_CHECK=$(./push_swap $ARG | ./checker $ARG)
	MOVES=$(./push_swap $ARG | wc -l)
	if [ $MOVES -gt $MOST_MOVES ]; then
		let MOST_MOVES=$(( $MOVES ))
	fi
	let TOTAL_SETS=$(( TOTAL_SETS + 1 ))
	let TOTAL_MOVES=$(( TOTAL_MOVES + $MOVES ))
	if [[ "$CHECK" != "$OWN_CHECK" ]]; then
		printf "${TEXT}Checker ${RED}KO ${TEXT}"
	else
		printf "${TEXT}Checker ${GREEN}OK ${TEXT}"
	fi
	if [[ "$CHECK" = "OK" ]]; then
		printf "${TEXT}The result is ${GREEN}OK${TEXT}, and needed $MOVES moves.\n"
	elif [[ "$CHECK" = "KO" ]]; then
		printf "${TEXT}The result is ${RED}KO${TEXT}, and needed $MOVES moves.\n$OUTPUT\n $ARG"
		break
	else
		printf "$OUTPUT"
		break
	fi
done
AV_MOVES=$(( $TOTAL_MOVES / $TOTAL_SETS ))
printf "${END}\n$TOTAL_MOVES moves in $TOTAL_SETS sets\nAverage moves: $AV_MOVES\nMost moves needed: $MOST_MOVES\n${NOCOLOR}"


make fclean
