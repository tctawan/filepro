#!/bin/bash


for p in $PWD/*; do
lp=$(basename $p)
if [ -f $lp ];then
echo $p
fi
done
