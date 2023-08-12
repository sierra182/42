#!/bin/bash
set -e

name=$1

if [[ "$name" =~ ^[[:alpha:]]+$ ]]; then
	
echo "Bonjour, $name"

else 

	echo "no character given!" >&2 
	exit 1
fi
