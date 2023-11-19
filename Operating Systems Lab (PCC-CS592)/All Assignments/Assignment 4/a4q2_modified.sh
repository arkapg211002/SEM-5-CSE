#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Insufficient Arguments"
	exit
fi

file="$1"
echo "The filename is : $file"

if [ -f "$file" ];then
	echo "File exists"
else
	echo "The file is empty"
	echo "NAME~ROLL~SUB1~SUB2~SUB3" > cat > "$file"
fi

add()
{
	read -p "Enter Name : " name
	read -p "Enter Roll Number : " roll
	read -p "Enter marks for Subject 1 : " a
	read -p "Enter marks for Subject 2 : " b
	read -p "Enter marks for Subject 3 : " c
	echo "$name~$roll~$a~$b~$c" >> "$file"
	echo "Data Added"
}

while true ; do
	read -p "Want to add to the file (yes / no) : " ch
	if [ $ch = yes ]; then
		add
	else
		break
	fi
done

