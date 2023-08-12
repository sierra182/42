#!/bin/bash

result=$(find . -mtime 30)

if [[ -z "$result" ]]; then
	
	echo "no files found!"
else

	echo "$result"
fi
