#!/bin/bash
# 13000121058
arr=("$@")
n=$#
sum=0
for var in ${arr[@]}; do
	sum=$[ $sum + $var ]
done
echo "The sum of $n natural numbers is $sum"

