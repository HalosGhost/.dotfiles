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

#<- Keybinds ->
bindkey -v
bindkey "^[[7~" beginning-of-line
bindkey "^[[8~" end-of-line
bindkey "^[[3~" delete-char

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
alias urxvt='urxvt -fg Green -bg Black -fn "xft:inconsolata:pixelsize=14"'
alias bc='bc -lq'
alias locate='locate -d /home/halosghost/.mlocate/mlocate.db'
alias matrix='cmatrix -f -l -a'
alias netcfg='sudo netcfg'
alias packer='packer --auronly'
alias mplay='mplayctl loadfile '
alias whereami='pwd -P'

#<- Suffixes ->
alias -s pdf='zathura'
alias -s jpg='feh'
alias -s png='feh'
alias -s gif='mplayer -loop 0'
alias -s mp3='mplayer'
alias -s flac='mplayer'
alias -s webm='mplayer'
alias -s mkv='mplayer'
alias -s mp4='mplayer'
alias -s ogg='mplayer'

#<- Functions ->
dbdl () {
  export url="$(purl $*)dl=1"
  echo $url; unset url
}
