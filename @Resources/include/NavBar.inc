; Measure

[ButtonSpacing]
Measure=Calc
Formula=(#SkinWidth# - 200) / 3
UpdateDivider=-1

[ButtonWidthDiference]
Measure=Calc
Formula=(ButtonSpacing - #ButtonsWidth#) / 2
UpdateDivider=-1

; Meters

[BackgroundNavBar]
Meter=Image
ImageName=#@#images\navbar.png
DynamicVariables=1
X=0
Y=(#SkinHeight# - [BackgroundNavBar:H])
UpdateDivider=-1

[ButtonSelectionIndicator]
Meter=Image
SolidColor=#HighlightColor#
DynamicVariables=1
H=10
W=#ButtonsWidth#
X=0
Y=(#SkinHeight# - 10)
UpdateDivider=-1

[ButtonOverHighlight]
Meter=Image
SolidColor=#HighlightColor#
DynamicVariables=1
H=115
W=#ButtonsWidth#
X=[ButtonWeatherTab:X]
Y=(#SkinHeight# - 115)
Hidden=1
UpdateDivider=-1


[ButtonMusicTab]
Meter=Image
ImageName=#@#images\musicTab.png
DynamicVariables=1
X=(100 + [ButtonWidthDiference] + [ButtonSpacing] * 0)
Y=([BackgroundNavBar:Y] + 25)
W=#ButtonsWidth#
H=#ButtonsHeight#
PreserveAspectRatio=1
UpdateDivider=2
; MouseOverAction=[!SetOption ButtonOverHighlight X "[ButtonMusicTab:X]"][!ShowMeter "ButtonOverHighlight"]
; MouseLeaveAction=[!HideMeter "ButtonOverHighlight"]
LeftMouseDownAction=[!SetVariable CurrentTab MusicTab][!UpdateMeasure MeasureRefreshCurrentTab]

; [ButtonWeatherTab]
; Meter=Image
; ImageName=#@#images\statsTab.png
; DynamicVariables=1
; X=(100 + [ButtonWidthDiference] + [ButtonSpacing] * 1)
; Y=([BackgroundNavBar:Y] + 25)
; W=#ButtonsWidth#
; H=#ButtonsHeight#
; PreserveAspectRatio=1
; UpdateDivider=2
; ; MouseOverAction=[!SetOption ButtonOverHighlight X "[ButtonWeatherTab:X]"][!ShowMeter "ButtonOverHighlight"]
; ; MouseLeaveAction=[!HideMeter "ButtonOverHighlight"]
; LeftMouseDownAction=[!SetOption ButtonSelectionIndicator X "[ButtonWeatherTab:X]"]

[ButtonStatsTab]
Meter=Image
ImageName=#@#images\statsTab.png
DynamicVariables=1
X=(100 + [ButtonWidthDiference] + [ButtonSpacing] * 1)
Y=([BackgroundNavBar:Y] + 25)
W=#ButtonsWidth#
H=#ButtonsHeight#
PreserveAspectRatio=1
UpdateDivider=2
; MouseOverAction=[!SetOption ButtonOverHighlight X "[ButtonStatsTab:X]"][!ShowMeter "ButtonOverHighlight"]
; MouseLeaveAction=[!HideMeter "ButtonOverHighlight"]
LeftMouseDownAction=[!SetVariable CurrentTab StatsTab][!UpdateMeasure MeasureRefreshCurrentTab]

[ButtonLedsTab]
Meter=Image
ImageName=#@#images\ledTab.png
DynamicVariables=1
X=(100 + [ButtonWidthDiference] + [ButtonSpacing] * 2)
Y=([BackgroundNavBar:Y] + 25)
W=#ButtonsWidth#
H=#ButtonsHeight#
PreserveAspectRatio=1
UpdateDivider=2
; MouseOverAction=[!SetOption ButtonOverHighlight X "[ButtonLedTab:X]"][!ShowMeter "ButtonOverHighlight"]
; MouseLeaveAction=[!HideMeter "ButtonOverHighlight"]
LeftMouseDownAction=[!SetVariable CurrentTab LedsTab][!UpdateMeasure MeasureRefreshCurrentTab]


[ConnectionImage]
Meter=Image
ImageName=#@#images\connection.png
X=(#SkinWidth# - 50)
Y=(#SkinHeight# - 75)
ImageAlpha=126
UpdateDivider=-1

