start-pulseaudio-x11 &
yawa -F $HOME/.xbkg.jpg
xmodmap $HOME/.Xmodmap &
xautolock -time 15 -locker 'physlock' &
export XDG_CONFIG_HOME=$HOME/.config
export BROWSER=/usr/bin/qutebrowser
export TERMINAL=/usr/bin/st
export PATH=$PATH:$HOME/.bin
export PAGER=/usr/bin/vimpager
export GTK_IM_MODULE=xim
export QT_IM_MODULE=xim
xmobar &
exec xmonad
