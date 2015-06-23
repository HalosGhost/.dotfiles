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
export FT2_SUBPIXEL_HINTING=1
/home/halosghost/projects/lang/hs/dstat/dstat -e enp0s25 -w wlp3s0 &
exec dwm
