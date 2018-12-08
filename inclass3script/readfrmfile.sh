#!/bin/bash

file=$1

if [ -f $file ]; then
	(while read l;do echo $l;echo;done)< $file
fi

