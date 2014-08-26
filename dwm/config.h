/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>
#include "push.c"

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#4c7899";
static const char selbgcolor[]      = "#4c7899";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "term", "web", "docs", "play", "etc" };

static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            True,        -1 },
    { "Pale moon",NULL,       NULL,       1 << 1,       False,       -1 },
    { "Termite",  NULL,       NULL,       1 << 0,       False,       -1 },
    { "Steam",    NULL,       NULL,       1 << 3,       False,       -1 },
    { "mpv",      NULL,       NULL,       1 << 3,       False,       -1 },

    { NULL,       "term",     NULL,       1 << 0,       False,       -1 },
    { NULL,       "web",      NULL,       1 << 1,       False,       -1 },
    { NULL,       "docs",     NULL,       1 << 2,       False,       -1 },
    { NULL,       "play",     NULL,       1 << 3,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon [2] = "0";
static const char * dmenucmd []  = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, "-b", NULL };
static const char * termcmd []   = { "st", "-e", "tmux", NULL };
static const char * volumeInc [] = { "pactl", "--", "set-sink-volume", "1", "+5%", NULL };
static const char * volumeDec [] = { "pactl", "--", "set-sink-volume", "1", "-5%", NULL };
static const char * volumeTog [] = { "pactl", "--", "set-sink-mute", "1", "toggle", NULL };
static const char * lockscrn []  = { "xautolock", "-locknow", NULL };
static const char * bl_up []     = { "sudo", "enlighten", "increase", "display", NULL };
static const char * bl_dn []     = { "sudo", "enlighten", "decrease", "display", NULL };

static Key keys[] = {
    /* modifier                key                        function          argument */
    { MODKEY,                  XK_d,                      spawn,            {.v = dmenucmd } },
    { 0,                       XK_Menu,                   spawn,            {.v = dmenucmd } },
    { MODKEY,                  XK_Return,                 spawn,            {.v = termcmd } },
    { 0,                       XF86XK_AudioRaiseVolume,   spawn,            {.v = volumeInc } }, 
    { 0,                       XF86XK_AudioLowerVolume,   spawn,            {.v = volumeDec } },
    { 0,                       XF86XK_AudioMute,          spawn,            {.v = volumeTog } },
    { 0,                       XF86XK_MonBrightnessDown,  spawn,            {.v = bl_dn } },
    { 0,                       XF86XK_MonBrightnessUp,    spawn,            {.v = bl_up } },
    { MODKEY|ControlMask,      XK_l,                      spawn,            {.v = lockscrn } },
    { MODKEY,                  XK_b,                      togglebar,        {0} },
    { MODKEY|ShiftMask,        XK_j,                      pushdown,         {0} },
    { MODKEY|ShiftMask,        XK_k,                      pushup,           {0} },
    { MODKEY,                  XK_j,                      focusstack,       {.i = +1 } },
    { MODKEY,                  XK_k,                      focusstack,       {.i = -1 } },
    { MODKEY,                  XK_h,                      setmfact,         {.f = -0.05} },
    { MODKEY,                  XK_l,                      setmfact,         {.f = +0.05} },
    { MODKEY|ShiftMask,        XK_Return,                 zoom,             {0} },
    { MODKEY,                  XK_Tab,                    view,             {0} },
    { MODKEY|ShiftMask,        XK_c,                      killclient,       {0} },
    { MODKEY,                  XK_t,                      setlayout,        {.v = &layouts[0]} },
    { MODKEY,                  XK_f,                      setlayout,        {.v = &layouts[1]} },
    { MODKEY,                  XK_m,                      setlayout,        {.v = &layouts[2]} },
    { MODKEY|ShiftMask,        XK_space,                  togglefloating,   {0} },
    { MODKEY,                  XK_0,                      view,             {.ui = ~0 } },
    { MODKEY|ShiftMask,        XK_0,                      tag,              {.ui = ~0 } },
    { MODKEY,                  XK_comma,                  focusmon,         {.i = -1 } },
    { MODKEY,                  XK_period,                 focusmon,         {.i = +1 } },
    { MODKEY|ShiftMask,        XK_comma,                  tagmon,           {.i = -1 } },
    { MODKEY|ShiftMask,        XK_period,                 tagmon,           {.i = +1 } },
    TAGKEYS(                   XK_1,                                        0)
    TAGKEYS(                   XK_2,                                        1)
    TAGKEYS(                   XK_3,                                        2)
    TAGKEYS(                   XK_4,                                        3)
    TAGKEYS(                   XK_5,                                        4)
    { MODKEY|ShiftMask,        XK_q,                      quit,             {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        toggleview,     {0} },
    { ClkTagBar,            0,              Button3,        view,           {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

