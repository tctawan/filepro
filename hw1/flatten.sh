
#!/bin/bash

zipfile=$1
to=$2

mkdir -p $2
unzip -d $2 $zipfile
for file in $(find $2 -type f ); do
#	echo $file
	mv $file $2
done

find -type d -empty -delete
