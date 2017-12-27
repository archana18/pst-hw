#!/bin/bash
chmod a+x trash.sh
mkdir -p TRASH
for FILE in $@
do 
	if [ -f $FILE  ]; then   
	if [[ "$FILE" != "hidden.o" ]] ; then
	if [[ "$FILE" != "bomb_defused.txt" ]] ; then
	if [[ "$FILE" != "program3B.c" ]] ; then
	if [[ "$FILE" != "Makefile" ]] ; then 
   			cp $FILE TRASH/
			rm $FILE
	fi
	fi
	fi
	fi
	else
  		echo "File $FILE does not exist."
	fi
done
find TRASH/ -type f -mmin +60 -delete

