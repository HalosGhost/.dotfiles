
static const char font[] = 
     "-xos4-terminus-medium-r-normal--13-*-*-*-*-*-iso10646-1";
static const char *tag_name[] = 
     {"one", "two", "three", "four", "five", NULL};
static const char *tile_modes[] = 
     {"R_ttwm", "B_ttwm", "rstack", "bstack","monocle", NULL};

static const char colors[LASTColor][9] = {
	[Background]	= "#101010",
	[Default]		= "#C6C6C6",
	[Occupied]		= "#6C6C6C",
	[Selected]		= "#4C7899",
	[Urgent]		= "#FF8880",
	[Title]			= "#6C6C6C",
};

static const char 	ttwm_cursor			= XC_left_ptr;
static const int	borderwidth			= 1;
static const int	tilegap				= 0;
static const Bool   classictabs         = False;
static const int	max_status_line		= 256;
static const int	win_min				= 20;
static const Bool	focusfollowmouse	= True;
static Bool			showbar				= True;
static Bool			topbar				= True;
static int			tilebias			= 0;

#include "icons.h"

#define DMENU		"dmenu_run -b"
#define TERM	    "termite"
#define LOCK        "xautolock -locknow"
#define SCRN        "scrot $HOME/Pictures/Scrn/shot-%d-%m-%Y.png"
/* Fn function assignments */
#define FN1         "sudo enlighten decrease display"
#define FN2         "sudo enlighten increase display"
#define FN3         "steam"
#define FN4         "netflix-desktop"
#define FN5         "sudo enlighten decrease keyboard"
#define FN6         "sudo enlighten increase keyboard"
#define FNA         "ponymix toggle -c 0"
#define FNB         "ponymix decrease 5"
#define FNC         "ponymix increase 5"

#define CMD(app)	app "&"

/* key definitions */
#define MOD1 Mod4Mask
#define MOD2 Mod1Mask
static Key keys[] = {
	/* modifier			key			function	argument */
	/* launchers + misc: */
	{ MOD1,				XK_Return,	spawn,		CMD(TERM)		},
	{ MOD1,				XK_d,		spawn,		CMD(DMENU)		},
	{ MOD1,				XK_w,		spawn,		CMD("firefox")	},
	{ MOD2|ShiftMask,	XK_q,		quit,		NULL			},
    { MOD1|ShiftMask,   XK_q,       killclient, NULL            },
	{ MOD1,				XK_f,		fullscreen,	NULL			},
	{ MOD1,				XK_a,		toggle,		"place bar"		},
	{ MOD1,				XK_x,		toggle,		"visible bar"	},
	{ MOD1|MOD2,		XK_f,		toggle,		"floating"		},
    { MOD2|ControlMask, XK_l,       spawn,      CMD(LOCK)       },
    { MOD1,             0x60,       spawn,      CMD(SCRN)       },
    /* fn remaps */
    { 0,                XK_F1,       spawn,      CMD(FN1)       },
    { 0,                XK_F2,       spawn,      CMD(FN2)       },
    { 0,                XK_F3,       spawn,      CMD(FN3)       },
    { 0,                XK_F4,       spawn,      CMD(FN4)       },
    { 0,                XK_F5,       spawn,      CMD(FN5)       },
    { 0,                XK_F6,       spawn,      CMD(FN6)       },
    { 0,                XK_F10,      spawn,      CMD(FNA)       },
    { 0,                XK_F11,      spawn,      CMD(FNB)       },
    { 0,                XK_F12,      spawn,      CMD(FNC)       },
    { 0,                0x1008ff2c,  spawn,      CMD("eject")   },
	/* tiling: */
	{ MOD1,				XK_space,	tile,		"cycle"			},
	{ MOD1|MOD2,		XK_t,		tile,		"R_ttwm"		},
	{ MOD1|MOD2,		XK_b,		tile,		"bstack"		},
	{ MOD1|MOD2,		XK_r,		tile,		"rstack"		},
    { MOD1,             XK_m,       tile,       "monocle"       },
	{ MOD1,				XK_i,		tile,		"increase"		},
	{ MOD1,				XK_o,		tile,		"decrease"		},
	/* tagging:
		s=set current active tag
		t=toggle toggle tag visibility
		a=assign window - toggle focused window's tag membership
		m=move win - assign focused window to a single tag		*/
	{ MOD1,				XK_1,		tag,		"s 1"			},
	{ MOD1,				XK_2,		tag,		"s 2"			},
	{ MOD1,				XK_3,		tag,		"s 3"			},
	{ MOD1,				XK_4,		tag,		"s 4"			},
	{ MOD1,				XK_5,		tag,		"s 5"			},
	{ MOD1|MOD2,		XK_1,		tag,		"t 1"			},
	{ MOD1|MOD2,		XK_2,		tag,		"t 2"			},
	{ MOD1|MOD2,		XK_3,		tag,		"t 3"			},
	{ MOD1|MOD2,		XK_4,		tag,		"t 4"			},
	{ MOD1|MOD2,		XK_5,		tag,		"t 5"			},
	{ MOD1|ShiftMask,	XK_1,		tag,		"a 1"			},
	{ MOD1|ShiftMask,	XK_2,		tag,		"a 2"			},
	{ MOD1|ShiftMask,	XK_3,		tag,		"a 3"			},
	{ MOD1|ShiftMask,	XK_4,		tag,		"a 4"			},
	{ MOD1|ShiftMask,	XK_5,		tag,		"a 5"			},
	{ MOD1|ControlMask,	XK_1,		tag,		"m 1"			},
	{ MOD1|ControlMask,	XK_2,		tag,		"m 2"			},
	{ MOD1|ControlMask,	XK_3,		tag,		"m 3"			},
	{ MOD1|ControlMask,	XK_4,		tag,		"m 4"			},
	{ MOD1|ControlMask,	XK_5,		tag,		"m 5"			},
	/* window focus/movement:
		f=focus previous, next, or alternate  window in tag(s)
		s=swap window with previous, next, or alternate  window	*/
	{ MOD1,				XK_k,		window,		"f prev"		},
	{ MOD1,				XK_j,		window,		"f next"		},
    { MOD1,             XK_Left,    window,     "f prev"        },
    { MOD1,             XK_Right,   window,     "f next"        },
	{ MOD1,				XK_h,		window,		"s prev"		},
	{ MOD1,				XK_l,		window,		"s next"		},
    { MOD1,             XK_Up,      window,     "s prev"        },
    { MOD1,             XK_Down,    window,     "s next"        },
    { MOD1,             XK_Tab,     window,     "f alt"         },
	{ MOD1|ShiftMask,	XK_Tab,		window,		"s alt"			},
};

static Button buttons[] = {
	/* modifier			button		function 	arg */
	{MOD1,				1,			mouse,		"move"		},
	{MOD1,				2,			tile,		"cycle"		},
	{MOD1,				3,			mouse,		"resize"	},
	{MOD1,				4,			window,		"s prev"	},
	{MOD1,				5,			window,		"s next"	},
	{MOD1,				6,			window,		"f prev"	},
	{MOD1,				7,			window,		"f next"	},
};


// vim: ts=4