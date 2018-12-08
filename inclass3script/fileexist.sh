#!/bin/bash

filename=$1
if [ -f $1 ]; then
	echo "File found"
else
	echo "File is not found"
fi
