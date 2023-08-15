#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <MarksFile>"
    exit 1
fi

marks_file="$1"

if [ ! -f "$marks_file" ]; then
    echo "Error: Marks file '$marks_file' not found."
    exit 1
fi

# Calculate the highest total marks and the student name using awk
highest_student=$(awk -F'~' '
    NR == 1 {
        max = $3 + $4 + $5
        student = $1
    }
    
    NR > 1 && $3 + $4 + $5 > max {
        max = $3 + $4 + $5
        student = $1
    }
    
    END {
        print student
    }
' "$marks_file")

if [ -n "$highest_student" ]; then
    echo "Student with the highest total marks: $highest_student"
else
    echo "No student records found in the file."
fi

