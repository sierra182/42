#!/bin/bash

log_file=$1

if [ -f "$log_file" ]; then
	
	if [[ "$log_file" =~ .+\.log$ ]]; then

		grep ERROR "$log_file"

	else
		echo "the file extension is not valid!" >&2
		exit 1
	fi

else
	echo "the file does not exist!" >&2
	exit 1
fi
