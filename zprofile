#<- ZProfile ->

#<- Keep TTY constant for X ->
[[ -z $DISPLAY && $XDG_VTNR -eq 1 ]] && startx
