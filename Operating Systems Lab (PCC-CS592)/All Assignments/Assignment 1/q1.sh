#!/bin/bash

# 13000121058

read -p "Enter the number : " n
p=1
a=$n
while [ $n -gt 0 ]; do
	p=$[ $p * n ]
	n=$[ $n - 1 ]
done
echo "The factorial of $a is $p"

