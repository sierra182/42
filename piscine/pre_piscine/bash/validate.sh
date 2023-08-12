#!/bin/bash

user_email=$1

if [[ "$#" -eq 0 ]]; then
	
	echo "there is no arguments!" >&2
	exit 1
fi

if [[ "$user_email" =~ ^[[:alnum:][:punct:]]+@[[:alnum:]._-]+\.[[:alnum:].]{2,}$ ]]; then

	echo "the mail is valid!"

else
	echo "the mail is not valid!" >&2
	exit 1
fi

exit 0
