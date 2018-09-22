start-pulseaudio-x11 &
yawa -F $HOME/.xbkg.jpg
xmodmap $HOME/.Xmodmap &
export EDITOR=/usr/bin/vis
export XDG_CONFIG_HOME=$HOME/.config
export BROWSER=/usr/bin/palemoon
export TERMINAL=/usr/bin/st
export PATH=$PATH:$HOME/.bin
export GTK_IM_MODULE=xim
export QT_IM_MODULE=xim
export FT2_SUBPIXEL_HINTING=1
export $(cat /etc/locale.conf)
export WIFI_IFACE=wlp3s0
xss-lock physlock &
dstat &
clipit -dn &
xinput set-prop 'SynPS/2 Synaptics TouchPad' 'Device Enabled' '0' &
exec dwm
