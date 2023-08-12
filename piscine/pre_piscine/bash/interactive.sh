#!/bin/bash

echo "please enter the text:"

read user_input

if [[ -z "$user_input" ]]; then

	echo "no text given!" >&2
	exit 1
fi

if [[ "$user_input" =~ ^[[:digit:]]+$ ]]; then
	echo "the input must contain at least one letter." >&2
	exit 1
fi

echo "${user_input^^}"
