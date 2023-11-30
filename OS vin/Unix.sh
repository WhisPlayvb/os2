#!/bin/bash

i="y"
while [ $i = "y" ]
do 
echo "- - - - - - - - - - - - - - - - - - - - - - - - - "
echo "1. Present working directory"
echo "2. List Files and directory"
echo "3. Create the directory" 
echo "4. Change the directory"
echo "5. Remove a file"
echo "6. Remove the directory"
echo "7. Rename the file"
echo "8. Create a file" 
echo "9. Display the contents of file"
echo "10. Copy the file "
echo "  "
echo "Enter your choice : "
read ch
echo "  "
case $ch in
      1)echo "Present working directory is : "
         pwd
         ;;
      2)echo "List of files and directories are displayed : "
         echo " "
         ls
         ;;
      3)echo "Enter the name of directory to be created : "
         read newdirname
         mkdir $newdirname
         ;;
      4)echo "To change the directory"
         echo "Enter the directory name : "
         read chgdirname
         cd $Schgdirname
         ;;
      5)echo "Enter the name of file to be removed : "
         read rfname
         rm $rfname
         ;;
      6)echo "Enter the name of directory to be removed : "
         read rdir
         rmdir $rdir
         ;;
      7)echo "Enter the name of file : "
         read fname
         echo "Enter the new file name : "
         read nfname
         mv $fname $nfname
         ;;
      8)echo "Enter the name of file to be create : "
         read filname 
         touch $filname
         ;;
      9)echo "Enter the name of file to be display : "
         read dfname
         cat $dfname
         ;;
    10)echo "Enter the name of file to be copy : "
         read cfname 
         echo "Enter the location : " 
         read locname
         cp $cfname  $locname
         ;;
      *)
         echo "Invalid choice"
         ;;
esac

echo " "
echo "Do you want to continue, press 'y' : "
read i
if [  $i !=  "y" ]
then
      exit
fi 
done

