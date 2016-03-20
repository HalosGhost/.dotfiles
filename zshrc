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
HISTSIZE=2048
SAVEHIST=2048
setopt appendhistory histignorealldups autocd notify prompt_subst interactivecomments
#setopt correctall
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

if [ "$DISPLAY" ]; then
   export RPROMPT="%F{black}$LSEGF%f%K{black} %B%(?.%F{cyan}^_^ %f.%F{red}o_O %f)%b%k"
   export PROMPT="%K{black} %F{white}%m%f %k%K{white}%F{black}$RSEGF%f%k%K{white} %F{black}%~%f %k$RSEGF
%(!.%K{red} λ\\.%K{blue} λ\\) %k%(!.%F{red}.%F{blue})$RSEGF%f "
else
   export RPROMPT='%B%(?.%{%F{cyan}%}^_^ %{%f%}.%{%F{red}%}o_O %{%f%})%b'
   export PROMPT='╒[%m]═[%~]%#
└╼ '
fi

#<- Keybinds ->
bindkey -M vicmd v edit-command-line
bindkey "^X" edit-command-line
bindkey "^_" history-incremental-pattern-search-backward
typeset -A key

bindkey "${terminfo[khome]}" beginning-of-line
bindkey "${terminfo[kend]}"  end-of-line
bindkey "${terminfo[kich1]}" overwrite-mode
bindkey "${terminfo[kdch1]}" delete-char
bindkey "${terminfo[kcuu1]}" up-line-or-history
bindkey "${terminfo[kcud1]}" down-line-or-history
bindkey "${terminfo[kcub1]}" backward-char
bindkey "${terminfo[kcuf1]}" forward-char

#<- Aliases ->
alias '..'='cd ..'
alias -g ...='../..'
alias -g ....='../../..'

alias ls='ls --color=auto -CFA'
alias ll='ls -lh'

for i in pacman cower grep; do
    alias "$i"="$i --color=always"
done

alias ytdl='youtube-dl'
alias sudo='sudo '
alias bc='bc -lq'
alias matrix='cmatrix -f -l -a'
alias lsbat='cat /sys/class/power_supply/BAT0/capacity'

alias pb='pbpst'
compdef _pbpst pb
alias shaman="shaman -l'Saint Paul,US'"

#<- Suffixes ->
alias -s pdf='zathura'
alias -s djvu='zathura'
alias -s jpg='sxiv'
alias -s png='sxiv'
alias -s gif='sxiv -a'
alias -s svg='inkview'
alias -s exe='mono'

for i in mp3 avi flac webm mkv mp4 mov m4a ogg ogv oga flv opus wav; do
    alias -s "$i"='qmpv'
done

alias -s md='vim'
alias -s rst='vim'
alias -s tex='vim'

#<- Functions ->
lsupd () {
    checkupdates
    cower -u
}

gitver () {
    git describe --long --tags | sed 's/\([^-]*-g\)/r\1/;s/-/./g'
}

upgraderepo () {
    (cd /usr/local/x86_64
    repose -f halosghost *)
}

cvis () {
    TERM=xterm-256color vis
}

netsloc () {
    printf '%s: %s\n' "$1" "$(awk 'BEGIN { a = 0; d = 0 } /^\+/ { a ++ } /^\-/ { d ++ } END { print "+" a ", -" d }' "$1")"
}

ytb () {
    mpv "$(clipit -p)"
}

yt () {
   ytdl -e --get-id "ytsearch$2:$1" | awk 'NR % 2 == 0 { print "ytdl://"$0 } NR % 2 != 0 { print $0 }'
}

onehs () {
   printf 'main = %s' "$1" | runhaskell
}

wifiscan () {
   sudo iw dev wlp3s0 scan|awk "/SSID: $1/"
}

#<- Source ZSh Syntax Highlighting ->
source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
