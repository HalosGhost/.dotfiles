
static const char font[] = 
    "-xos4-terminus-medium-r-normal--13-*-*-*-*-*-iso10646-1";
static const char *tile_modes[] = 
    {"rstack", "monocle", NULL};
static const Tagcon tagcons[] = {
    /*  prefix  icon    suffix  */
    {   NULL,   11,     NULL    }, // Terminal
    {   NULL,   12,     NULL    }, // Internet
    {   NULL,   15,     NULL    }, // Media
    {   NULL,   13,     NULL    }, // Documents
    {   NULL,   17,     NULL    }, // Image Work
    {   NULL,   18,     NULL    }, // Et cetera
};

static const char    alopex_cursor        = XC_left_ptr;
static const int     borderwidth          = 0;
static const int     tilegap              = 0;
static const int     tagspace             = 0;
static const int     max_status_line      = 256;
static const int     win_min              = 20;
static const Bool    focusfollowmouse     = True;
static Bool          showbar              = True;
static Bool          topbar               = True;
static int           tilebias             = 143;
static const int     attachmode           = 1;
static int           stackcount           = 2;

#define LAUNCH       "interrobang"
#define TERM         "$TERMINAL"
#define LOCK         "xautolock -locknow"
#define WNDWLST      "interrobang -opt \"set last = false\" alopex"
#define SCRN         "scrot $HOME/Pictures/Scrn/shot-%d-%m-%Y.png"
#define CMD(app)     app "&"
#define XRANDR_CMD   "xrandr --output LVDS --auto --output DisplayPort-0 --auto --left-of LVDS"
#define WALLPAPER    "source $HOME/.fehbg"

/* key definitions: */
#define ALTR Mod1Mask
#define CTRL ControlMask
#define SHFT ShiftMask
#define SUPR Mod4Mask
#define TAGK(KEY,TAG) \
   { ALTR,           KEY,           tag,           "t " TAG          }, \
   { ALTR|SUPR,      KEY,           tag,           "m " TAG          }, \
   { ALTR|CTRL,      KEY,           tag,           "s " TAG          }, \
   { ALTR|SHFT,      KEY,           tag,           "a " TAG          },

#define FN1          "sudo enlighten decrease display"
#define FN2          "sudo enlighten increase display"
#define FN3          "steam"
#define FN4          "netflix-desktop"
#define FNA          "ponymix toggle -c 0"
#define FNB          "ponymix decrease 5&&mpv $XDG_CONFIG_HOME/alopex/pop-sound.flac --no-video"
#define FNC          "ponymix increase 5&&mpv $XDG_CONFIG_HOME/alopex/pop-sound.flac --no-video"

static Key keys[] = {
   /* modifier       key            function       argument          */
   /* launchers + misc: */
   { ALTR,           XK_Return,     spawn,         CMD(TERM)         },
   { ALTR,           XK_d,          spawn,         CMD(LAUNCH)       },
   { ALTR,           XK_w,          spawn,         CMD("$BROWSER")   },
   { SUPR|SHFT,      XK_q,          quit,          NULL              },
   { ALTR|SHFT,      XK_q,          killclient,    NULL              },
   { ALTR,           XK_f,          fullscreen,    NULL              },
   { ALTR|SUPR,      XK_f,          toggle,        "floating"        },
   { ALTR|CTRL,      XK_l,          spawn,         CMD(LOCK)         },
   { ALTR,           0x60,          spawn,         CMD(SCRN)         },
   { ALTR,           XK_F4,         spawn,         XRANDR_CMD        },
   /* function keys */
   { 0,              0x1008ff03,    spawn,         CMD(FN1)          },
   { 0,              0x1008ff02,    spawn,         CMD(FN2)          },
   { 0,              XK_F9,         spawn,         CMD(FNA)          },
   { 0,              XK_F11,        spawn,         CMD(FN3)          },
   { 0,              XK_F12,        spawn,         CMD(FN4)          },
   { 0,              0x1008ff11,    spawn,         CMD(FNB)          },
   { 0,              0x1008ff13,    spawn,         CMD(FNC)          },
   { 0,              0x1008ff2c,    spawn,         CMD("eject")      },
   { 0,              XK_Menu,       windowlist,    WNDWLST           },
   /* tiling: */
   { ALTR,           XK_space,      tile,          "cycle"           },
   { ALTR,           XK_i,          tile_conf,     "increase"        },
   { ALTR,           XK_o,          tile_conf,     "decrease"        },
   { ALTR,           XK_equal,      tile_conf,     "+"               },
   { ALTR,           XK_minus,      tile_conf,     "-"               },
   { ALTR,           XK_period,     tile_conf,     "all"             },
   { ALTR,           XK_comma,      tile_conf,     "one"             },
   /* tags and views: */
   { ALTR,           XK_Tab,        tag,           "flip"            },
     TAGK(           XK_1,                         "1"               )
     TAGK(           XK_2,                         "2"               )
     TAGK(           XK_3,                         "3"               )
     TAGK(           XK_4,                         "4"               )
     TAGK(           XK_5,                         "5"               )
     TAGK(           XK_6,                         "6"               )
     TAGK(           XK_7,                         "7"               )
   /* window focus/movement:
      f=focus, s=swap                                                */
   { ALTR,           XK_k,          window,        "f prev"          },
   { ALTR,           XK_Left,       window,        "f prev"          },
   { ALTR,           XK_j,          window,        "f next"          },
   { ALTR,           XK_Right,      window,        "f next"          },
   { SUPR,           XK_Tab,        window,        "f alt"           },
   { ALTR,           XK_h,          window,        "s prev"          },
   { ALTR,           XK_Up,         window,        "s prev"          },
   { ALTR,           XK_l,          window,        "s next"          },
   { ALTR,           XK_Down,       window,        "s next"          },
   { SUPR|SHFT,      XK_Tab,        window,        "s alt"           },
   { ALTR|SHFT,      XK_equal,      window,        "+"               },
   { ALTR|SHFT,      XK_minus,      window,        "-"               },
   { ALTR|SHFT,      XK_space,      toggle,        "monitor focus"   },
};

static Button buttons[] = {
   /* modifier       button         function       arg               */
   { ALTR|SUPR,      1,             mouse,         "move"            },
   { ALTR,           2,             toggle,        "floating"        },
   { ALTR,           3,             mouse,         "resize"          },
   { ALTR,           4,             window,        "s prev"          },
   { ALTR,           5,             window,        "s next"          },
   { ALTR,           6,             window,        "f prev"          },
   { ALTR,           7,             window,        "f next"          },
};

static Rule rules[] = {
   /* name           class          tags           flags             */
   { "float",        NULL,          0,             FLAG_FLOATING     },
   { NULL,           "float",       0,             FLAG_FLOATING     },
   { NULL,           "dwb",         2,             0                 },
};

