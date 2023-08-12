#!/bin/bash

if [ $# -eq 0 ]; then

	echo "no args to list!" >&2
	exit 1
else 
	for arg in "$@"
	do
	
		echo $arg
	done

	echo "there are $# arguments"
fi



