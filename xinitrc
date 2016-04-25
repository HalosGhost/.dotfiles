start-pulseaudio-x11 &
yawa -F $HOME/.xbkg.jpg
xmodmap $HOME/.Xmodmap &
export EDITOR=/usr/bin/vim
export XDG_CONFIG_HOME=$HOME/.config
export BROWSER=/usr/bin/firefox
export TERMINAL=/usr/bin/st
export PATH=$PATH:$HOME/.bin
export PAGER=/usr/bin/vimpager
export GTK_IM_MODULE=xim
export QT_IM_MODULE=xim
export FT2_SUBPIXEL_HINTING=1
dstat &
clipit -dn &
exec dwm
