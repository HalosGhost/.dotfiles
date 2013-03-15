
static const char font[] = 
   "-xos4-terminus-medium-r-normal--13-*-*-*-*-*-iso10646-1";
static const char *tag_name[] = 
   {"1", "2", "3", "4", "5", NULL};
static const char *tile_modes[] = 
   {"monocle","R_ttwm", "B_ttwm", "rstack", "bstack", NULL};

static const char colors[LASTColor][9] = {
   [Background]      = "#101010",
   [Default]         = "#C6C6C6",
   [Occupied]        = "#6C6C6C",
   [Selected]        = "#4C7899",
   [Urgent]          = "#FF8880",
   [Title]           = "#6C6C6C",
};

static const char    ttwm_cursor          = XC_left_ptr;
static const int     borderwidth          = 1;
static const int     tilegap              = 0;
static const Bool    classictabs          = True;
static const int     max_status_line      = 256;
static const int     win_min              = 20;
static const Bool    focusfollowmouse     = True;
static Bool          showbar              = True;
static Bool          topbar               = True;
static int           tilebias             = 0;

static const char    *video1              = "LVDS1";
static const char    *video2              = "VGA1";
static const char    *video_location      = "below";

#include "icons.h"

#define DMENU        "dmenu_run -b"
#define TERM         "termite"
#define LOCK         "xautolock -locknow"
#define SCRN         "scrot $HOME/Pictures/Scrn/shot-%d-%m-%Y.png"
#define CMD(app)     app "&"

/* Fn assignments */
#define FN1          "sudo enlighten decrease display"
#define FN2          "sudo enlighten increase display"
#define FN3          "steam"
#define FN4          "netflix-desktop"
#define FN5          "sudo enlighten decrease keyboard"
#define FN6          "sudo enlighten increase keyboard"
#define FNA          "ponymix toggle -c 0"
#define FNB          "ponymix decrease 5"
#define FNC          "ponymix increase 5"

/* key definitions */
#define SUPR Mod4Mask
#define LALT Mod1Mask
#define CTRL ControlMask
#define SHFT ShiftMask

static Key keys[] = {
   /* modifier       key            function       argument       */
   /* launchers + misc: */
   { SUPR,           XK_Return,     spawn,         CMD(TERM)      },
   { SUPR,           XK_d,          spawn,         CMD(DMENU)     },
   { SUPR,           XK_w,          spawn,         CMD("firefox") },
   { LALT|SHFT,      XK_q,          quit,          NULL           },
   { SUPR|SHFT,      XK_q,          killclient,    NULL           },
   { SUPR,           XK_f,          fullscreen,    NULL           },
   { SUPR,           XK_a,          toggle,        "place bar"    },
   { SUPR,           XK_x,          toggle,        "visible bar"  },
   { SUPR|LALT,      XK_f,          toggle,        "floating"     },
   { LALT|CTRL,      XK_l,          spawn,         CMD(LOCK)      },
   { SUPR,           0x60,          spawn,         CMD(SCRN)      },
   /* fn remaps */
   { 0,              XK_F1,         spawn,         CMD(FN1)       },
   { 0,              XK_F2,         spawn,         CMD(FN2)       },
   { 0,              XK_F3,         spawn,         CMD(FN3)       },
   { 0,              XK_F4,         spawn,         CMD(FN4)       },
   { 0,              XK_F5,         spawn,         CMD(FN5)       },
   { 0,              XK_F6,         spawn,         CMD(FN6)       },
   { 0,              XK_F10,        spawn,         CMD(FNA)       },
   { 0,              XK_F11,        spawn,         CMD(FNB)       },
   { 0,              XK_F12,        spawn,         CMD(FNC)       },
   { 0,              0x1008ff2c,    spawn,         CMD("eject")   },
   /* tiling: */
   { SUPR,           XK_space,      tile,          "cycle"        },
   { SUPR|LALT,      XK_t,          tile,          "R_ttwm"       },
   { SUPR|LALT,      XK_b,          tile,          "bstack"       },
   { SUPR|LALT,      XK_r,          tile,          "rstack"       },
   { SUPR,           XK_m,          tile,          "monocle"      },
   { SUPR,           XK_i,          tile,          "increase"     },
   { SUPR,           XK_o,          tile,          "decrease"     },
   /* external monitor commands */
   { SUPR|SHFT,      XK_a,          monitor,       "activate"     },
   { SUPR|SHFT,      XK_d,          monitor,       "deactivate"   },
   { SUPR|SHFT,      XK_s,          monitor,       "send"         },
   { SUPR|SHFT,      XK_r,          monitor,       "return"       },
   /* tagging:
      s=set current active tag
      t=toggle toggle tag visibility
      a=assign window - toggle focused window's tag membership
      m=move win - assign focused window to a single tag          */
   { SUPR,           XK_1,          tag,           "s 1"          },
   { SUPR,           XK_2,          tag,           "s 2"          },
   { SUPR,           XK_3,          tag,           "s 3"          },
   { SUPR,           XK_4,          tag,           "s 4"          },
   { SUPR,           XK_5,          tag,           "s 5"          },
   { SUPR|LALT,      XK_1,          tag,           "t 1"          },
   { SUPR|LALT,      XK_2,          tag,           "t 2"          },
   { SUPR|LALT,      XK_3,          tag,           "t 3"          },
   { SUPR|LALT,      XK_4,          tag,           "t 4"          },
   { SUPR|LALT,      XK_5,          tag,           "t 5"          },
   { SUPR|SHFT,      XK_1,          tag,           "a 1"          },
   { SUPR|SHFT,      XK_2,          tag,           "a 2"          },
   { SUPR|SHFT,      XK_3,          tag,           "a 3"          },
   { SUPR|SHFT,      XK_4,          tag,           "a 4"          },
   { SUPR|SHFT,      XK_5,          tag,           "a 5"          },
   { SUPR|CTRL,      XK_1,          tag,           "m 1"          },
   { SUPR|CTRL,      XK_2,          tag,           "m 2"          },
   { SUPR|CTRL,      XK_3,          tag,           "m 3"          },
   { SUPR|CTRL,      XK_4,          tag,           "m 4"          },
   { SUPR|CTRL,      XK_5,          tag,           "m 5"          },
   /* window focus/movement:
      f=focus previous, next, or alternate  window in tag(s)
      s=swap window with previous, next, or alternate  window     */
   { SUPR,           XK_k,          window,        "f prev"       },
   { SUPR,           XK_j,          window,        "f next"       },
   { SUPR,           XK_Left,       window,        "f prev"       },
   { SUPR,           XK_Right,      window,        "f next"       },
   { SUPR,           XK_h,          window,        "s prev"       },
   { SUPR,           XK_l,          window,        "s next"       },
   { SUPR,           XK_Up,         window,        "s prev"       },
   { SUPR,           XK_Down,       window,        "s next"       },
   { SUPR,           XK_Tab,        window,        "f alt"        },
   { SUPR|SHFT,      XK_Tab,        window,        "s alt"        },
};

static Button buttons[] = {
   /* modifier       button         function       arg            */
 /*{ SUPR,           1,             mouse,         "move"         },*/
   { SUPR,           2,             tile,          "cycle"        },
   { SUPR,           3,             mouse,         "resize"       },
   { SUPR,           4,             window,        "s prev"       },
   { SUPR,           5,             window,        "s next"       },
   { SUPR,           6,             window,        "f prev"       },
   { SUPR,           7,             window,        "f next"       },
};


// vim: ts=4
