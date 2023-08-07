#!/bin/bash
# 13000121058

swap()
{
	local temp=${arr[$1]}
	arr[$1]=${arr[$2]}
	arr[$2]=$temp
}

quick()
{
	local last left right
	left=$1
	right=$2
	if [ $left -ge $right ]; then
		return
	fi
	last=$left
	swap "$left" "$(( (left + right)/2 ))"
	for (( i=left+1; i<=right; i++)); do
		if [ ${arr[$left]} -gt ${arr[$i]} ];then
			last=$[ $last + 1 ]
			swap "$i" "$last"
		fi
	done
	swap "$last" "$left"
	quick "$left" "$(( last - 1 ))"
	quick "$((last + 1))" "$right"
}

arr=("$@")
len=${#arr[@]}
quick "0" "$((len-1))"
echo "The sorted array is ${arr[@]}"

