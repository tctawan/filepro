#!/bin/bash

ext=$1
dir=$2
for file in $(find $2 -type f -name "*.$1" -printf "%f\n"); do
#	echo $file
	newname=$(echo $file | cut -d'.' -f 1)
#	echo $newname
	mv $dir/$file $dir/$newname
done
