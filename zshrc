#<- ZSh RC ->

#<- Primary Options ->
HISTFILE=~/.zsh_hist
HISTSIZE=1000
SAVEHIST=1000
setopt appendhistory autocd notify
#setopt correctall
unsetopt beep
zstyle :compinstall filename '/home/halosghost/.zshrc'
zstyle ':completion:*' menu select
setopt completealiases
fpath=(~/.zsh/completion $fpath)
autoload -Uz compinit
compinit
export PS1="[%~]%% "
export RPROMPT="%(?.%F{cyan}^_^%f.%F{red}o_O%f)"
source $HOME/.zprofile
source $HOME/.zsh_env

#<- Keybinds ->
bindkey -v
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
alias netcfg='sudo netcfg'
alias whereami='pwd -P'
alias cower='cower --color=always'

#<- Suffixes ->
alias -s pdf='zathura'
alias -s jpg='feh'
alias -s png='feh'
alias -s gif='mplayer -loop 0'
alias -s mp3='mplayer'
alias -s avi='mplayer'
alias -s flac='mplayer'
alias -s webm='mplayer'
alias -s mkv='mplayer'
alias -s mp4='mplayer'
alias -s ogg='mplayer'

alias -s com='firefox'
alias -s org='firefox'
alias -s edu='firefox'

#<- Functions ->
dbdl () {
  export url="$(purl $*)dl=1"
  echo $url; unset url
}
