"<- Vim RC ->
"Sourced and edited from gtmanfred <http://code.gtmanfred.com/cgit/dotfiles.git/plain/vimrc>

"<- General Settings ->
filetype indent plugin on
set smartindent softtabstop=4 tabstop=4 shiftwidth=4 expandtab
set showcmd
hi CursorLine   ctermbg=black cterm=NONE
hi CursorColumn ctermbg=black
hi ColorColumn  ctermbg=black
hi SpecialKey   ctermfg=darkgrey
hi NonText      ctermfg=darkgrey
set cursorline cursorcolumn colorcolumn=80
set number relativenumber
set lazyredraw
set hlsearch showmatch
set matchtime=1
set incsearch
set ignorecase smartcase
set backspace=2
set nocompatible
set autoindent
set formatoptions=c,q,r,t
set ruler
set background=dark
set virtualedit=block
set tabpagemax=15
set scrolloff=3
set foldmethod=syntax
set encoding=utf-8
set laststatus=2
set clipboard=unnamedplus
syntax on
let g:rst_syntax_code_list=['c', 'lua', 'haskell']
runtime! ftplugin/man.vim

set encoding=utf-8
set listchars=tab:│•,eol:$,space:␣
nnoremap <C-w> :set list!<CR>

nnoremap <C-p> :set paste!<CR>

"<- Global Options ->
let g:clang_library_path = "/usr/lib"
let g:clang_complete_copen=1

"<- Airline ->
let g:airline_powerline_fonts = 1
let g:airline_theme = 'murmur'
let g:airline#extensions#tabline#enabled = 1

"<- vimpager ->
let vimpager_passthrough = 0

"<- AutoCmds ->
au BufRead,BufNew /tmp/mutt* set tw=79
au BufNewFile *zshcle* setft=zsh
au BufNewFile,BufRead *.svg setf svg
au BufReadPre *.pdf set ro nowrap
au BufReadPost *.pdf silent %!pdftotext "%" -nopgbrk -layout -q -eol unix -
au BufWritePost *.pdf silent !rm -rf ~/PDF/%
au BufWritePost *.pdf silent !lp -s -d pdffg "%"
au BufWritePost *.pdf silent !until [ -e ~/PDF/% ]; do sleep 1; done
au BufWritePost *.pdf silent !mv ~/PDF/% %:p:h
au BufRead,BufNewFile *systemd* set filetype=systemd

highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
au BufWinEnter * match ExtraWhitespace /\s\+$/
au InsertEnter * match ExtraWhitespace /\s\+\%#\@<!$/
au InsertLeave * match ExtraWhitespace /\s\+$/
au BufWinLeave * call clearmatches()

"<- Keybinds ->
map <Esc><Esc> :w<CR>
nnoremap ZO <C-w>o
nnoremap <Leader>h :set hls!<CR>
nnoremap <C-t> :vsp<CR>
nnoremap <C-o> :sp<CR>
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>w
nnoremap <C-k> <C-w>W
nnoremap <C-l> <C-w>l
