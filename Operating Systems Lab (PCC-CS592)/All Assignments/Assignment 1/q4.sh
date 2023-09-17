#!/bin/bash
# write a shell script to generate fibonacci series up to Nth term where N is user input
read -p "Enter the term : " N
if [ $N -eq 0 ]; then
	echo "Enter positive term"
elif [ $N -eq 1 ]; then
	echo "0"
elif [ $N -eq 2 ]; then
	echo "0 1"
else
	A=0
	B=1
	echo -n "0 1 "
	while [ $N -ge 3 ]; do
		NEXT=`expr $A + $B`
		echo -n "$NEXT "
		A=$B
		B=$NEXT
		N=`expr $N - 1`
	done
	echo
fi

	

