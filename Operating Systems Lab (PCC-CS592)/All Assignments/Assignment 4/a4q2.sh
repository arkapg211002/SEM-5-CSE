#!/bin/bash
# 13000121058

if [ "$#" -ne 1 ]; then
	echo "Insufficient Arguments"
	exit
fi

det=$1

if [ -z $det ]; then
	echo "Name~Roll~Subject_1~Subject_2~Subject_3" > "$det"
fi

add()
{
	read -p "Enter name : " name
	read -p "Enter Roll : " roll
	read -p "Enter marks for Subject_1 : " s_1
	read -p "Enter marks for Subject_2 : " s_2
	read -p "Enter marks for Subject_3 : " s_3
	echo "$name~$roll~$s_1~$s_2~$s_3" >> "$det"
}

in=1

while [ $in -gt 0 ] ; do
	read -p "Do you want to add more 1 for yes 0 for no : " ch
	if [ $ch -eq 1 ]; then
		add
	fi
	in=$ch	
done

# highest marks
hm=$(awk -F'~' '
NR == 1 {
	max = $3 + $4 + $5
	student = $1
}
NR > 1 && $3 + $4 + $5 > max {
	max = $3 + $4 + $5
	student = $1
}
END{
	print student
}
' "$det")

if [ -n "$hm" ] ; then
	echo "The student with highest marks is : $hm"
else
	echo "Student details not found"
fi

# Average marks
awk -F'~' 'NR >= 1 { total+=$3 } ;END { print "Average Marks for Subject_1 is", total/(NR-1) }' "$det"
awk -F'~' 'NR >= 1 { total+=$4 } ;END { print "Average Marks for Subject_2 is", total/(NR-1) }' "$det"
awk -F'~' 'NR >= 1 { total+=$5 } ;END { print "Average Marks for Subject_3 is", total/(NR-1) }' "$det"

# Highest in any of the subject
h1=$(awk -F'~' '
NR == 1 {
	max = $3
	student = $1
}
NR > 1 && $3 > max {
	max = $3
	student = $1
}
END {
	print student
}
' "$det")
echo "The student with the highest marks in Subject_1 is $h1"

h2=$(awk -F'~' '
NR == 1 {
	max = $4
	student = $1
}
NR > 1 && $4 > max {
	max = $4
	student = $1
}
END {
	print student
}
' "$det")
echo "The student with the highest in Subject_2 is $h2"

h3=$(awk -F'~' '
NR == 1 {
	max = $5
	student = $1
}
NR > 1 && $5 > max {
	max = $5
	student = $1
}
END {
	print student
}
' "$det")
echo "The student with the highest in Subject_3 is $h3"

