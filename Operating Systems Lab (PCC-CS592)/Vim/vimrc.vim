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
set nowrap
set mouse=a
set ttymouse=xterm2
set t_Co=256
"set background=light
"colorscheme PaperColor
colorscheme=challenger_deep
set termguicolors
set path+=**
set wildmenu
syntax on
filetype on
"if !has('gui_running') && &term =~ '\%(screen\|tmux\)'
"  let &t_8f = \<Esc>[38;2;%lu;%lu;%lum
"  let &t_8b = \<Esc>[48;2;%lu;%lu;%lum
"endif
"set termguicolors
