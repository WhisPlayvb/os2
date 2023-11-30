echo "Enter Filename"

read file

if [ -e $file ]

then

	echo "File Exist"

	if [ -s $file ]

	then

		echo "File not empty"

	else

		echo "File Empty"

		rm $file

		echo "File Deleted Successfully"

	fi

else

	echo "File not exist"

fi