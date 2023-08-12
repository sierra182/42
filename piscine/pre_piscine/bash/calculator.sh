#!/bin/bash

commandName=$1
numberOne=$2
numberTwo=$3

add() {

	echo $(( $1 + $2 ))
}

subtract() {
	
	echo $(( $1 - $2)) 
}

multiply() {

	echo $(( $1 * $2))
}

divide() {
	
	echo $(( $1 / $2))
}

main() {

	if [[ "$1" == "add" ]]; then
	
		result=$(add $2 $3)
		echo "the result is: $result"
        fi

	if [[ "$1" == "subtract" ]]; then
	
		result=$(subtract $2 $3)
		echo "the result is: $result"
	fi

	if [[ "$1" == "multiply" ]]; then
	
		result=$(multiply $2 $3)
		echo "the result is: $result"	
	fi

	if [[ "$1" == "divide" ]]; then
	
		result=$(divide $2 $3)
		echo "the result is: $result"
	fi
}

main $1 $2 $3 
