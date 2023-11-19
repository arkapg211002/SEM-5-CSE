#!/bin/bash

while true ; do
	echo
	echo "1) Sort in reverse order according to roll number"
	echo "2) Replace lower case with the upper case letters"
	echo "3) Records with unique name"
	echo "4) Display the 2nd 3rd line"
	echo

	read -p "Enter choice : " ch
	sed -n '2,$p' Students.dat > Student.dat
	case "$ch" in
		1)	sort -t'|' -k2 -nr Student.dat > Sorted.dat
			echo "The Records sorted"
			echo "Sorted.dat created"
			echo
			cat Sorted.dat
			;;
		2)	tr [:lower:] [:upper:] < Sorted.dat > Converted.dat
			mv Converted.dat Sorted.dat
			echo "Changes done"
			echo "Sorted.dat file is as follows now"
			echo
			cat Sorted.dat
			;;
		3)	sort -t'|' -u -k1,1 Sorted.dat
			echo
			sort -t'|' -u -k1,1 Sorted.dat >> Students.dat
			echo "Records with unique name appended"
			echo "Students.dat now"
			echo
			cat Students.dat
			;;
		4)	if [ $(cat Students.dat | wc -l) -lt 3 ];then
				echo "Students.dat has less than 3 lines"
			else
				sed -n '2,3p' Students.dat
			fi
			;;
		*)	echo "Invalid Choice"
			read -p "Want to exit? yes / no : " choice
			if [ $choice = "yes" ];then
				exit
			fi
			;;
	esac
done

