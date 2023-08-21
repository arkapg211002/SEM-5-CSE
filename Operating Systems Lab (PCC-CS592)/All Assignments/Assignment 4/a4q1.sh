#!/bin/bash
#13000121058



if [ "$#" -ne 1 ]; then
	exit
fi

file=$1


add()
{
	read -p "Enter the name : " name
	read -p "Enter roll number : " roll
	read -p "Enter the phone number : " phn
	read -p "Enter the address : " adr
	echo "$name|$roll|$phn|$adr" >> "$file"
}

while true ; do
	echo "1. Add details"
	echo "2. Sort records in reverse order according to roll number "
	echo "3. Replace lower case with upper case "
	echo "4. Find records with unique number "
	echo "5. Display 2nd and 3rd line "
	echo "6. exit"
	echo
	read ch
	if [ -z "$file" ]; then
		echo "$file is empty. No tasks can be performed"
		exit
	fi
	case "$ch" in
		1) 
			add
			;;
		2)
			sort -t'|' -k2 -nr "$file" > Sorted.dat
			;;
		3)
			tr [:lower:] [:upper:] < Sorted.dat > SortedUpper.dat
			mv SortedUpper.dat Sorted.dat
			;;
		4)
			sort -t'|' -u -k1,1 Sorted.dat >> "$file"
			;;
		5)
			newfile="p.dat"
			sed -n '2,3p' "$file" > "$newfile"
			if [ -z $newfile ]; then
				echo "File has less than 3 lines"
			else
				cat "$newfile"
			fi
			;;
		6)
			exit
			;;
		*)
			echo "Invalid choice"
			;;
	esac
done

