
#!/bin/bash

zipfile=$1
to=$2

mkdir -p $to
unzip -d $to $zipfile
for file in $(find $to -type f ); do
#	echo $file
	mv $file $2
done

find -type d -empty -delete
