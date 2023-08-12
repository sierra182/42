#!/bin/bash
set -e

dir_to_save="$1" 
backup_dir="./backupDirSave"
backup_timestamp=$(date +"%Y%m%d_%H%M%S")

if [[ "$#" -eq 0 ]]; then

	echo "directory is missing." >&2
	exit 1
fi

if ! [[ -d "$dir_to_save" ]]; then
	
	echo "the arg is not a directory" >&2
	exit 1
fi

if ! [[ -d "$backup_dir" ]]; then
	
	mkdir "$backup_dir"
	chmod 700 "$backup_dir"

	if [[ "$?" -ne 0 ]]; then

		echo "there was an error when create new directory." >&2
		exit 1
	else

		echo "the directory has been created with success!"
	fi
fi

diskfreespace=$(df "$backup_dir" | tail -1 | awk '{print $4}')
dir_to_save_size=$(du "$dir_to_save" -s | awk '{print $1}')

if [[ "$diskfreespace" -lt "$dir_to_save_size" ]]; then

	echo "not enought space on disk!" >&2
	exit 1
fi

cp -r "$dir_to_save" "$backup_dir"

if [[ "$?" -ne 0 ]]; then

	echo "there was an error when copy." >&2
	exit 1
fi 

find "$backup_dir" -type f -execdir bash -c 'mv "$1" "${1%.*}"'"_$backup_timestamp"'.${1##*.}' _ {} \;   

if [[ "$?" -ne 0 ]]; then

	echo "there was an error on search." >&2
	exit 1
fi

mv "${backup_dir}/${dir_to_save}" "${backup_dir}/${dir_to_save}_${backup_timestamp}"

exit 0
