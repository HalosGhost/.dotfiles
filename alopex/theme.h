/* copyright J.McClure 2012-2013, see alopex.c or COPYING for details */

static const char colors[LASTColor][9] = {

#ifdef SummerCoat
#define THEME_NAME "SummerCoat"
	[Background]	= "#201814",
	[Default]		= "#686858",
	[Occupied]		= "#DDBB88",
    [Selected]		= "#EE8844",
	[Urgent]		= "#FFDD0E",
	[Title]			= "#EECCAA",
	[TabFocused]	= "#D0B072",
    [TabFocusedBG]	= "#242424",
    [TabTop]		= "#BB8844",
    [TabTopBG]		= "#242424",
    [TabDefault]	= "#686858",
    [TabDefaultBG]	= "#181818",
    [TagLine]		= "#FF4400",
#endif

#ifdef DayLight
#define THEME_NAME "DayLight"
    [Background]    = "#FAF0E6",
    [Default]       = "#121212",
    [Occupied]      = "#A04222",
    [Selected]      = "#CD6839",
    [Urgent]        = "#FF4222",
    [Title]         = "#B13E0F",
    [TabFocused]    = "#FF7216",
    [TabFocusedBG]  = "#EEE5DE",
    [TabTop]        = "#FF7216",
    [TabTopBG]      = "#EEE5DE",
    [TabDefault]    = "#A04222",
    [TabDefaultBG]  = "#CDC5BF",
    [TagLine]       = "#FF4400",
#endif

#ifdef WinterCoat
#define THEME_NAME "WinterCoat"
	[Background]	= "#101010",
	[Default]		= "#686868",
	[Occupied]		= "#68A0DD",
	[Selected]		= "#BBE0EE",
	[Urgent]		= "#FF8880",
	[Title]			= "#DDDDDD",
	[TabFocused]	= "#68B0E0",
	[TabFocusedBG]	= "#242424",
	[TabTop]		= "#486488",
	[TabTopBG]		= "#242424",
	[TabDefault]	= "#686868",
	[TabDefaultBG]	= "#181818",
	[TagLine]		= "#2436AA",
#endif

#ifdef IceWater
#define THEME_NAME "IceWater"
    [Background]    = "#101010",
    [Default]       = "#6C6C6C",
    [Occupied]      = "#C6C6C6",
    [Selected]      = "#4C7899",
    [Urgent]        = "#FF8880",
    [Title]         = "#DDDDDD",
    [TabFocused]    = "#4C7899",
    [TabFocusedBG]  = "#333333",
    [TabTop]        = "#6C6C6C",
    [TabTopBG]      = "#333333",
    [TabDefault]    = "#101010",
    [TabDefaultBG]  = "#333333",
#endif
};

