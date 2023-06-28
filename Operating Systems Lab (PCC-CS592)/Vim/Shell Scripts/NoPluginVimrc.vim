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

" Tabs bar
hi TabLineSel ctermbg=darkcyan ctermfg=white guibg=darkcyan guifg=white
hi TabLine ctermbg=lightcyan ctermfg=black guibg=lightcyan guifg=black
hi TabLineFill ctermbg=grey ctermfg=white guibg=grey guifg=white
set showtabline=2
" Tab headings
"function GuiTabLabel()
"    let label = ''
"    let bufnrlist = tabpagebuflist(v:lnum)

    " Add '+' if one of the buffers in the tab page is modified
"    for bufnr in bufnrlist
"        if getbufvar(bufnr, "&modified")
"            let label = '+'
"            break
"        endif
"    endfor

    " Append the number of windows in the tab page if more than one
"    let wincount = tabpagewinnr(v:lnum, '$')
"    if wincount > 1
"        let label .= wincount
"    endif
"    if label != ''
"        let label .= ' '
"    endif

    " Append the buffer name (not full path)
"    return label . "%t"
"endfunction

"set guitablabel=%!GuiTabLabel()

set tabline=%!MyTabLine()  " custom tab pages line
function MyTabLine()
        let s = '' " complete tabline goes here
        " loop through each tab page
        for t in range(tabpagenr('$'))
                " set highlight
                if t + 1 == tabpagenr()
                        let s .= '%#TabLineSel#'
                else
                        let s .= '%#TabLine#'
                endif
                " set the tab page number (for mouse clicks)
                let s .= '%' . (t + 1) . 'T'
                let s .= ' '
                " set page number string
                let s .= t + 1 . ' '
                " get buffer names and statuses
                let n = ''      "temp string for buffer names while we loop and check buftype
                let m = 0       " &modified counter
                let bc = len(tabpagebuflist(t + 1))     "counter to avoid last ' '
                " loop through each buffer in a tab
                for b in tabpagebuflist(t + 1)
                        " buffer types: quickfix gets a [Q], help gets [H]{base fname}
                        " others get 1dir/2dir/3dir/fname shortened to 1/2/3/fname
                        if getbufvar( b, "&buftype" ) == 'help'
                                let n .= '[H]' . fnamemodify( bufname(b), ':t:s/.txt$//' )
                        elseif getbufvar( b, "&buftype" ) == 'quickfix'
                                let n .= '[Q]'
                        else
                                let n .= pathshorten(bufname(b))
                        endif
                        " check and ++ tab's &modified count
                        if getbufvar( b, "&modified" )
                                let m += 1
                        endif
                        " no final ' ' added...formatting looks better done later
                        if bc > 1
                                let n .= ' '
                        endif
                        let bc -= 1
                endfor
                " add modified label [n+] where n pages in tab are modified
                if m > 0
                        let s .= '[' . m . '+]'
                endif
                " select the highlighting for the buffer names
                " my default highlighting only underlines the active tab
                " buffer names.
                if t + 1 == tabpagenr()
                        let s .= '%#TabLineSel#'
                else
                        let s .= '%#TabLine#'
                endif
                " add buffer names
                if n == ''
                        let s.= '[New]'
                else
                        let s .= n
                endif
                " switch to no underlining and add final space to buffer list
                let s .= ' '
        endfor
        " after the last tab fill with TabLineFill and reset tab page nr
        let s .= '%#TabLineFill#%T'
        " right-align the label to close the current tab page
        if tabpagenr('$') > 1
                let s .= '%=%#TabLineFill#%999Xclose'
        endif
        return s
endfunction


"let g:rails_statusline=0
" Status line no plugin 
set laststatus=2
set statusline=
set statusline+=%6*
set statusline+=%1*
set statusline+=|
set statusline+=\ 
set statusline+=%{StatuslineMode()}
set statusline+=\ 
set statusline+=%m
set statusline+=\ 
set statusline+=%r
set statusline+=\ 
set statusline+=|
"set statusline+=%3*
"set statusline+=|
"set statusline+=\ 
"set statusline+=%f
"set statusline+=\ 
"set statusline+=|
set statusline+=%4*
set statusline+=|
set statusline+=\ 
set statusline+=%{expand(&filetype)}
set statusline+=\ 
set statusline+=%4*
set statusline+=\ 
set statusline+=|
set statusline+=%7*
set statusline+=|
set statusline+=\ 
set statusline+=%{strlen(&fenc)?&fenc:'none'}
set statusline+=\ 
set statusline+=/
set statusline+=\ 
set statusline+=Buffer:
set statusline+=%n
set statusline+=\ 
set statusline+=|
set statusline+=%=
set statusline+=%4*
set statusline+=|
set statusline+=\ 
set statusline+=%F
set statusline+=\ 
set statusline+=|
set statusline+=%3*
set statusline+=|
set statusline+=\ 
set statusline+=%P
set statusline+=\ 
set statusline+=%l
set statusline+=/
set statusline+=%L
set statusline+=\ 
set statusline+=:
set statusline+=%c
set statusline+=\ 
set statusline+=|
set statusline+=%2*
set statusline+=|
set statusline+=\ 
set statusline+=%{strftime('%F\ %H:%M\ %p')}
set statusline+=\ 
set statusline+=|
hi User6 ctermbg=cyan ctermfg=white guibg=cyan guifg=white
hi User1 ctermbg=darkblue ctermfg=white guibg=darkblue guifg=white
hi User3 ctermbg=lightblue ctermfg=black guibg=lightblue guifg=black
hi User4 ctermbg=darkcyan ctermfg=white guibg=darkcyan guifg=white
hi User7 ctermbg=grey ctermfg=black guibg=grey guifg=black
hi User2 ctermbg=blue ctermfg=white guibg=blue guifg=white

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
let g:netrw_banner=0
let g:netrw_liststyle=3
let g:netrw_browse_split=4
let g:netrw_altv=1
let g:netrw_winsize=15
let g:netrw_keepdir=0

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


