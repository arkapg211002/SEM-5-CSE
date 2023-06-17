## Useful Vim commands

| Commands | Definition |
|:----|:---|
| vim | Start vim |
| i | Insert mode for inserting text |
| Esc key | To go to command mode (default mode when vim opens) |
| :edit `filename.txt` | To create new file |
| :w (`:` refers to command line mode in vim)| To save the file |
| :q | To get out of the current window |
| :qa! | To get out of vim directly |
| vim -R `filename.txt` (write in terminal) | To open the file in read only mode |
| vim `filename.txt` (write in terminal) | To open file in normal mode |
| :wq | To save and close |
| :help | To open help window in vim |
| :help `topic name` | To open help for particular topic if the topic name is known |
| :helpgrep `name` | To open help if topic name is not known |
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
| /`type expression` | searches the expression in the current file |
| n | searches the next occurences of the searched expression |
| N | searches the previous occurences of the searched expression |
| * | place the cursor under a word and type * . All the occurences of the word gets highlighted |
| :vimgrep `expression` *.txt | finds all the occurrences of the expression in all the files |
| :cn | go to next expression |
| :cN | go to previous expression |
| :badd `filename` | to add a file to the buffer of current vim session |
| :bN | To switch files that are in the buffer. N represnts the Nth file in the buffer. The first file that you open using `vim filename` or `:edit filename` is assigned number 1 in the buffer | 
| :bnext | move to next file in the buffer list |
| :bprevious | move to previous file in the buffer list |
| :buffers | list all the buffers |
| :ball | load all the buffers |
| :tabnew `file name` | Open new tab in the existing vim session |
| :tabnext | move to the next tab |
| :tabprevious | move to previous tab |
| :tabclose | close current tab |
| :tabfirst | move to first tab |
| :tablast | move to last tab |
| :new `filename` | open file in new window in the same vim sessoin |
| Folding functions in programs | Useful when there are multiple long functions.`:set foldenable` and `:set foldmethod=indent` to enable folding in the current file. `zo` to open folding.`zc` to close folding. `zR` to open all foldings |
