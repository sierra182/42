#!/bin/bash

command_entry=$1
file_name=$2

if  [[ $command_entry == "create" ]]; then
	
	touch $file_name

elif [[ $command_entry == "delete" ]] ; then

	rm $file_name

elif [[ $command_entry == "move" ]] ; then

	mkdir newDir
	mv $file_name newDir/$file_name 

fi

