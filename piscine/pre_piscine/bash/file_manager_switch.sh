#!/bin/bash

command_name=$1
file_name=$2

create() {

	if [ -f "$1" ]; then

		echo "the file all ready exist!"
		return 1
	else		
		touch "$1"		
		return 0
	fi
}

delete() {
	
	if [ -f "$1" ]; then
	
		rm "$1"	
		return 0
	else 
		echo "the file does not exist!"
		return 1
	fi
}

move() {
	
	if [ -f "newCreatedDir/$1" ]; then

		echo "the file already exist in destination!"
		return 1
	fi

	if [ -f "$1" ]; then

		mkdir -p newCreatedDir
		mv "$1" newCreatedDir/"$1"
		return 0
	else
		echo "the file do not exist!"
		return 1
	fi
}

case "$command_name" in

	create)

		create "$file_name"

		if [ "$?" -eq 0 ]; then
		
			echo "the file was created with succes!"

		else 
			echo "there was an error in create." >&2
		fi
		;;
	delete)
		
		delete "$file_name"

		if [ "$?" -eq 0 ]; then
		
			echo "the file was deleted with succes!"

		else 
			echo "there was an error with delete..."
		
		fi
		;;				
	move)
	
		move "$file_name"

		if [ "$?" -eq 0 ]; then
		
			echo "the file was moved with succes!"

		else
			echo "there was an error with move..."
		fi
		;;
	*)
		echo "there is no args!"
		exit 1
		;;
esac



	
