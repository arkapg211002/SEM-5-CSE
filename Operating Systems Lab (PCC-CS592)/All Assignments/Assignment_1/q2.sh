#!/bin/bash
# Write a shell script to determine whether a given year is a leap year or not.
read -p "Enter the year : " Y
if echo $Y | grep -qE '^[-+]?[0-9]+$' ; then
	if [ $Y -ge 0 ]; then
		if [ `expr $Y % 400` -eq 0 ]; then
			echo "$Y is leap year"
		elif [ `expr $Y % 100` -eq 0 ]; then 
			echo "$Y is not leap year"
		elif [ `expr $Y % 4` -eq 0 ]; then
			echo "$Y is leap year"
		else 
			echo "$Y is not leap year"
		fi
	else
		echo "$Y is not a year"
	fi
else
	echo "$Y is not a year"
fi


