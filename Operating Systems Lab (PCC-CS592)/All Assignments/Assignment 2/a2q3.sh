#!/bin/bash
#13000121058
if [ $(grep -c $1 /etc/passwd) -ne 0 ]; then
	echo "Valid user"
else
	echo "Not valid user"
fi
