#!/bin/bash
# 13000121058
# Write a shell script to find the sum of digits of a user supplied number . Also check for invalid user inputs and show appropriate error message

read -p "Enter the number : " N
if echo $N | grep -qE '^[-+]?[0-9]+$' ; then
	if [ $N -lt 0 ]; then
		N=`expr $N \* -1`
	fi
	SUM=0
	while [ $N -gt 0 ]; do
		REM=`expr $N % 10`
		SUM=`expr $SUM + $REM`
		N=`expr $N / 10`
	done
	echo "The sum of digits is $SUM"
else
	echo "Not a valid number"
fi

