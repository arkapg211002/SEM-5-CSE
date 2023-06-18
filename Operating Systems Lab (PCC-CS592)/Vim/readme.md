## To upgrade vim to version 9.0
https://itsfoss.com/install-latest-vim-ubuntu/

## My simple vimrc
```vim
set number
set incsearch
set hlsearch
set nocompatible
set autoindent
set smartindent
set smarttab
set history=1000
set encoding=UTF-8
set ruler
set cursorline
set mouse=a
colorscheme sublimemonokai
syntax on
filetype on
```

## Colorscheme I use as a beginner
https://github.com/arkapg211002/SEM-5-CSE/blob/main/Operating%20Systems%20Lab%20(PCC-CS592)/Vim/sublimemonokai.vim

To add sublimemonokai follow [Step 4](https://www.geeksforgeeks.org/customising-vim-from-scratch-without-plug-ins/)

## Terminal in Vim (version above and from 8.0)
```vim
"open terminal on the right
:bel vert term

"to scroll in the terminal
"place the cursor in the terminal then press the following keys
"Ctrl + w , Shift + n

"to use mouse in the terminal
:set mouse=a

```

## Useful Vim commands

| | Commands | Definition |
|:--|:----:|:---|
|1| vim | Start vim |
|2| i | Insert mode for inserting text |
|3| Esc key | To go to command mode (default mode when vim opens) |
|4| :edit `filename.txt` | To create new file |
|5| :w (`:` refers to command line mode in vim)| To save the file |
|6| :q | To get out of the current window |
|7| :qa! | To get out of vim directly |
|8| vim -R `filename.txt` (write in terminal) | To open the file in read only mode |
|9| vim `filename.txt` (write in terminal) | To open file in normal mode |
|10| :wq | To save and close |
|11| :colorscheme `ctrl+d` | List the available themes in vim |
|12| :help | To open help window in vim |
|13| :help `topic name` | To open help for particular topic if the topic name is known |
|14| :helpgrep `name` | To open help if topic name is not known |
|15| a | To open append mode, enter text after the cursor |
|16| A | To append at the end of the line and enter insert mode |
|17| o | To open new line after the current line |
|18| s | Substitute -> Delete the current character under the cursor and enter insert mode |
|19| cc | Similar to substitute. Deletes the entire line and enters the insert mode |
|20| r | Replace the character under the cursor , doesnt enter into insert mode |
|21| R | Enter into REPLACE mode |
|22| J | To join two text lines. Place the cursor after line 1 of the 2 lines and type J |
|23| h | To move cursor left |
|24| l | To move cursor right |
|25| k | To move cursor up |
|26| j | To move cursor down |
|27| nj | n represents any line number. nj moves directly down to that n th line |
|28| nk | move to n th line upwards |
|29| 0 | move to beginning of current line |
|30| $ | move to the end of the current line |
|31| ctrl f | scroll down to end |
|32| ctrl b | scroll up to beginning |
|33| :$ | move to the end of the file |
|34| :0 | move to the beginning of the file |
|35| w | move to beginning of the next word |
|36| b | move to beginning of the previous word |
|37| e | move to end of the current word |
|38| x | delete character from the cursor position |
|39| X | delete previous character from the cursor psoition |
|40| y | copy character from the cursor position |
|41| yy | copy entire line |
|42| p | paste character at the current cursor position |
|43| P | paste character before the cursor position |
|44| dw | delete the current word where cursor is |
|45| dd | delete entire line |
|46| D | delete entire line from the cursor position |
|47| u | undo |
|48| :red | redo |
|50| /`type expression` | searches the expression in the current file |
|51| n | searches the next occurences of the searched expression |
|51| N | searches the previous occurences of the searched expression |
|52| * | place the cursor under a word and type * . All the occurences of the word gets highlighted |
|53| :vimgrep `expression` *.txt | finds all the occurrences of the expression in all the files |
|54| :cn | go to next expression |
|55| :cN | go to previous expression |
|56| :badd `filename` | to add a file to the buffer of current vim session |
|57| :bN | To switch files that are in the buffer. N represnts the Nth file in the buffer. The first file that you open using `vim filename` or `:edit filename` is assigned number 1 in the buffer | 
|58| :bnext | move to next file in the buffer list |
|59| :bprevious | move to previous file in the buffer list |
|60| :buffers | list all the buffers |
|61| :ball | load all the buffers |
|62| :tabnew `file name` | Open new tab in the existing vim session |
|63| :tabnext | move to the next tab |
|63| :tabprevious | move to previous tab |
|64| :tabclose | close current tab |
|65| :tabfirst | move to first tab |
|66| :tablast | move to last tab |
|67| :new `filename` | open file in new window in the same vim sessoin |
|68| Folding functions in programs | Useful when there are multiple long functions.`:set foldenable` and `:set foldmethod=indent` to enable folding in the current file. `zo` to open folding.`zc` to close folding. `zR` to open all foldings |
|69| vim -d `file1.txt` `file2.txt` | to show the difference between two files (terminal command) |
|70| :diffsplit `file2.txt`| (vim command line) to show horizontally the differnce of `file1`(already open) with `file 2` |
|71| :vert diffsplit `file2.txt`| (vim command line) to show differences vertically |
|72| :term | to open terminal in vim (default version of vim that is installed along with ubuntu has unscrollable terminal) |
|73| :below terminal | To open terminal below |
|74| :below vertical terminal | to open terminal on the right side of the window |
|75| :colorscheme `ctrl d` | To get list of available inbuilt colorschemes for vim |
|76| :hi CursorLine ctermbg=Grey | To set current cursor line as grey highlight | 
