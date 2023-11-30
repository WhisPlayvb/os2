Day=$(date +%F)

for FILE in *.png
do 
   mv "$FILE" "$Day-${FILE}"
done

