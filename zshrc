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
setopt appendhistory histignorealldups autocd notify prompt_subst
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
   export PROMPT='╒[%m]═[%~]%

└╼ '
fi

#<- Keybinds ->
bindkey -M vicmd v edit-command-line
bindkey "^X" edit-command-line
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

alias ytdl='youtube-dl'
alias sudo='sudo '
alias grep='grep --color=auto'
alias bc='bc -lq'
alias matrix='cmatrix -f -l -a'
alias whereami='pwd -P'
alias cower='cower --color=always'
alias pacman='pacman --color=always'
alias count='wc -l'
alias lsbat='cat /sys/class/power_supply/BAT0/capacity'

if [ -f "/usr/bin/optirun" ]; then
    alias qmpv='optirun mpv --msg-level=all=error:statusline=status'
else
    alias qmpv='mpv --msg-level=all=error:statusline=status'
fi

if [ -f "/usr/bin/optirun" ]; then
    alias netflix='optirun chromium --app="https://netflix.com"'
else
    alias netflix='chromium --app="https://netflix.com"'
fi

alias pb='pbpst'
alias shaman="shaman -l'Saint Paul,US'"
alias FTL='steam -applaunch 212680'
alias Splice='steam -applaunch 209790'
alias dinothawr='retroarch -L /usr/lib/libretro/dinothawr_libretro.so /home/halosghost/Games/dinothawr/dinothawr.game'
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
alias -s ogv='qmpv'
alias -s oga='qmpv'
alias -s flv='qmpv'
alias -s opus='qmpv'
alias -s wav='qmpv'

alias -s md='vim'
alias -s rst='vim'
alias -s tex='vim'

alias -s nds='retroarch -L /usr/lib/libretro/libretro-desmume.so'

#<- Functions ->
lsupd () {
    checkupdates
    cower -u
}

upgraderepo () {
    (cd /usr/local/x86_64
    repose -f halosghost *)
}

netsloc () {
    printf '%s: %s\n' "$1" "$(awk 'BEGIN { a = 0; d = 0 } /^\+/ { a ++ } /^\-/ { d ++ } END { print "+" a ", -" d }' "$1")"
}

ytb () {
    mpv "ytdl://$(clipit -p)"
}

yt () {
   ytdl -e --get-id "ytsearch$2:$1"
}

#<- Source ZSh Syntax Highlighting ->
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
