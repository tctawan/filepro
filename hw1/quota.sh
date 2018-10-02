#!/bin/bash

dir=$1
du=$(du -ks $1 | cut -f1 )
if [ $du -lt 1000 ]; then
	echo "Low"
elif [ $du -lt 10000 ]; then 
	echo "Medium"
else
	echo "High"
fi
