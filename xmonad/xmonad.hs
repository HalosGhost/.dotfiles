import XMonad
import XMonad.Util.Run
import XMonad.Layout.Tabbed
import XMonad.Layout.ResizableTile
import XMonad.Actions.CycleWS
import XMonad.Hooks.ManageDocks
import XMonad.Hooks.ManageHelpers
import XMonad.Hooks.UrgencyHook
import XMonad.Hooks.DynamicLog
import Graphics.X11.ExtraTypes.XF86
import System.IO.UTF8
import qualified XMonad.StackSet as W
import qualified Data.Map as M
--import XMonad.Util.CustomKeys
--import XMonad.Actions.TagWindows

main = do
    h <- spawnPipe "xmobar"
    xmonad $ withUrgencyHook NoUrgencyHook defaultConfig
       { borderWidth             = 1
       , terminal                = "st -e tmux"
       , focusFollowsMouse       = True
       , normalBorderColor       = "#cccccc"
       , focusedBorderColor      = "#4c7899"
       , manageHook              = manageDocks <+> myManageHook
       , layoutHook              = myLayouts
       , workspaces              = [">_", "web", "docs", "play", "&c"]
       , logHook                 = dynamicLogWithPP $ myPP h
       , keys                    = myKeys
       } where

           myManageHook          = composeAll
             [ className         =? "Chromium"  --> doShift  "web"
             , className         =? "Steam"     --> doShift  "play"
             , className         =? "Gimp"      --> doShift  "docs"
             , className         =? "mpv"       --> doShift  "play"
--             , isFullscreen                     --> (doF W.focusDown <+> doFullFloat)
             ]

           myLayouts             = avoidStruts
                                   $   tiled
                                   ||| tabbed shrinkText defaultTheme
             where tiled         = Tall 1 (3/100) (3/5)

           myPP h                = defaultPP
             { ppOutput          = System.IO.UTF8.hPutStrLn h
             , ppTitle           = shorten 20
             , ppCurrent         = wrap "[" "]"
             , ppUrgent          = wrap "*" "*"
             , ppHidden          = pad
             , ppHiddenNoWindows = const ""
             , ppSep             = " | " --"  "
             , ppWsSep           = " "
             , ppLayout          = (\x -> case x of
                                       "Tall"            -> "[]="
                                       "Tabbed Simplest" -> "[T]"
                                       _                 -> x
                                   )
             }

           myDmenu               = "dmenu_run " ++ dmenuOpts
              where dmenuOpts    = "-nb '#000' -nf '#bbb' -sb '#4c7899' -sf '#eee'"

           myVol                 = "pactl -- set-sink-volume 1 "
           myMute                = "pactl -- set-sink-mute 1 toggle"
           myMicMute             = "pactl -- set-source-mute 2 toggle"

           myKeys conf@(XConfig {XMonad.modMask = modMask}) = M.fromList $
              [ ((modMask                , xK_Return ), spawn $ XMonad.terminal conf       )
              , ((modMask                , xK_d      ), spawn myDmenu                      )
              , ((modMask .|. shiftMask  , xK_c      ), kill                               )
              , ((modMask                , xK_j      ), windows W.focusDown                )
              , ((modMask                , xK_k      ), windows W.focusUp                  )
              , ((modMask                , xK_h      ), sendMessage Shrink                 )
              , ((modMask                , xK_l      ), sendMessage Expand                 )
              , ((modMask .|. shiftMask  , xK_j      ), windows W.swapDown                 )
              , ((modMask .|. shiftMask  , xK_k      ), windows W.swapUp                   )
              , ((modMask .|. controlMask, xK_l      ), spawn "xautolock -locknow"         )
              , ((modMask                , xK_Tab    ), toggleWS                           )
              , ((modMask                , xK_space  ), sendMessage NextLayout             )
              , ((modMask .|. shiftMask  , xK_space  ), setLayout $ XMonad.layoutHook conf )
              , ((modMask                , xK_t      ), withFocused $ windows . W.sink     )
              , ((0      ,  xF86XK_AudioRaiseVolume  ), spawn $ myVol ++ "+5%"             )
              , ((0      ,  xF86XK_AudioLowerVolume  ), spawn $ myVol ++ "-5%"             )
              , ((0      ,  xF86XK_AudioMute         ), spawn $ myMute                     )
              --, ((0      ,  xF86XK_AudioMicMute      ), spawn $ myMicMute                  )
              , ((0      ,  xF86XK_MonBrightnessUp   ), spawn $ "xbacklight +5"            )
              , ((0      ,  xF86XK_MonBrightnessDown ), spawn $ "xbacklight -5"            )
              ] ++

              [ ((m .|. modMask,           k         ), windows $ f i                      )
                  | (i, k) <- zip (take 5 (XMonad.workspaces conf)) [xK_1 ..]
                  , (f, m) <- [(W.greedyView, 0      ), (W.shift, shiftMask)               ]
              ]
