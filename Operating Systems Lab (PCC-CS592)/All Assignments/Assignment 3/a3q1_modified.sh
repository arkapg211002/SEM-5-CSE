#!/bin/bash

show_permissions()
{
	read -p "Enter the name of file or directory : " name
	echo "The full path of the file is : "
	echo $PWD/"$name"
	if [ -f $PWD/"$name" ];then
		permissions=$(ls -l "$name" | cut -d' ' -f1 | cut -c2-10)
		echo "The permisions for '$name' is : $permissions"
	elif [ -d $PWD/"$name" ];then
		permissions=$(ls -ld "$name" | cut -d' ' -f1 | cut -c2-10)
		echo "The permissions for '$name' is : $permissions"
	else
		echo "'$name' does not exist"
	fi
}

count()
{
	numfiles=$(ls -l | grep -c "^-")
	numdir=$(ls -l | grep -c "^d")
	echo -e "\nIn $PWD\n"
	echo "The number of files is : $numfiles"
	echo "The number of directories is : $numdir"
}

showmod()
{
	read -p "Enter the name of file or directory : " name
	if [ -f $PWD/"$name" ]; then
		echo $(ls -l "$name" | cut -d' ' -f6-8)
	elif [ -d $PWD/"$name" ];then
		echo $(ls -ld "$name" | cut -d' ' -f6-8)
	else
		echo "'$name' is not present"
	fi
}

while true ; do
	echo
	echo "1) Show Permissions"
	echo "2) Count number of files and directories"
	echo "3) Show last modification time"
	echo "4) Exit"

	read -p "Enter choice : " ch
	case "$ch" in
		1) show_permissions ;;
		2) count ;;
		3) showmod ;;
		4) echo "Exiting from switch.."
		   exit ;;
		*) echo "Invalid choice"
	esac
done

