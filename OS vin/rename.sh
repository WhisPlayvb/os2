#!/bin/bash
FILES=$(ls *.jpg)
DAY=$(date +%F)
for FILE in $FILES
   do
   mv $FILE $DAY-$FILE
done
