day=$(date +%F)



for file in *.jpg

do

	mv "$file" "$day-${file}"

done