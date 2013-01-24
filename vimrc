"<- Vim RC ->
"Sourced and edited from gtmanfred <http://code.gtmanfred.com/cgit/dotfiles.git/plain/vimrc>

"<- General Settings ->
filetype indent plugin on
set smartindent
set tabstop=3
set shiftwidth=3
set expandtab
set showcmd
set softtabstop=3
set number
set showmatch
set matchtime=1
set incsearch
set ignorecase
set smartcase
set backspace=2
set nocp 
set autoindent
set formatoptions=c,q,r,t
set ruler
set tags=./tags;/
set virtualedit=block
set tabpagemax=15
set scrolloff=3
set virtualedit=block
set foldmethod=syntax
set foldopen=all
set nocp
syntax on 
hi Normal ctermfg=NONE ctermbg=NONE cterm=NONE
map <F2> :call g:ClangUpdateQuickFix() <CR>

"<- Global Options ->
let g:netrw_http_cmd='curl'
let g:netrw_http_xcmd='-o'
let g:netrw_silent=1
let g:clang_library_path = "/usr/lib"
let g:clang_complete_copen=1

"<- AutoCmds ->
au BufRead,BufNew /tmp/mutt* so ~/.mutt/mutt.vim
au BufRead *.txt set tw=94
au BufWinLeave * silent! mkview
au BufWinEnter * silent! loadview
au BufNewFile *zshcle* setft=zsh
au BufWinEnter,BufRead,BufNewFile *.java set filetype=java makeprg=javamake ts=4 sw=4 noet
au BufNewFile,BufRead *.svg setf svg 
au BufReadPre *.pdf set ro nowrap
au BufReadPost *.pdf silent %!pdftotext "%" -nopgbrk -layout -q -eol unix -
au BufWritePost *.pdf silent !rm -rf ~/PDF/%
au BufWritePost *.pdf silent !lp -s -d pdffg "%"
au BufWritePost *.pdf silent !until [ -e ~/PDF/% ]; do sleep 1; done
au BufWritePost *.pdf silent !mv ~/PDF/% %:p:h
au BufNewFile,BufRead /etc/nginx/conf/* set ft=nginx
au BufReadPost ~/pastes/* noremap q <esc>:q!<esc>
au BufReadPost /tmp/* noremap q <esc>:q!<esc>
au BufRead,BufNewFile *systemd* set filetype=systemd
au BufWinEnter,BufRead,BufNewFile *.c set filetype=c ts=4 sw=4 noet
