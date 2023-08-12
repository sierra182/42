#!/bin/bash

word_to_replace=$1
new_word=$2
file_path=$3

sed "s/$word_to_replace/$new_word/" $file_path  
