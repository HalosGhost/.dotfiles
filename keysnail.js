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

var viewKs =
[ [ 'h',       function ()     { goDoCommand('cmd_scrollLeft');                                    }, 'Scroll Left'     ]
, [ 'j',       function ()     { goDoCommand('cmd_scrollLineDown');                                }, 'Scroll Down'     ]
, [ 'k',       function ()     { goDoCommand('cmd_scrollLineUp');                                  }, 'Scroll Up'       ]
, [ 'l',       function ()     { goDoCommand('cmd_scrollRight');                                   }, 'Scroll Right'    ]
, [ ['g','g'], function ()     { goDoCommand('cmd_scrollTop');                                     }, 'Scroll Top'      ]
, [ 'G',       function ()     { goDoCommand('cmd_scrollBottom');                                  }, 'Scroll Bottom'   ]
, [ 'H',       function ()     { BrowserBack();                                                    }, 'Hist Back'       ]
, [ 'J',       function ()     { getBrowser().mTabContainer.advanceSelectedTab( 1, true);          }, 'Next Tab'        ]
, [ 'K',       function ()     { getBrowser().mTabContainer.advanceSelectedTab(-1, true);          }, 'Prev Tab'        ]
, [ 'L',       function ()     { BrowserForward();                                                 }, 'Hist Forward'    ]
, [ ':',       function (e, a) { shell.input(null, a);                                             }, 'Command Mode'    ]
, [ 'r',       function ()     { BrowserReload();                                                  }, 'Reload'          ]
, [ 'R',       function ()     { BrowserReloadSkipCache();                                         }, 'Reload (cache)'  ]
, [ 'd',       function ()     { closeNonPinnedTab();                                              }, 'Close Tab'       ]
, [ 'u',       function ()     { undoCloseTab();                                                   }, 'Unclose Tab'     ]
, [ 't',       function ()     { shell.input('tabopen ');                                          }, 'Tabopen'         ]
, [ 'T',       function ()     { shell.input('tabopen ' + bmui._uri.asciiSpec);                    }, 'Tabopen URL'     ]
, [ 'o',       function ()     { shell.input('open ');                                             }, 'Open'            ]
, [ 'O',       function ()     { shell.input('open ' + bmui._uri.asciiSpec);                       }, 'Open URL'        ]
, [ 'y',       function ()     { var url = bmui._uri.asciiSpec; scpt(url); secho('Yanked ' + url); }, 'Yank URL'        ]
, [ 'p',       function ()     { gBrowser.loadURI(gcpt(), null, null);                             }, 'Open Yanked'     ]
, [ 'P',       function ()     { gBrowser.loadOneTab(gcpt(), null, null, null, false);             }, 'Tabopen Yanked'  ]
, [ '/',       function ()     { command.iSearchForward();                                         }, 'Search Forward'  ]
, [ '?',       function ()     { command.iSearchBackward();                                        }, 'Search Backward' ]
, [ '[',       function ()     { gBrowser.loadOneTab('about:about', null, null, null, false);      }, 'about:about'     ]
, [ ['Z','Q'], function ()     { goQuitApplication();                                              }, 'Close Firefox'   ]
, [ ['Z','R'], function ()     { command.restartApp();                                             }, 'Restart Firefox' ]
]

for ( var i = 0; i < viewKs.length; ++ i ) {
    key.setViewKey(viewKs[i][0], viewKs[i][1], viewKs[i][2]);
}

var editKs =
[ [ 'C-u',     function ()     { goDoCommand('cmd_deleteToBeginningOfLine');                       }, 'Backline'        ]
, [ 'C-w',     function ()     { goDoCommand('cmd_deleteWordBackward');                            }, 'Backword'        ]
]

for ( var i = 0; i < editKs.length; ++ i ) {
    key.setEditKey(editKs[i][0], editKs[i][1], editKs[i][2]);
}
