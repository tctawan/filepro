#!/bin/bash

ext=$1
dir=$2
for file in $(find $dir -type f -name "*.$ext" -printf "%f\n"); do
#	echo $file
	newname=$(echo $file | cut -d'.' -f 1)
#	echo $newname
	mv $dir/$file $dir/$newname
done
