echo "Enter Filename"
read filenm
if [ -e    $filenm ]
then
    echo $filenm "Exist"
    if [ -s $filenm ]
    then 
        echo $filenm "File size >0"
    else
         rm $filenm
         echo $filenm "File Deleted which has size 0"
    fi
else
    echo "File not exist"
    
fi
