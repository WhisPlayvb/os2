i="Y"

while [ $i="Y" ]

do

   echo "1.Show Present working Directory"
   echo "2.List Files in Directory"
   echo "3.Create Directory"
   echo "4.Change Directory"
   echo "5.Remove File"
   echo "6.Remove Directory"
   echo "7.Rename File"
   echo "8.Create File"
   echo "9.Display File"
   echo "10.Copy File"
   
   echo "Enter Your Choice:"
   read choice
   
   
   case $choice in
   
        1)echo "This is present working Directory"
         pwd
        ;;
        
        2)echo "List of Files in Current Directory"
        ls
        ;;
        
        3)echo "Enter Directory Name"
        read Dirnm
        mkdir $Dirnm
        ;;
        
        4)echo "Enter Path to Change Directory"
        read path
        cd $path
        ;;
        
        5)echo "Enter File name to Remove"
        read rmFile
        rm $rmFile
        ;;
        
        6)echo "Enter Directory Name to Remove"
        read rmDirnm
        rmdir $rmDirnm
        ;;
        
        7)echo "Enter File to Rename"
        read filen
        echo "Enter File New Name"
        read nfilen
        mv $filen $nfilen
        ;;
        
        8) echo "Enter File Name To Create New File"
        read filenamec
        touch $filenamec
        echo "File Create Successfully"
        ;;
        
        9)echo "Enter File Name To Display Text"
        read filenamed
        cat $filenamed
        ;;
        
        10)echo "Enter File To Be Copied"
        read sfile
        echo "Enter File name to be Copied In"
        read dfile
        cp $sfile $dfile
        ;;
    
        *)
   esac
  
  echo "Do tou want to Continue Y/N:"
  read i
  if [ $i != "Y" ]
  then 
       exit
  fi
  done
  
                
