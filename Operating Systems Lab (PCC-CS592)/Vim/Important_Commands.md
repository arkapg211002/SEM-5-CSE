## Useful Vim commands

| Commands | Definition |
|:----|:---|
| vim | Start vim |
| i | Insert mode for inserting text |
| Esc key | To go to command mode (default mode when vim opens) |
| :edit filename.txt | To create new file |
| :w (: refers to command line mode in vim)| To save the file |
| :q | To get out of the current window |
| :qa! | To get out of vim directly |
| vim -R filename.txt (write in terminal) | To open the file in read only mode |
| vim filename.txt (write in terminal) | To open file in normal mode |
| :wq | To save and close |
| :help | To open help window in vim |
| :help <topic name> | To open help for particular topic if the topic name is known |
| :helpgrep <name> | To open help if topic name is not known |
| a | To open append mode, enter text after the cursor |
| A | To append at the end of the line and enter insert mode |
| o | To open new line after the current line |
| s | Substitute -> Delete the current character under the cursor and enter insert mode |
| cc | Similar to substitute. Deletes the entire line and enters the insert mode |
| r | Replace the character under the cursor , doesnt enter into insert mode |
| R | Enter into REPLACE mode |
| J | To join two text lines. Place the cursor after line 1 of the 2 lines and type J |
| h | To move cursor left |
| l | To move cursor right |
| k | To move cursor up |
| j | To move cursor down |
| nj | n represents any line number. nj moves directly down to that n th line |
| nk | move to n th line upwards |
| 0 | move to beginning of current line |
| $ | move to the end of the current line |
| ctrl f | scroll down to end |
| ctrl b | scroll up to beginning |
| :$ | move to the end of the file |
| :0 | move to the beginning of the file |
| w | move to beginning of the next word |
| b | move to beginning of the previous word |
| e | move to end of the current word |
| x | delete character from the cursor position |
| X | delete previous character from the cursor psoition |
| y | copy character from the cursor position |
| yy | copy entire line |
| p | paste character at the current cursor position |
| P | paste character before the cursor position |
| dw | delete the current word where cursor is |
| dd | delete entire line |
| D | delete entire line from the cursor position |
| u | undo |
| :red | redo |

