#!/bin/bash

students_file="Students.dat"

print_menu() {
    echo "Menu:"
    echo "1. Add more student records"
    echo "2. Sort records in reverse order of Roll number"
    echo "3. Replace lower case letters with upper case letters"
    echo "4. Find records with unique names and append them"
    echo "5. Display the 2nd and 3rd lines"
    echo "6. Exit"
}

add_student() {
    echo "Enter Name: "
    read name
    echo "Enter Roll: "
    read roll
    echo "Enter Phone: "
    read phone
    echo "Enter Address: "
    read address
    echo "$name|$roll|$phone|$address" >> "$students_file"
    echo "Student record added."
}

while true; do
    print_menu
    echo "Enter your choice: "
    read choice

    case $choice in
        1)
            add_student
            ;;
        2)
            sort -t'|' -k2 -nr "$students_file" > Sorted.dat
            echo "Records sorted by Roll number in reverse order."
            ;;
        3)
            tr 'a-z' 'A-Z' < "$students_file" > SortedUpper.dat
            mv SortedUpper.dat "$students_file"
            echo "Lower case letters replaced with upper case."
            ;;
        4)
            sort -t'|' -u -k1,1 "$students_file" > Unique.dat
	    mv Unique.dat "$students_file"
            echo "Records with unique names appended."
            ;;
        5)
            sed -n '2,3p' "$students_file"
            ;;
        6)
            echo "Exiting."
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a valid option."
            ;;
    esac
done

