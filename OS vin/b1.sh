#!/bin/bash
echo "Enter Filename"
read file_name
if [ -e $file_name ]
   then
   echo $file_name ": File Exist"
   if [ -s $file_name ]
      then
      echo $file_name ": File has size > 0"
   else
      rm $file_name
      echo $file_name ": File is Deleted which has size = 0"
   fi
else
   echo $file_name ": File does not exist" 
fi 

