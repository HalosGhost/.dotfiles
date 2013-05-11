
static const char font[] = 
    "-xos4-terminus-medium-r-normal--13-*-*-*-*-*-iso10646-1";
static const char *tile_modes[] = 
    {"rstack", "monocle", NULL};
static const Tagcon tagcons[] = {
    /*  prefix  icon    suffix  */
    {   NULL,   19,     NULL    },
    {   NULL,   20,     NULL    },
    {   NULL,   23,     NULL    },
    {   NULL,   24,     NULL    },
    {   NULL,   21,     NULL    },
    {   NULL,   25,     NULL    },
    {   NULL,   26,     NULL    },
};

static const char    alopex_cursor        = XC_left_ptr;
static const int     borderwidth          = 1;
static const int     tilegap              = 0;
static const int     tagspace             = 0;
static const int     max_status_line      = 256;
static const int     win_min              = 20;
static const Bool    focusfollowmouse     = True;
static Bool          showbar              = True;
static Bool          topbar               = True;
static int           tilebias             = 0;
static const int     attachmode           = 1;
static int           stackcount           = 2;

#define LAUNCH       "interrobang"
#define TERM         "termite"
#define LOCK         "xautolock -locknow"
#define SCRN         "scrot $HOME/Pictures/Scrn/shot-%d-%m-%Y.png"
#define CMD(app)     app "&"
#define XRANDR_CMD   "xrandr --output LVDS --auto --output DisplayPort-0 --auto --left-of LVDS"
#define WALLPAPER    "source $HOME/.fehbg"

/* key definitions: */
#define MOD1 Mod4Mask
#define MOD2 Mod1Mask
#define MOD3 ControlMask
#define MOD4 ShiftMask
#define TAGK(KEY,TAG) \
   { MOD1,           KEY,           tag,           "t " TAG          }, \
   { MOD1|MOD2,      KEY,           tag,           "m " TAG          }, \
   { MOD1|MOD3,      KEY,           tag,           "s " TAG          }, \
   { MOD1|MOD4,      KEY,           tag,           "a " TAG          },

#define FN1          "sudo enlighten decrease display"
#define FN2          "sudo enlighten increase display"
#define FN3          "steam"
#define FN4          "netflix-desktop"
#define FN5          "sudo enlighten decrease keyboard"
#define FN6          "sudo enlighten increase keyboard"
#define FNA          "ponymix toggle -c 0"
#define FNB          "ponymix decrease 5"
#define FNC          "ponymix increase 5"


static Key keys[] = {
   /* modifier       key            function       argument          */
   /* launchers + misc: */
   { MOD1,           XK_Return,     spawn,         CMD(TERM)         },
   { MOD1,           XK_d,          spawn,         CMD(LAUNCH)       },
   { MOD1,           XK_w,          spawn,         CMD("$BROWSER")   },
   { MOD2|MOD4,      XK_q,          quit,          NULL              },
   { MOD1|MOD4,      XK_q,          killclient,    NULL              },
   { MOD1,           XK_f,          fullscreen,    NULL              },
   { MOD1,           XK_a,          toggle,        "place bar"       },
   { MOD1,           XK_x,          toggle,        "visible bar"     },
   { MOD1|MOD2,      XK_f,          toggle,        "floating"        },
   { MOD2|MOD3,      XK_l,          spawn,         CMD(LOCK)         },
   { MOD1,           0x60,          spawn,         CMD(SCRN)         },
   { MOD1,           XK_F4,         spawn,         XRANDR_CMD,       },
   /* function keys */
   { 0,              XK_F1,         spawn,         CMD(FN1)          },
   { 0,              XK_F2,         spawn,         CMD(FN2)          },
   { 0,              XK_F3,         spawn,         CMD(FN3)          },
   { 0,              XK_F4,         spawn,         CMD(FN4)          },
   { 0,              XK_F5,         spawn,         CMD(FN5)          },
   { 0,              XK_F6,         spawn,         CMD(FN6)          },
   { 0,              XK_F10,        spawn,         CMD(FNA)          },
   { 0,              XK_F11,        spawn,         CMD(FNB)          },
   { 0,              XK_F12,        spawn,         CMD(FNC)          },
   { 0,              0x1008ff2c,    spawn,         CMD("eject")      },
   /* tiling: */
   { MOD1,           XK_space,      tile,          "cycle"           },
   { MOD1,           XK_i,          tile_conf,     "increase"        },
   { MOD1,           XK_o,          tile_conf,     "decrease"        },
   { MOD1,           XK_equal,      tile_conf,     "+"               },
   { MOD1,           XK_minus,      tile_conf,     "-"               },
   { MOD1,           XK_period,     tile_conf,     "all"             },
   { MOD1,           XK_comma,      tile_conf,     "one"             },
   /* tags and views: */
   { MOD1,           XK_Tab,        tag,           "flip"            },
     TAGK(           XK_1,                         "1"               )
     TAGK(           XK_2,                         "2"               )
     TAGK(           XK_3,                         "3"               )
     TAGK(           XK_4,                         "4"               )
     TAGK(           XK_5,                         "5"               )
     TAGK(           XK_6,                         "6"               )
     TAGK(           XK_7,                         "7"               )
   /* window focus/movement:
      f=focus, s=swap                                                */
   { MOD1,           XK_k,          window,        "f prev"          },
   { MOD1,           XK_Left,       window,        "f prev"          },
   { MOD1,           XK_j,          window,        "f next"          },
   { MOD1,           XK_Right,      window,        "f next"          },
   { MOD2,           XK_Tab,        window,        "f alt"           },
   { MOD1,           XK_h,          window,        "s prev"          },
   { MOD1,           XK_Up,         window,        "s prev"          },
   { MOD1,           XK_l,          window,        "s next"          },
   { MOD1,           XK_Down,       window,        "s next"          },
   { MOD2|MOD4,      XK_Tab,        window,        "s alt"           },
   { MOD1|MOD4,      XK_equal,      window,        "+"               },
   { MOD1|MOD4,      XK_minus,      window,        "-"               },
   { MOD1|MOD4,      XK_space,      toggle,        "monitor focus"   },
};

static Button buttons[] = {
   /* modifier       button         function       arg               */
   { MOD1|MOD2,      1,             mouse,         "move"            },
   { MOD1,           2,             toggle,        "floating"        },
   { MOD1,           3,             mouse,         "resize"          },
   { MOD1,           4,             window,        "s prev"          },
   { MOD1,           5,             window,        "s next"          },
   { MOD1,           6,             window,        "f prev"          },
   { MOD1,           7,             window,        "f next"          },
};

static Rule rules[] = {
   /* name           class          tags           flags             */
   { "float",        NULL,          0,             FLAG_FLOATING     },
   { NULL,           "float",       0,             FLAG_FLOATING     },
   { NULL,           "dwb",         2,             0                 },
};

