#!/bin/bash

# Change this to modify where the file is stored.
# For some reason, I needed to split this up??
FILE_DIR=$HOME
FILE_NAME=.install_log.txt

# Tests if file is created, if not, create it.
if [ ! -f $FILE_DIR/$FILE_NAME ]; then
  echo "File not found. Making file..."

  touch $FILE_DIR/$FILE_NAME
  echo "Done!"
fi

if [ "$#" -eq 0 ]; then
  echo "Correct usage: install_log.sh <package> <description>"
elif [[ $1 == "-l" ]]; then
  cat $FILE_DIR/$FILE_NAME
#elif []; then
else
  #DT=[[ date +"%Y-%m-%d %H:%M" ]]
  echo -n "$(date -I)" >>$FILE_DIR/$FILE_NAME
  echo " $1  : ${@:2}" >>$FILE_DIR/$FILE_NAME
  #date +"%Y-%m-%d %H:%M:%S" >>$FILE_DIR/$FILE_NAME
  #echo $1 >>$FILE_DIR/$FILE_NAME
  #echo ${@:2} >>$FILE_DIR/$FILE_NAME
  #echo >>$FILE_DIR/$FILE_NAME
fi
