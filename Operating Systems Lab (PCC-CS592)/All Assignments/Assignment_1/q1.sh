#!/bin/bash

# 13000121058

# Write a shell script to find out the factorial of a user given number.

P=1
read -p "Enter the number : " N
NUM=$N
while [ $N -gt 0 ]; do
	P=`expr $P \* $N`
	N=`expr $N - 1 `
done
echo "The factorial of $NUM is $P"

