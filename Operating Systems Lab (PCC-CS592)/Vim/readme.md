## Learn Vim
https://www.tutorialspoint.com/vim/index.htm </br>
https://drive.google.com/file/d/10xnekN1o_JFprBa10NXjTteDAqgcbcZf/view?usp=drivesdk

## To upgrade vim to version 9.0
https://itsfoss.com/install-latest-vim-ubuntu/

## A simple .vimrc
```vim
set number
set autoindent
set smartindent
set smarttab
set history=1000
set mouse=a
set ttymouse=xterm2
set t_Co=256
set path+=**
set wildmenu
set showtabline=2
set laststatus=2
set cursorline
set cursorlineopt=number
colorscheme torte
hi CursorLineNr cterm=NONE ctermbg=235 ctermfg=DarkRed
hi LineNr ctermbg=235 ctermfg=LightGrey

```
## Add any external colorscheme
https://github.com/arkapg211002/SEM-5-CSE/blob/main/Operating%20Systems%20Lab%20(PCC-CS592)/Vim/sublimemonokai.vim

To add sublimemonokai follow [Step 4](https://www.geeksforgeeks.org/customising-vim-from-scratch-without-plug-ins/)

## Terminal in Vim (version above and from 8.0)
```vim
" open terminal on the right
:bel vert term

" to scroll in the terminal
" place the cursor in the terminal then press the following keys
" Ctrl + w , Shift + n

" to use mouse in the terminal
:set mouse=a

" to come out of the scroll mode
" place the cursor in the terminal at the end and type
i

" to exit terminal type and enter
exit

"in vim version 8.0
" to exit terminal type and enter
exit
:q 
```
## PaperColor light and dark colorscheme
https://github.com/NLKNguyen/papercolor-theme/blob/master/colors/PaperColor.vim

![5](https://github.com/arkapg211002/SEM-5-CSE/blob/main/Operating%20Systems%20Lab%20(PCC-CS592)/Vim/screenshots/5.png)

## Vim setup without plugins
![no plugins](https://raw.githubusercontent.com/arkapg211002/SEM-5-CSE/main/Operating%20Systems%20Lab%20(PCC-CS592)/Vim/screenshots/2023-06-28%20(1).png)

## NERDTree file structure

https://github.com/preservim/nerdtree
```
git clone https://github.com/preservim/nerdtree.git ~/.vim/pack/vendor/start/nerdtree
vim -u NONE -c "helptags ~/.vim/pack/vendor/start/nerdtree/doc" -c q
```
Additions in .vimrc
```
" Start NERDTree and leave the cursor in it.
autocmd VimEnter * NERDTree
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
" If another buffer tries to replace NERDTree, put it in the other window, and bring back NERDTree.
autocmd BufEnter * if bufname('#') =~ 'NERD_tree_\d\+' && bufname('%') !~ 'NERD_tree_\d\+' && winnr('$') > 1 |
    \ let buf=bufnr() | buffer# | execute "normal! \<C-W>w" | execute 'buffer'.buf | endif
" Open the existing NERDTree on each new tab.
autocmd BufWinEnter * if getcmdwintype() == '' | silent NERDTreeMirror | endif
```
To open/refresh NERDTree file structure `:NERDTree` </br>
To close `:q`

## Vim devicons and NERDFont
[Vim devicons](https://github.com/ryanoasis/vim-devicons) </br>
[NERDFonts](https://github.com/ryanoasis/nerd-fonts#font-installation)
### How to get vim devicons 
https://youtu.be/4KdAqsU7E-M

## Some helpful plugins
1. https://github.com/vim-airline/vim-airline
2. https://github.com/godlygeek/tabular/tree/master
3. https://vimawesome.com/plugin/undotree-vim
4. https://vimawesome.com/plugin/comfortable-motion-vim
5. https://vimawesome.com/plugin/vim-signify
6. https://github.com/skywind3000/vim-quickui/tree/master
7. https://vimawesome.com/plugin/minimap-vim-hard-things
8. https://vimawesome.com/plugin/indentline

Other plugins: https://vimawesome.com/

## Vim setup with plugins 

![Vimspace with plugins](https://github.com/arkapg211002/SEM-5-CSE/blob/main/Operating%20Systems%20Lab%20(PCC-CS592)/Vim/screenshots/2023-06-21%20(4).png)

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
|41| yy | copy entire line. To copy multiple lines place the cursor from where you want to copy and then press nyy where n is the number of lines you want to copy. To copy in a range go to command line mode and type `:a,by` where a is the starting line number and b is the ending line number|
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
|77| :print | To print file from vim |
|78| :hardcopy `filename.ps` | Convert whole file in current vim window to postscript file |
|79| :sp | Horizontal split |
|80| :vsp | vertical split |
|81| :set ttymouse=xterm2 | to resize split screens using mouse |
|82| :set termguicolors | Set terminal to express colors like gVim |
|83| `Shift`+`→` | To scroll right relatively faster |
|84| `Shift`+`←` | To scroll left relatively faster |
|85| :bd `filename` | To delete any file from the buffer |
|86| `Ctrl + w` `any arrow key` | To move between the split screens |
|87| :set `laststatus`=2 | To see the status line |
|88| :Explore | To see the file tree structure |
|89| :Sexplore | To open file tree structure horizontally |
|90| :Vexplore | To open file tree structure vertically |
|91| :Rexplore | To go back to file tree structure from the file that was opened from the tree |
|92| :Lexplore | To open file tree on the left |
|93| :Lexplore! | To open the file tree on the right |
|94| :Ntree `directory name` | To change the tree top to the directory under the cursor. Go to the `..` at the top and press enter to change the current directory to the parent |

## Copy paste in vim
### Within vim
Go to command line mode 
`:a,by` where a and b are the starting and ending line numbers
`p` to paste

### Paste the text in vim that is copied from outside vim
`Shift + Insert`

### Copy in vim and paste outside vim
```
:bel term
gedit filename.extension
```
Gedit opens copy and paste outside vim where you want 

## To print source code file as pdf from vim and terminal
In terminal
```
sudo apt install ghostscript
```

In vim convert the source code file to postscript file
```
:hardcopy > filename.ps
```

In terminal
```
ps2pdf filename.ps filename.pdf
```

To open pdf file from terminal
```
sudo apt install xdg-utils
xdg-open filename.pdf
```
## Customize bash shell
https://www.linuxfordevices.com/tutorials/linux/beautify-bash-shell

## Adding zsh and customizing
https://youtu.be/yJpj33Jtpd0

## To know and change default shell
```
# To see the current shell
echo $SHELL

# To list the shells
cat /etc/shells

# To change default shells
chsh
# Then give the path of the shell you want
```
