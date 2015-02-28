#<- ZSh RC ->
[[ -z "${DISPLAY}" && "${XDG_VTNR}" -eq 1 ]] && exec startx

#<- Primary Options ->
export PATH=$PATH:$HOME/.bin
RSEGF=""
RSEG=""
LSEGF=""
LSEG=""
BRNCH=""
HISTFILE=~/.zsh_hist
HISTSIZE=1000
SAVEHIST=1000
setopt appendhistory histignorealldups autocd notify prompt_subst
#setopt correctall
unsetopt beep
zstyle :compinstall filename '/home/halosghost/.zshrc'
zstyle ':completion:*' menu select
setopt completealiases
fpath=(~/.zsh/completion $fpath)
autoload -Uz compinit
#autoload -Uz vcs_info
autoload -U bashcompinit
autoload -U edit-command-line
zle -N edit-command-line
compinit
bashcompinit
eval $(dircolors $HOME/.dircolors )

#precmd () {
#   vcs_info 'prompt'
#}
#
#zstyle ':vcs_info:*:prompt:*' check-for-changes true
#zstyle ':vcs_info:*:prompt:*' unstagedstr '±'
#zstyle ':vcs_info:*:prompt:*' actionformats "%c %b"
#zstyle ':vcs_info:*:prompt:*' formats "%c %b"
#vcs_info_msg_0_

if [ "$DISPLAY" ]; then
   export RPROMPT="%F{black}$LSEGF%f%K{black} %B%(?.%F{cyan}^_^ %f.%F{red}o_O %f)%b%k"
   export PROMPT="%K{black} %F{white}%m%f %k%K{white}%F{black}$RSEGF%f%k%K{white} %F{black}%~%f %k$RSEGF
%(!.%K{red} λ\\.%K{blue} λ\\) %k%(!.%F{red}.%F{blue})$RSEGF%f "
else
   export RPROMPT='%B%(?.%{%F{cyan}%}^_^ %{%f%}.%{%F{red}%}o_O %{%f%})%b'
   export PROMPT='╒[%m]═[%~]%

└╼ '
fi

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
alias matrix='cmatrix -f -l -a'
alias whereami='pwd -P'
alias cower='cower --color=always'
alias pacman='pacman --color=always'
alias count='wc -l'
alias sloc='cloc'
alias lsbat='cat /sys/class/power_supply/BAT0/capacity'
alias qmpv='mpv --msg-level=all=error:statusline=status'
alias shaman="shaman -l'Saint Paul,US'"

alias FTL='steam -applaunch 212680'
alias Splice='steam -applaunch 209790'
alias dinothawr='retroarch -L /usr/lib/libretro/dinothawr_libretro.so /home/halosghost/Games/dinothawr/dinothawr.game'
alias praetorian='ssh -i"${HOME}/.ssh/halosghost.ed25519" "praetorian.erebor.buhman.org"'
alias centurion='ssh -i"${HOME}/.ssh/halosghost.ed25519" "centurion.erebor.buhman.org"'

#<- Suffixes ->
alias -s pdf='zathura'
alias -s jpg='sxiv'
alias -s png='sxiv'
alias -s gif='sxiv -a'
alias -s mp3='qmpv'
alias -s avi='qmpv'
alias -s flac='qmpv'
alias -s webm='qmpv'
alias -s mkv='qmpv'
alias -s mp4='qmpv'
alias -s mov='qmpv'
alias -s m4a='qmpv'
alias -s ogg='qmpv'
alias -s flv='qmpv'
alias -s opus='qmpv'

alias -s md='vim'
alias -s rst='vim'
alias -s tex='vim'

alias -s nds='retroarch -L /usr/lib/libretro/libretro-desmume.so'

#<- Functions ->
dbdl () {
    export url="$(purl $*)dl=1"
    echo $url; unset url
}

lsupd () {
    checkupdates
    cower -u
}

yt () {
   ytdl -e --get-id "ytsearch$2:$1"
}

#<- Source ZSh Syntax Highlighting ->
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
