#<- ZSh RC ->

#<- Primary Options ->
HISTFILE=~/.zsh_hist
HISTSIZE=1000
SAVEHIST=1000
setopt appendhistory histignorealldups autocd notify
#setopt correctall
unsetopt beep
zstyle :compinstall filename '/home/halosghost/.zshrc'
zstyle ':completion:*' menu select
setopt completealiases
fpath=(~/.zsh/completion $fpath)
autoload -Uz compinit
autoload -U bashcompinit
autoload -U edit-command-line
zle -N edit-command-line
compinit
bashcompinit
export RPROMPT='%B%(?.%F{cyan}^_^%f.%F{red}o_O%f)%b' 
export PROMPT="╒[%~]%#
└╼ "
source $HOME/.zsh_env

#<- Keybinds ->
bindkey -M vicmd v edit-command-line
bindkey "^X" edit-command-line
typeset -A key

key[Home]=${terminfo[khome]}
key[End]=${terminfo[kend]}
key[Insert]=${terminfo[kich1]}
key[Delete]=${terminfo[kdch1]}
key[Up]=${terminfo[kcuu1]}
key[Down]=${terminfo[kcud1]}
key[Left]=${terminfo[kcub1]}
key[Right]=${terminfo[kcuf1]}
key[PageUp]=${terminfo[kpp]}
key[PageDown]=${terminfo[knp]}

[[ -n "${key[Home]}"    ]]  && bindkey  "${key[Home]}"    beginning-of-line
[[ -n "${key[End]}"     ]]  && bindkey  "${key[End]}"     end-of-line
[[ -n "${key[Insert]}"  ]]  && bindkey  "${key[Insert]}"  overwrite-mode
[[ -n "${key[Delete]}"  ]]  && bindkey  "${key[Delete]}"  delete-char
[[ -n "${key[Up]}"      ]]  && bindkey  "${key[Up]}"      up-line-or-history
[[ -n "${key[Down]}"    ]]  && bindkey  "${key[Down]}"    down-line-or-history
[[ -n "${key[Left]}"    ]]  && bindkey  "${key[Left]}"    backward-char
[[ -n "${key[Right]}"   ]]  && bindkey  "${key[Right]}"   forward-char

#<- Aliases ->
alias '..'='cd ..'
alias -g ...='../..'
alias -g ....='../../..'

alias la='ls -A'
alias ll='ls -lh'
alias lla='ls -lhA'

alias db='dropbox'
alias purl='db puburl'
alias ytdl='youtube-dl'

alias sudo='sudo '
alias grep='grep --color=auto'
alias ls='ls --color=auto -CF'
alias bc='bc -lq'
alias locate='locate -d /home/halosghost/.mlocate/mlocate.db'
alias matrix='cmatrix -f -l -a'
alias netctl='sudo netctl'
alias whereami='pwd -P'
alias cower='cower --color=always'
alias pacman='pacman --color=always'
alias keytest="xev | grep -A2 --line-buffered '^KeyRelease' | sed -n '/keycode /s/^.*keycode \([0-9]*\).* (.*, \(.*\)).*$/\1 \2/p'"
alias alsi='alsi -u -f $XDG_CONFIG_HOME/alsi/arch.logo'
alias count='wc -l'
alias sloc='cloc'
alias mplayer='mpv'

#<- Suffixes ->
alias -s pdf='zathura'
alias -s jpg='feh'
alias -s png='feh'
alias -s gif='mpv --loop=inf'
alias -s mp3='mpv'
alias -s avi='mpv'
alias -s flac='mpv'
alias -s webm='mpv'
alias -s mkv='mpv'
alias -s mp4='mpv'
alias -s m4a='mpv'
alias -s ogg='mpv'
alias -s flv='mpv'
alias -s opus='mpv'

alias -s doc='loffice'
alias -s md='vim'
alias -s rst='vim'

alias -s gba='mednafen'
alias -s gcm='dolphin-emu -e'
alias -s z64='mupen64plus'

alias -s html="$BROWSER"
alias -s htm="$BROWSER"
alias -s com="$BROWSER"
alias -s org="$BROWSER"
alias -s edu="$BROWSER"

#<- Functions ->
dbdl () {
    export url="$(purl $*)dl=1"
    echo $url; unset url
}

lsupd () {
    checkupdates
    cower -u
}

#<- Source ZSh Syntax Highlighting ->
#source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
