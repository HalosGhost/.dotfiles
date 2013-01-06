#!/bin/sh
eval $(cat ~/.fehbg) &
xmodmap ~/.Xmodmap &
xrdb ~/.Xresources &
dropboxd &
conky -d
pasystray &
xautolock -time 15 -locker 'i3lock --color=000000' &
exec i3
