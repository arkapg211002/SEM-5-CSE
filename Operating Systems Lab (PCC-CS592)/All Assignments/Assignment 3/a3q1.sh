#!/bin/bash
# 13000121058

show_permissions()
{
	read -p "Enter the path of the file or directory : " fd
	if [ -e $fd ]; then
		ls -l $fd | awk '{print $1}'
	else
		echo "$fd does not exist"
	fi
}

show_count()
{
	filecount=$(find . -maxdepth 1 -type f | wc -l)
	directorycount=$(find . -maxdepth 1 -type d | wc -l)
	echo "Total number of files $filecount"
	echo "Total number of directroies $directorycount"
}

show_lastmod()
{
	read -p "Enter the filename : " fn
	if [ -e $fn ]; then
		ls -l $fn | awk '{print $8}'
	else
		echo "$fn does not exist"
	fi
}

while true ; do
	echo "1. Show file permissions"
	echo "2. Show count of files and directories"
	echo "3. Show last modification time of file"
	echo "4. Exit"
	read ch
	case "$ch" in
		1) show_permissions ;;
		2) show_count ;;
		3) show_lastmod ;;
		4) echo "Exit from switch" ; exit ;;
		*) echo "Invalid choice" ;;
	esac
done


