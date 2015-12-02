"<- Vim RC ->
"Sourced and edited from gtmanfred <http://code.gtmanfred.com/cgit/dotfiles.git/plain/vimrc>

"<- General Settings ->
filetype indent plugin on
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set showcmd
set softtabstop=4
set cursorline
set cursorcolumn
hi CursorLine   ctermbg=black cterm=NONE
hi CursorColumn ctermbg=black
hi ColorColumn  ctermbg=black
set colorcolumn=80
set cuc cul
set number
set lazyredraw
set relativenumber
set hlsearch
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
set background=dark
set tags=./tags;/
set virtualedit=block
set tabpagemax=15
set scrolloff=3
set virtualedit=block
set foldmethod=syntax
set foldopen=all
set nocp
set encoding=utf-8
set laststatus=2
set clipboard=unnamedplus
syntax on
let g:rst_syntax_code_list=['c', 'lua', 'haskell']
hi Normal ctermfg=NONE ctermbg=NONE cterm=NONE
runtime! ftplugin/man.vim

"<- Colorizer ->
let g:colorizer_auto_filetype='css,html'

"<- neocomplete ->
let g:neocomplete#enable_at_startup = 1

"<- Global Options ->
let g:netrw_http_cmd='curl'
let g:netrw_http_xcmd='-o'
let g:netrw_silent=1
let g:clang_library_path = "/usr/lib"
let g:clang_complete_copen=1

"<- Airline ->
let g:airline_powerline_fonts = 1
let g:airline_theme = 'murmur'
let g:airline#extensions#tabline#enabled = 1

"<- AutoCmds ->
au BufRead,BufNew /tmp/mutt* so ~/.mutt/mutt.vim
au BufRead *.txt set tw=94
au BufWinLeave * silent! mkview
au BufWinEnter * silent! loadview
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
autocmd BufWinEnter * match ExtraWhitespace /\s\+$/
autocmd InsertEnter * match ExtraWhitespace /\s\+\%#\@<!$/
autocmd InsertLeave * match ExtraWhitespace /\s\+$/
autocmd BufWinLeave * call clearmatches()

"<- Keybinds ->
map <Esc><Esc> :w<CR>
