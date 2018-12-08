#!/bin/bash


file=$1
dest="${file%.*}.csv"
echo $dest
while read l ; do
	name=$(echo $l | cut -d":" -f1)
	cvnum=$(echo $l | grep -o "_[0-9]*.html" | sed -e "s/_\([0-9]*\)\.html/\1/")
	score=$(echo $l | cut -d" " -f3)
	echo "$name,$cvnum,$score" >> $dest
done < $file
