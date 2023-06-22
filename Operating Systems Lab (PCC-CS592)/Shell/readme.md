## Useful shell commands

| | Commands | Use |
|:--|:--:|:--|
|| <b>Introduction</b> ||
|1| passwd | To change password |
|2| ls | list all files and directories. `sudo apt install tree` -> `tree` command lists all files and directories in the form of tree |
|3| whoami | tells user name |
|4| users | lists the users logged into the system |
|5| who | lists the users logged into the system |
|6| w | gives details of the users logged into the system |
|7| logout | system `cleans up` and `breaks` up the connection |
|8| poweroff | shuts down the system by powering off |
|9| reboot | reboot/restart the system |
|10| shutdown | shuts down the system |
|| <b>File Management</b> ||
|11| ls -l | List all files with their `type,permission,memory blocks taken,user,group,file size,date created/modified,file name`|
||| `-` indicates rgular files |
||| `b` indicates block special files |
||| `d` indicates directories |
||| `c` indicates character special files |
||| `l` symbolic link files ,links on any files |
||| `p` indicates `process` for interprocess communication |
||| `s` indicates `sockets` for interprocess communication |
|12| `*` (metacharacter) | To list files that has more than one charcaters in common |
|13| `?` (metacharacter) | To list files by matching a single character |
|14| ls -a | Lists all the files including the hidden files. Hidden files start with `.` (period character) |
|15| vim `filename` | To create file |
|16| cat `filename` | Show the content of file in the terminal |
|17| echo `filename` | Show the name of the file in the terminal |
|18| cat `-b` `filename` | To show the content of the file along with line numbers |
|19| wc `filename` | First column shows the number of lines in the file. Second column shows the number of words in the file. Third column shows the number of bytes taken by the file. Fourth column shows the name of the file |
|20| cp `source file` `destination file` | To copy contents of source into destination file |
|21| mv `old filename` `new filename` | renames the file |
|22| rm `filename` | removes the file |
|23| rm `-i` `filename` | shows the file type while removing. Type `y` `enter` to confirm removing |
|24| touch `filename` | To create empty file |
|| <b>Directory Management</b> ||
|25| cd `~` | Go to home directory |
|26| cd `~username` | Go to any other user's home directory |
|27| pwd | shows the path where you are in |
|28| cd `-` | Go to the last vdirectory you were in |
|29| ls `directory name` | List all files in a directory |
|30| mkdir `directory name` | To create directory |
|31| rmdir `directory name` | To remove directory |
|32| mv `old directory` `new directory` | Rename directory |
|33| cd `.` | Shows the current directory you are in |
|34| cd `..` | Goes to the parent directory |
|| <br>Permissions</br> ||
|35| chmod | Change the modes or permissions of files and directories |
||| `chmod` can be used in `symbolic mode` and `absolute mode`. In symbolic mode, `+` is used to add permissions, `-` is used to remove permissions, `=` is used to set permissions |
|36| chmod `user type` `operator` `permissions`  `filename` | `user type` can have `u` for user, `o` for other users, `g` for group. `operator` can have `+`,`-`,`=`. `permissions` can have `r` for read, `w` for write, `x` for execute. For example: `chmod u+rwx filename.txt`,`chmod g=rx filename.txt` |
|37| chown `user` `filename` | Change ownership of `filename` to `user` |
|38| chgrp `group` `filename` | Change ownership of `filename` to `group` |
|39| sudo addgroup `group name` Add new group |
|40| sudo adduser `user` `group name` | Add `user` to group `group name` |
|| <b>Environment</b> ||
|41| `variable` | To store any value |
|42| echo $`variable` | To display the variable |
|43| echo $PWD | gives current working directory |
|44| echo $RANDOM | Generates a random integer between 0 and 32,767 each time it is referenced |
|45| echo $TERM | Refers to the display type |
|46| echo $TZ | Gives the timezone |
|47| echo $UID | Expands to the numeric user ID of the current user, initialized at the shell startup |
|48| grep `pattern` `files` | searches for a pattern in the files |
|49| sort `filename` | sorts the lines of the file alphabetically or numerically. sort `-r` `filename` reverses the order in which the lines of the file are sorted |
|50| sort +x `filename` | sorts the lines of the file ignoring the first x lines |
|51| ls `-l` l `more` | `more` is used not to display long list of files all at once, shows `--MORE--` at the end of screen. Type any key to display the reminaing list. Press `Q` to come out of `--MORE--` list. l is the pipe | 
|52| command `&` | To run a background process |
|53| ps | List all the processes that are running |
|54| ps -f | Lists all the processes that are running with more details |
|55| kill `PID` | terminate a process by giving its PID |
|56| top | shows information about physical and virtual memory, CPU usage, load averages, and your busy processes |
|57| ping `hostname` | get the ip address and see how the host responds. Type `Ctrl + C` to come out of ping command |
|58| finger | The finger command displays information about users on a given host. `sudo apt install finger` if `finger` not present |
|| <b>Shell Scripting</b> ||
|59| read `variable` | input value to variable |
|60| readonly `variable` | make the variable only readonly, no furthur input possible |
|61| unset `variable` | unset the variable from the list of variables that the shell tracks |
|62| echo $$ | process id of the current script |
|63| $* | takes the entire list as one argument |
|64| $@ | takes the entire list and seperates them into arguments |
|65| $? | gives the exit status of the previous run command. Tells whether it was successful or not |
|66| `array name`=(`valeu1`...`value n`) | declare array |
|67| ${array_name[index]} | access array elements |
|68| `${array_name[*]}` `${array_name[@]}` | Access all the elements of the array |







