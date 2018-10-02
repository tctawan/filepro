#!/bin/bash

dir=$1
for file in $(find $1 -type f); do
	fw=$(cat $file | head -1 | awk '{print $1}')
	echo $fw
done
