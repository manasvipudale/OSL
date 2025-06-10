#Name: Utkarsha Kakade
#PRN no: 72293279M

#Initialization :

name=-1
city=-1
code=-1
phn=-1
cnt=-1
ch=0


while [ $ch -ne 7 ]
do 
	echo "\n\tAddress Database\n\t------------------\n1. Create Database\n2. View database\n3. Insert a record"
	echo "4. Delete a record\n5. Search a record. \n6.Modify A Record.\n7.Exit.."
	echo "\nYour Choice : "
	read ch

	case $ch in

	1) 	#Creating the database :
		echo "\n Address Database : \nEnter the File Name : " #user input
		read fname
		touch $fname		#file creation  create a file

		echo "\nEnter the no. of records to be entered in the file $fname : "  #no of records
		read n
		i=$n
		
		while [ $i != 0 ]
		do
					
			echo "\nEnter Name : "
			read name
	
			echo "\nEnter city : "
			read city
			
			echo "\nEnter zipcode : "
			read code
				 
			echo "\nEnter moblie : " 
			read phn   

			echo "\n$name \t\t$city\t\t$code\t\t$phn"
			echo "\n$name \t\t$city\t\t$code\t\t$phn" >> $fname  #add record in file
			echo "\n Your data is stored in the file."

		i=`expr $i - 1`
		done
	;;

	2) 	#View database :
		echo "\n\t\tADDRESS DATABASE"
		echo "........................................................................................."
		echo "\nName\t\tCity\t\tZipcode\t\tMobile"
		echo "........................................................................................."
		cat $fname  #to display records
		echo "........................................................................................."
	;;	


	3) 
		echo "\nEnter Name : "
		read name

		echo "\nEnter City : "
		read city
		
		echo "\nEnter Zipcode : "
		read code
	
		echo "\nEnter Mobile : "
		read phn
			
		echo "\n$name\t\t$city\t\t$code\t\t$phn"
		echo "\n$name\t\t$city\t\t$code\t\t$phn" >> $fname  #add record into file
		echo "\n Your data is stored in the file."
		
		$n=`expr $n + 1`
		
	;;


	4)	#Delete :
		touch temp #another file
		echo "\nEnter the Name of the  record to be deleted : "  #user value
		read no

		if grep -w "$no" $fname #-W Select  only  those  lines  containing  matches  that form whole      words. 
		then
			grep -w -v "$no" $fname >> temp   
			rm $fname  #martching record deleted
			mv temp $fname  #non matching copied into original one
		else 
			echo "\nRecord not found.."
		fi
	;;

	
	5)	#Searching a record :
		echo "\nEnter the Name of the record to be displayed : "
		read no

		if grep  -w "$no" $fname
		then
			grep -w -v "$no" $fname >> temp
		else 
			echo "\nRecord not found.."
		fi
	;;

	6)  #Modify A Record:
		touch temp
		echo "\nEnter the Name of the student whose record is to be modified : "
		read name
		
		if grep -w "$name" $fname 
		then
		grep -w -v "$name" $fname >> temp
		echo "\nEnter Name : "
		read name

		echo "\nEnter City : "
		read city
		
		echo "\nEnter Zipcode : "
		read code
		
		echo "\nEnter Mobile : "
		read phn
		
		
		echo "\n$name\t\t$city\t\t$code\t\t$phn" >>temp
			
		echo "\n Your data is stored in the file."

		code=-1
		phn=-1
		fi

		rm $fname
		mv temp $fname

	;;

	7)	#Exit..
		echo Exitting from Program..
	;;
	esac
done
