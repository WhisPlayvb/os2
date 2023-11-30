echo "Enter Filename : "

read file



if [ -e $file ]

then

	echo "File Exist"

	temp_file=$(mktemp)

	sort -u $file > $temp_file

	mv $temp_file $file

	echo "Duplicate lines removed from "$file

else

	echo "File not Exist"

fi