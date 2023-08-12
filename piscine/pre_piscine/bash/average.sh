#!/bin/bash

file_path=$1

awk '{sum+=$1} END {average=sum/NR; printf "the average is:%.2f\n", average}' "$file_path"
