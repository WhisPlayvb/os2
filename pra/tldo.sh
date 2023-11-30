echo "Enter filename"

read file



if [ -e $file ]; then

	echo "File exist"



	tmp_file=$(mktemp)

	echo "Enter first-level dir name : "

	read dir1



	echo "Enter second-level dir name : "

	read dir2



	sort -u $file > $tmp_file



	mkdir -p $dir1/$dir2



	mv $tmp_file $dir1/$dir2/"processed_file.txt"



	echo "Processed file moved to "$dir1/$dir2

else

	echo "File not exist"

fi