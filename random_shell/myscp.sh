#!/bin/bash

filename=$1
if [ -f $1 ]; then
	echo "File found"
else
	echo "File is not found"
fi


find ~ -name "*.txt" -printf "%p\n"

for p in $PWD/*; do
lp=$(basename $p)
if [ -f $lp ];then
echo $p
fi
done

file2=$2

if [ -f $file2 ]; then
	(while read l;do echo $l;echo;done)< $file2
fi


find -printf "%s %p\n"
