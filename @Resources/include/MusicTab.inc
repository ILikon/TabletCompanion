; Measures

; Meters

[BackgroundMusicTab]
Meter=Image
ImageName=#@#images\bgMusic.png
X=0
Y=0
UpdateDivider=-1
Group=MusicTab


[MeterNoCover]
Meter=Image
ImageName=#@#images\noCover.png
; DynamicVariables=1
UpdateDivider=-1
X=((#SkinWidth# - #NoCoverSize#)/2 - 1)
Y=340
AntiAlias=1
PreserveAspectRatio=2
Group=MusicTab|MediaPlayer
LeftMouseDownAction=!Execute["C:\Program Files (x86)\Windows Media Player\wmplayer.exe" /prefetch:11 /Query:3;3;6;Resume previous list;29655;-1;;;;0;;;;1;;]

[MeterFullCover]
Meter=Image
MeasureName=MeasureCover
MaskImageName=#@#images\hexMask.png
; DynamicVariables=1
; W=542
H=542
X=((#SkinWidth# - #FullCoverSize#)/2 - 1)
Y=200
AntiAlias=1
PreserveAspectRatio=2
Group=MusicTab|MediaPlayer
MouseScrollUpAction=[!CommandMeasure MeasureTrack "SetPosition +5"]
MouseScrollDownAction=[!CommandMeasure MeasureTrack "SetPosition -5"]


[BackgroundMusicTabOverlay]
Meter=Image
ImageName=#@#images\bgMusicOverlay.png
X=0
Y=0
UpdateDivider=-1
Group=MusicTab

[MeterArtist]
Meter=String
MeasureName=MeasureArtist
X=(#SkinWidth#/2)
Y=940
W=#SkinWidth#
FontFace=#Font#
FontSize=#FontSizeArtist#
FontColor=#HighlightColor#
AntiAlias=1
StringCase=UPPER
StringAlign=CenterCenter
ClipString=2
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeterTrack]
Meter=String
MeasureName=MeasureTrack
X=(#SkinWidth#/2)
Y=1070
W=#SkinWidth#
FontFace=#Font#
FontSize=#FontSizeTitle#
FontColor=#TextColor#
AntiAlias=1
StringCase=UPPER
StringAlign=CenterCenter
ClipString=2
ClipStringH=150
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeterPosition]
Meter=String
MeasureName=MeasurePosition
X=(#SkinWidth#/7)
Y=830
FontFace=#Font#
FontSize=#FontSizeMusicTime#
FontColor=#HighlightColor#
AntiAlias=1
StringCase=UPPER
StringAlign=CenterCenter
UpdateDivider=10
Group=MusicTab|MediaPlayer

[MeterDuration]
Meter=String
MeasureName=MeasureDuration
X=(#SkinWidth#/7 * 6)
Y=r
FontFace=#Font#
FontSize=#FontSizeMusicTime#
FontColor=#HighlightColor#
AntiAlias=1
StringCase=UPPER
StringAlign=CenterCenter
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeterPlayPause]
Meter=Image
ImageName=[MeasurePlayPause]
DynamicVariables=1
X=((#SkinWidth# - #MusicButtonsSize#)/2)
Y=(830 - #MusicButtonsSize#/2)
AntiAlias=1
UpdateDivider=5
LeftMouseDownAction=[!CommandMeasure MeasureTrack "PlayPause"][!UpdateMeasure MeasurePlayPause][!UpdateMeter MeterPlayPause][!Redraw]
Group=MusicTab|MediaPlayer

[MeterPrevious]
Meter=Image
ImageName=#@#images\previous.png
; DynamicVariables=1
X=((#SkinWidth# - #MusicButtonsSize#)/2 - 130)
Y=r
AntiAlias=1
UpdateDivider=20
LeftMouseDownAction=[!CommandMeasure MeasureTrack "Previous"]
RightMouseDownAction=[!CommandMeasure MeasureTrack "SetPosition 0"]
Group=MusicTab|MediaPlayer

[MeterNext]
Meter=Image
ImageName=#@#images\next.png
; DynamicVariables=1
X=((#SkinWidth# - #MusicButtonsSize#)/2 + 130)
Y=r
AntiAlias=1
UpdateDivider=20
LeftMouseDownAction=[!CommandMeasure MeasureTrack "Next"]
Group=MusicTab|MediaPlayer

;============= Progress ===============

[MeasureProgress1]
Measure=Calc
Formula=(Min(1*100/6,Max(0*100/6,MeasureProgress))-0*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeasureProgress2]
Measure=Calc
Formula=(Min(2*100/6,Max(1*100/6,MeasureProgress))-1*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeasureProgress3]
Measure=Calc
Formula=(Min(3*100/6,Max(2*100/6,MeasureProgress))-2*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeasureProgress4]
Measure=Calc
Formula=(Min(4*100/6,Max(3*100/6,MeasureProgress))-3*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeasureProgress5]
Measure=Calc
Formula=(Min(5*100/6,Max(4*100/6,MeasureProgress))-4*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeasureProgress6]
Measure=Calc
Formula=(Min(6*100/6,Max(5*100/6,MeasureProgress))-5*100/6)*6
MaxValue=100
UpdateDivider=5
Group=MusicTab|Progress

[MeterProgress1]
Meter=Bar
MeasureName=MeasureProgress1
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(60)));(-sin(Rad(60)));(sin(Rad(60)));(cos(Rad(60)));385;195
Group=MusicTab|Progress

[MeterProgress2]
Meter=Bar
MeasureName=MeasureProgress2
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(0)));(-sin(Rad(0)));(sin(Rad(0)));(cos(Rad(0)));630;321
Group=MusicTab|Progress

[MeterProgress3]
Meter=Bar
MeasureName=MeasureProgress3
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(-60)));(-sin(Rad(-60)));(sin(Rad(-60)));(cos(Rad(-60)));643;596
Group=MusicTab|Progress

[MeterProgress6]
Meter=Bar
MeasureName=MeasureProgress6
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(120)));(-sin(Rad(120)));(sin(Rad(120)));(cos(Rad(120)));154;344
Group=MusicTab|Progress

[MeterProgress5]
Meter=Bar
MeasureName=MeasureProgress5
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(180)));(-sin(Rad(180)));(sin(Rad(180)));(cos(Rad(180)));168;619
Group=MusicTab|Progress

[MeterProgress4]
Meter=Bar
MeasureName=MeasureProgress4
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
UpdateDivider=5
TransformationMatrix=(cos(Rad(-120)));(-sin(Rad(-120)));(sin(Rad(-120)));(cos(Rad(-120)));412;745
Group=MusicTab|Progress
