#!/bin/bash

number1=$1
number2=$2

if ((number1 > number2)); then
	echo "the first number, $number1 is the most great"
elif ((number1 == number2)); then
	echo "$number1 and $number2 are equals"
else 
	echo "the second number, $number2 is the most great "
fi



