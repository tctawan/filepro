#!/bin/bash

csv=$1

for list in $(cat $1); do
firstname=$(echo $list | cut -d',' -f1)
lastname=$(echo $list | cut -d',' -f2)
year=$(echo $list | cut -d',' -f3 | cut -c-4)
if [ $year -le 2000 ]; then
	echo "Dear Mr/Mrs $lastname, $firstname"
fi 
done
