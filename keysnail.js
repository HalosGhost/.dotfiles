// ========================== KeySnail Init File =========================== //
// You can preserve your code in this area when generating the init file using GUI.
// Put all your code except special key, set*key, hook, blacklist.
// ========================================================================= //
//{{%PRESERVE%
// Put your codes here
//}}%PRESERVE%
// ========================================================================= //

// ========================= Special key settings ========================== //

key.quitKey              = "undefined";
key.helpKey              = "undefined";
key.escapeKey            = "C-v";
key.macroStartKey        = "undefined";
key.macroEndKey          = "undefined";
key.universalArgumentKey = "undefined";
key.negativeArgument1Key = "undefined";
key.negativeArgument2Key = "undefined";
key.negativeArgument3Key = "undefined";
key.suspendKey           = "S-ESC";

// ================================= Hooks ================================= //

// ============================= Key bindings ============================== //

// some convenience variables
var bmui              = window.BookmarkingUI;
var secho             = display.echoStatusBar;
var gcpt              = command.getClipboardText;
var scpt              = command.setClipboardText;
var closeNonPinnedTab = function () {
    if ( !getBrowser().selectedTab.pinned ) {
        BrowserCloseTabOrWindow();
    } else {
        secho('Cannot close pinned tab');
    }
}

var yankCurrentURL    = function () {
    let url = bmui._uri.asciiSpec;
    scpt(url); secho('Yanked ' + url);
}

var viewKs =
[ [ 'h',       ()     => goDoCommand('cmd_scrollLeft')                              , 'Scroll Left'     ]
, [ 'j',       ()     => goDoCommand('cmd_scrollLineDown')                          , 'Scroll Down'     ]
, [ 'k',       ()     => goDoCommand('cmd_scrollLineUp')                            , 'Scroll Up'       ]
, [ 'l',       ()     => goDoCommand('cmd_scrollRight')                             , 'Scroll Right'    ]
, [ ['g','g'], ()     => goDoCommand('cmd_scrollTop')                               , 'Scroll Top'      ]
, [ 'G',       ()     => goDoCommand('cmd_scrollBottom')                            , 'Scroll Bottom'   ]
, [ 'H',       ()     => BrowserBack()                                              , 'Hist Back'       ]
, [ 'J',       ()     => getBrowser().mTabContainer.advanceSelectedTab( 1, true)    , 'Next Tab'        ]
, [ 'K',       ()     => getBrowser().mTabContainer.advanceSelectedTab(-1, true)    , 'Prev Tab'        ]
, [ 'L',       ()     => BrowserForward()                                           , 'Hist Forward'    ]
, [ ':',       (e, a) => shell.input(null, a)                                       , 'Command Mode'    ]
, [ 'r',       ()     => BrowserReload()                                            , 'Reload'          ]
, [ 'R',       ()     => BrowserReloadSkipCache()                                   , 'Reload (cache)'  ]
, [ 'd',       ()     => closeNonPinnedTab()                                        , 'Close Tab'       ]
, [ 'u',       ()     => undoCloseTab()                                             , 'Unclose Tab'     ]
, [ 't',       ()     => shell.input('tabopen ')                                    , 'Tabopen'         ]
, [ 'T',       ()     => shell.input('tabopen ' + bmui._uri.asciiSpec)              , 'Tabopen URL'     ]
, [ 'o',       ()     => shell.input('open ')                                       , 'Open'            ]
, [ 'O',       ()     => shell.input('open ' + bmui._uri.asciiSpec)                 , 'Open URL'        ]
, [ 'y',       ()     => yankCurrentURL()                                           , 'Yank URL'        ]
, [ 'p',       ()     => gBrowser.loadURI(gcpt(), null, null)                       , 'Open Yanked'     ]
, [ 'P',       ()     => gBrowser.loadOneTab(gcpt(), null, null, null, false)       , 'Tabopen Yanked'  ]
, [ '/',       ()     => command.iSearchForward()                                   , 'Search Forward'  ]
, [ '?',       ()     => command.iSearchBackward()                                  , 'Search Backward' ]
, [ '[',       ()     => gBrowser.loadOneTab('about:about', null, null, null, false), 'about:about'     ]
, [ ['Z','Q'], ()     => goQuitApplication()                                        , 'Close Firefox'   ]
, [ ['Z','R'], ()     => command.restartApp()                                       , 'Restart Firefox' ]
]

for ( let i = 0; i < viewKs.length; ++ i ) {
    key.setViewKey(viewKs[i][0], viewKs[i][1], viewKs[i][2]);
}

var editKs =
[ [ 'C-u',     ()     => goDoCommand('cmd_deleteToBeginningOfLine')                 , 'Backline'        ]
, [ 'C-w',     ()     => goDoCommand('cmd_deleteWordBackward')                      , 'Backword'        ]
, [ 'ESC',     ()     => document.activeElement.blur()                              , 'Escape Focus'    ]
]

for ( let i = 0; i < editKs.length; ++ i ) {
    key.setEditKey(editKs[i][0], editKs[i][1], editKs[i][2]);
}
