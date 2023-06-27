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
colorscheme monokai 
set termguicolors
set path+=**
set wildmenu
set wildmode=longest:full,full
set showcmd
syntax on
filetype on
filetype plugin on

" Statusline
set laststatus=2
set statusline=
set statusline+=%7*
set statusline+=%9*
set statusline+=%7*
set statusline+=%7*
set statusline+=|
set statusline+=\ 
set statusline+=%{StatuslineMode()}
set statusline+=\ 
set statusline+=|
set statusline+=%3*
set statusline+=|
set statusline+=\ 
set statusline+=%m
set statusline+=\ 
set statusline+=%r
set statusline+=\ 
set statusline+=|
set statusline+=%4*
set statusline+=|
set statusline+=\ 
set statusline+=%f
set statusline+=\ 
set statusline+=\ 
set statusline+=/
set statusline+=\ 
set statusline+=%y
set statusline+=\ 
set statusline+=/
set statusline+=\ 
set statusline+=%{&ff}
set statusline+=\ 
set statusline+=/
set statusline+=\ 
set statusline+=%{strlen(&fenc)?&fenc:'none'}
set statusline+=\ 
set statusline+=|
set statusline+=%=
set statusline+=%3*
set statusline+=|
set statusline+=\ 
set statusline+=%F
set statusline+=\ 
set statusline+=|
set statusline+=\ 
set statusline+=%2*
set statusline+=%5*
set statusline+=%5*
set statusline+=%5*
set statusline+=%5*
set statusline+=%4*
set statusline+=%P
set statusline+=\ 
set statusline+=|
set statusline+=\ 
set statusline+=%l
set statusline+=/
set statusline+=%L
set statusline+=\ 
set statusline+=|
set statusline+=\ 
set statusline+=:
set statusline+=%c
set statusline+=\ 
set statusline+=|
set statusline+=%1*
set statusline+=%{strftime(\"%H:%M\")}
set statusline+=%1*
set statusline+=|
set statusline+=%6*
set statusline+=|
set statusline+=\ 
set statusline+=%n
set statusline+=\ 
set statusline+=|
hi User7 ctermbg=cyan ctermfg=black guibg=cyan guifg=black
hi User9 ctermbg=black ctermfg=white guibg=black guifg=white
hi User3 ctermbg=lightblue ctermfg=black guibg=lightblue guifg=black
hi User4 ctermbg=darkblue ctermfg=white guibg=darkblue guifg=white
hi User2 ctermbg=lightcyan ctermfg=black guibg=lightcyan guifg=black
hi User5 ctermbg=blue ctermfg=white guibg=blue guifg=white
hi User1 ctermbg=darkcyan ctermfg=white guibg=darkcyan guifg=white
hi User6 ctermbg=red ctermfg=white guibg=red guifg=white

function! StatuslineMode()
  let l:mode=mode()
  if l:mode==#"n"
    return "NORMAL"
  elseif l:mode==?"v"
    return "VISUAL"
  elseif l:mode==#"i"
    return "INSERT"
  elseif l:mode==#"R"
    return "REPLACE"
  elseif l:mode==?"s"
    return "SELECT"
  elseif l:mode==#"t"
    return "TERMINAL"
  elseif l:mode==#"c"
    return "COMMAND"
  elseif l:mode==#"!"
    return "SHELL"
  endif
endfunction

" File Structure
let g:netrw_banner = 0
let g:netrw_liststyle=3
let g:netrw_browse_split=4
let g:netrw_altv=1
let g:netrw_winsize=15


" If status line not working use below statusline
"set laststatus=2
"set statusline=
"set statusline+=%2*
"set statusline+=%{StatuslineMode()}
"set statusline+=%1*
"set statusline+=\ 
"set statusline+=<
"set statusline+=<
"set statusline+=\ 
"set statusline+=%f
"set statusline+=\ 
"set statusline+=>
"set statusline+=>
"set statusline+=%=
"set statusline+=%m
"set statusline+=%h
"set statusline+=%r
"set statusline+=\ 
"set statusline+=%3*
"set statusline+=%{b:gitbranch}
"set statusline+=%1*
"set statusline+=\ 
"set statusline+=%4*
"set statusline+=%F
"set statusline+=:
"set statusline+=:
"set statusline+=%5*
"set statusline+=%l
"set statusline+=/
"set statusline+=%L
"set statusline+=%1*
"set statusline+=|
"set statusline+=%y
"set statusline+=%2*
"set statusline+=\ 
"set statusline+=%{strftime(\"%H:%M\")}
"set statusline+=%2*
"hi User2 ctermbg=lightgreen ctermfg=black guibg=lightgreen guifg=black
"hi User1 ctermbg=black ctermfg=white guibg=black guifg=white
"hi User3 ctermbg=black ctermfg=lightblue guibg=black guifg=lightblue
"hi User4 ctermbg=black ctermfg=lightgreen guibg=black guifg=lightgreen
"hi User5 ctermbg=black ctermfg=magenta guibg=black guifg=magenta

"function! StatuslineMode()
"  let l:mode=mode()
"  if l:mode==#"n"
"    return "NORMAL"
"  elseif l:mode==?"v"
"    return "VISUAL"
"  elseif l:mode==#"i"
"    return "INSERT"
"  elseif l:mode==#"R"
"    return "REPLACE"
"  elseif l:mode==?"s"
"    return "SELECT"
"  elseif l:mode==#"t"
"    return "TERMINAL"
"  elseif l:mode==#"c"
"    return "COMMAND"
"  elseif l:mode==#"!"
"    return "SHELL"
"  endif
"endfunction

"function! StatuslineGitBranch()
"  let b:gitbranch=""
"  if &modifiable
"    try
"      let l:dir=expand('%:p:h')
"      let l:gitrevparse = system("git -C ".l:dir." rev-parse --abbrev-ref HEAD")
"      if !v:shell_error
"        let b:gitbranch="(".substitute(l:gitrevparse, '\n', '', 'g').") "
"      endif
"    catch
"    endtry
"  endif
"endfunction

"augroup GetGitBranch
"  autocmd!
"  autocmd VimEnter,WinEnter,BufEnter * call StatuslineGitBranch()
"augroup END


