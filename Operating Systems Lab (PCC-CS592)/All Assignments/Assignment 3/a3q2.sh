#!/bin/bash
# 13000121058
datafile="personal.dat"
personal()
{
	read -p "Enter name : " name
	read -p "Enter roll number : " roll
	echo "Enter password : "
	read -s pass
	echo "$name $roll $pass" >> datafile
}

showdata()
{
	echo "Enter password : "
	read -s p
	if [ $(grep -c $p datafile) -ne 0 ]; then
		awk -v pattern="$p" '$3 ~ pattern {print $1" "$2}' datafile
	else
		echo "details not found"
	fi
}

while true ; do
	echo "1. Enter personal details"
	echo "2. Show details"
	echo "3. Exit"
	read ch
	case "$ch" in
		1) personal ;;
		2) showdata ;;
		3) exit ;;
		*) echo "Invalid choice" ;;
	esac
done



	
