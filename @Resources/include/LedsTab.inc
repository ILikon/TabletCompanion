
[Variables]
BigHex=61,-35| LineTo 0,-70 | LineTo -61,-35 | LineTo -61,35 | LineTo 0,70 | LineTo 61,35 | ClosePath 1
SmallHex=43,-25| LineTo 0,-50 | LineTo -43,-25 | LineTo -43,25 | LineTo 0,50 | LineTo 43,25 | ClosePath 1
SelectedPath=Path MyPath | StrokeWidth 5 | Stroke Color #TextColor# | Fill Color #HighlightColor# | StrokeLineJoin Round
UnselectedPath=Path MyPath | StrokeWidth 0 | Stroke Color #TextColor# | Fill Color #HighlightColor# | StrokeLineJoin Round
OnOff=1
LightMode=0
ColorMode=0
ColorTransition=0
Intensity=1023

; Measures

; Measure Web Socket - sets up a web socket client to comunicate with the led controller
; OnOpen sends a message asking for the current status
[MeasureWS]
Measure=Plugin
Plugin=WebSocketClient
Address="ws://192.168.1.99:81/"
OnOpen=[!Log "Connection Opened"][!CommandMeasure MeasureWS "?;"][!SetOption ConnectionImage "ImageAlpha" "255"][!UpdateMeter ConnectionImage][!Redraw]
OnClose=[!Log "Connection Closed, Reason:$message$"][!SetOption ConnectionImage "ImageAlpha" "126"][!UpdateMeter ConnectionImage][!Redraw]
OnMessage=[!Log "Message Recieved:$message$"]
KeepAlive=1
PingServer=0
MaxReconnectAttempts=5
ParseCommands="O|I|C|L|S"
OnO=[!Log "Cmd Recieved O:$message$"][!UpdateMeasure MeasureToggleOnOff]
OnI=[!Log "Cmd Recieved I:$message$"][!SetVariable "Intensity" "$message$"][!UpdateMeasure MeasureRefreshSlide]
OnC=[!Log "Cmd Recieved C:$message$"][!SetVariable "ColorMode" "$message$"]
OnL=[!Log "Cmd Recieved L:$message$"][!SetVariable "LightMode" "$message$"][!UpdateMeasure MeasureRefreshLightMode]
OnS=[!Log "Cmd Recieved S:$message$"][!SetVariable "ColorTransition" "$message$"]

; Measure to turn off leds on shutdown, save led status and recover on init
[SaveLedStatus]
Measure=Calc
DynamicVariables=1
UpdateDivider=-1
IfCondition=(#Inited# = 0)
IfTrueAction=[!SetVariable "OnOff" "#LedStatus#"]
IfFalseAction=[!CommandMeasure MeasureWS "O0"][!WriteKeyValue Variables LedStatus #OnOff# "#@#variables.ini"]

; Plugin to implement sliding for brightness
[MeasureMouse]
Measure=Plugin
Plugin=Mouse
DynamicVariables=1
RelativeToSkin=1
RequireDragging=1
LeftMouseDragAction=[!SetVariable "Intensity" "(Clamp(Round(($MouseX$ - #SkinWidth#/2 + #BrightnessScrollW#/2)/#BrightnessScrollW#*1023), 0, 1023))"][!UpdateMeasure MeasureRefreshSlide][!CommandMeasure MeasureWS "I#Intensity#"]
LeftMouseUpAction=[!CommandMeasure MeasureMouse "Stop"]
Group=LedsTab

[MeasureRefreshSlide]
Measure=Calc
UpdateDivider=-1
DynamicVariables=1
OnUpdateAction=[!SetOption BrightnessHandle X "(#Intensity#/1023*#BrightnessScrollW# + #SkinWidth#/2 - #BrightnessScrollW#/2)"][!UpdateMeter BrightnessHandle][!Redraw]
Group=LedsTab

; Update button OnOff
[MeasureToggleOnOff]
Measure=Calc
UpdateDivider=-1
DynamicVariables=1
IfCondition=(#OnOff# = 1)
IfTrueAction=[!SetOption MeterOnOffButton Shape "#SelectedPath#"][!SetOption MeterOnOffButton "LeftMouseDownAction" """[!SetVariable "OnOff" "0"][!UpdateMeasure MeasureToggleOnOff]"""]
IfFalseAction=[!SetOption MeterOnOffButton Shape "#UnselectedPath#"][!SetOption MeterOnOffButton "LeftMouseDownAction" """[!SetVariable "OnOff" "1"][!UpdateMeasure MeasureToggleOnOff]"""]
IfConditionMode=1
OnUpdateAction=[!UpdateMeter MeterOnOffButton][!CommandMeasure MeasureWS "O#OnOff#"][!Redraw]
Group=LedsTab

[MeasureRefreshLightMode]
Measure=Calc
UpdateDivider=-1
DynamicVariables=1

IfCondition=#LightMode# = 3
IfTrueAction=[!SetOption MeterRaveButton Shape "#SelectedPath#"][!ActivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"][!SetVariable ComputeAudio "1" "#ROOTCONFIG#\AudioReporter"][!SetOption MeasureAudio Sensitivity "35" "#ROOTCONFIG#\AudioReporter"][!SetOption MeasureProcessAudio ScriptFile "#@#scripts\ProcessAudio.lua" "#ROOTCONFIG#\AudioReporter"]
IfFalseAction=[!SetOption MeterRaveButton Shape "#UnselectedPath#"]

IfCondition2=#LightMode# = 4
IfTrueAction2=[!SetOption MeterMusicButton Shape "#SelectedPath#"][!ActivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"][!SetVariable ComputeAudio "0"  "#ROOTCONFIG#\AudioReporter"][!SetOption MeasureAudio Sensitivity "35" "#ROOTCONFIG#\AudioReporter"][!SetOption MeasureProcessAudio ScriptFile "#@#scripts\ProcessAudio.lua" "#ROOTCONFIG#\AudioReporter"]
IfFalseAction2=[!SetOption MeterMusicButton Shape "#UnselectedPath#"]

IfCondition3=#LightMode# = 0
IfTrueAction3=[!SetOption MeterLightButton Shape "#SelectedPath#"][!DeactivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"]
IfFalseAction3=[!SetOption MeterLightButton Shape "#UnselectedPath#"]

IfCondition4=#LightMode# = 2
IfTrueAction4=[!SetOption MeterPulseButton Shape "#SelectedPath#"][!DeactivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"]
IfFalseAction4=[!SetOption MeterPulseButton Shape "#UnselectedPath#"]

IfCondition5=#LightMode# = 1
IfTrueAction5=[!SetOption MeterFadeButton Shape "#SelectedPath#"][!DeactivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"]
IfFalseAction5=[!SetOption MeterFadeButton Shape "#UnselectedPath#"]

IfCondition6=#LightMode# = 5
IfTrueAction6=[!SetOption MeterGameButton Shape "#SelectedPath#"][!ActivateConfig "#ROOTCONFIG#\AudioReporter" "AudioReporter.ini"][!SetOption MeasureAudio Sensitivity "10" "#ROOTCONFIG#\AudioReporter"][!SetOption MeasureProcessAudio ScriptFile "#@#scripts\ProcessAudioGaming.lua" "#ROOTCONFIG#\AudioReporter"]
IfFalseAction6=[!SetOption MeterGameButton Shape "#UnselectedPath#"]

IfConditionMode=1
OnUpdateAction=[!UpdateMeter MeterRaveButton][!UpdateMeter MeterMusicButton][!UpdateMeter MeterLightButton][!UpdateMeter MeterPulseButton][!UpdateMeter MeterFadeButton][!UpdateMeter MeterGameButton][!Redraw]
Group=LedsTab

; Meters

[BackgroundLedsTab]
Meter=Image
ImageName=#@#images\bgLeds.png
X=0
Y=0
UpdateDivider=-1
Group=LedsTab

[BackgroundLedsTabOverlay]
Meter=Image
ImageName=#@#images\bgLedsOverlay.png
X=0
Y=0
UpdateDivider=-1
Group=LedsTab

; -- OnOff --
[MeterOnOffButton]
Meter=Shape
Shape=#SelectedPath#
MyPath=#BigHex#
X=(#SkinWidth#/2)
Y=466
UpdateDivider=-1
Group=LedsTab

[OnOffImage]
Meter=Image
ImageName=#@#images\btOnOff.png
; DynamicVariables=1
X=((#SkinWidth# - #LedsIconsSize#)/2)
Y=(466 - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab


; -- Rave --
[MeterRaveButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 - 238)
Y=(876 - 140)
LeftMouseDownAction=[!SetVariable "LightMode" "3"][!CommandMeasure MeasureWS "L3"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[RaveImage]
Meter=Image
ImageName=#@#images\btRave.png
DynamicVariables=1
X=([MeterRaveButton:X] - #LedsIconsSize#/2)
Y=([MeterRaveButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Music --
[MeterMusicButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 - 110)
Y=(876 - 75)
LeftMouseDownAction=[!SetVariable "LightMode" "4"][!CommandMeasure MeasureWS "L4"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[MusicImage]
Meter=Image
ImageName=#@#images\btMusic.png
DynamicVariables=1
X=([MeterMusicButton:X] - #LedsIconsSize#/2)
Y=([MeterMusicButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Game --
[MeterGameButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 - 238)
Y=876
LeftMouseDownAction=[!SetVariable "LightMode" "5"][!CommandMeasure MeasureWS "L5"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[GameImage]
Meter=Image
ImageName=#@#images\btGame.png
DynamicVariables=1
X=([MeterGameButton:X] - #LedsIconsSize#/2)
Y=([MeterGameButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Fade --
[MeterFadeButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 + 238)
Y=(876 - 140)
LeftMouseDownAction=[!SetVariable "LightMode" "1"][!CommandMeasure MeasureWS "L1"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[FadeImage]
Meter=Image
ImageName=#@#images\btFade.png
DynamicVariables=1
X=([MeterFadeButton:X] - #LedsIconsSize#/2)
Y=([MeterFadeButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Pulse --
[MeterPulseButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 + 110)
Y=(876 - 70)
LeftMouseDownAction=[!SetVariable "LightMode" "2"][!CommandMeasure MeasureWS "L2"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[PulseImage]
Meter=Image
ImageName=#@#images\btPulse.png
DynamicVariables=1
X=([MeterPulseButton:X] - #LedsIconsSize#/2)
Y=([MeterPulseButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Light --
[MeterLightButton]
Meter=Shape
Shape=#UnselectedPath#
MyPath=#SmallHex#
X=(#SkinWidth#/2 + 238)
Y=876
LeftMouseDownAction=[!SetVariable "LightMode" "0"][!CommandMeasure MeasureWS "L0"][!UpdateMeasure MeasureRefreshLightMode]
UpdateDivider=-1
Group=LedsTab

[LightImage]
Meter=Image
ImageName=#@#images\btLight.png
DynamicVariables=1
X=([MeterLightButton:X] - #LedsIconsSize#/2)
Y=([MeterLightButton:Y] - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

; -- Brightness --
[BrightnessOffImage]
Meter=Image
ImageName=#@#images\brightnessOff.png
DynamicVariables=1
X=(90 - #LedsIconsSize#/2)
Y=(1050 - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

[BrightnessOnImage]
Meter=Image
ImageName=#@#images\brightnessOn.png
DynamicVariables=1
X=(#SkinWidth# - 90 - #LedsIconsSize#/2)
Y=(1050 - #LedsIconsSize#/2)
UpdateDivider=-1
Group=LedsTab

[BrightnessScroll]
Meter=Shape
Shape=Path MyPath | StrokeWidth 5 | StrokeColor #HighlightColor# | FillColor 0,0,0,0 | StrokeLineJoin Round
MyPath=240,0| LineTo 233,-13 | LineTo -232,-13 | LineTo -240,0 | LineTo -233,13 | LineTo 232,13 | ClosePath 1
X=(#SkinWidth#/2)
Y=1050
UpdateDivider=-1
Group=LedsTab

[BrightnessHandle]
Meter=Shape
Shape=#SelectedPath#
MyPath=26,-15| LineTo 0,-30 | LineTo -26,-15 | LineTo -26,15 | LineTo 0,30 | LineTo 26,15 | ClosePath 1
X=(#SkinWidth#/2 + 100)
Y=1050
LeftMouseDownAction=[!CommandMeasure MeasureMouse "Start"]
UpdateDivider=-1
Group=LedsTab