#!/bin/bash


log_file=$1

if [[ -f "$log_file" && "$log_file" =~ .+\.log$ ]]; then
	
	cut -d' ' -f1 "$log_file" | sort | uniq -c
else

	echo "the file doesnot exist or do not have the correct extension '.log'" >&2
	exit 1
fi
