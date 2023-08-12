#!/bin/bash

args_array=("$@")
sum=0
max_int=1000

if [[ "$#" -lt 2 ]]; then # Check if there is no minimum args

	echo "two arguments minimums needed." >&2
	exit 1
fi

for arg in "${args_array[@]}"; do
	
	if ! [[ $arg =~ ^-?[0-9]+$ ]]; then # Check if arg is a number

		echo "$arg is not an integer." >&2 
		exit 1
	fi
	
	if [[ $arg -lt -$max_int || $arg -gt $max_int ]]; then # Check if arg is out of range -max_int to +max_int
	 	
		echo "$arg is not in the range -$max_int to $max_int." >&2
		exit 1
	fi

	((sum += arg))
done

echo "the sum is $sum."

exit 0
