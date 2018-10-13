; Measures

[MeasureHD1]
Measure=FreeDiskSpace
Drive=#Drive1#
UpdateDivider=1000
Group=StatsTab

[MeasureHD1F]
Measure=FreeDiskSpace
Drive=#Drive1#
InvertMeasure=1
UpdateDivider=1000
Group=StatsTab

[MeasureHDT1]
Measure=FreeDiskSpace
Drive=#Drive1#
Total=1
UpdateDivider=1000
Group=StatsTab

[MeasureHD2]
Measure=FreeDiskSpace
Drive=#Drive2#
;InvertMeasure=1
UpdateDivider=1000
Group=StatsTab

[MeasureHD2F]
Measure=FreeDiskSpace
Drive=#Drive2#
InvertMeasure=1
UpdateDivider=1000
Group=StatsTab

[MeasureHDT2]
Measure=FreeDiskSpace
Drive=#Drive2#
Total=1
UpdateDivider=1000
Group=StatsTab

[MeasureHD3]
Measure=FreeDiskSpace
Drive=#Drive3#
;InvertMeasure=1
UpdateDivider=1000
Group=StatsTab

[MeasureHD3F]
Measure=FreeDiskSpace
Drive=#Drive3#
InvertMeasure=1
UpdateDivider=1000
Group=StatsTab

[MeasureHDT3]
Measure=FreeDiskSpace
Drive=#Drive3#
Total=1
UpdateDivider=1000
Group=StatsTab

[MeasureCPU]
Measure=CPU
UpdateDivider=20
Group=StatsTab

[MeasureRAM]
Measure=PhysicalMemory
UpdateDivider=20
Group=StatsTab

[MeasureNetIn]
Measure=NetIn
UpdateDivider=20
Group=StatsTab

[MeasureNetInTotal]
Measure=NetIn
Cumulative=1
UpdateDivider=20
Group=StatsTab

[MeasureNetOut]
Measure=NetOut
UpdateDivider=20
Group=StatsTab

[MeasureNetOutTotal]
Measure=NetOut
Cumulative=1
UpdateDivider=20
Group=StatsTab

; Meters

[BackgroundStatsTab]
Meter=Image
ImageName=#@#images\bgStats.png
X=0
Y=0
UpdateDivider=-1
Group=StatsTab

[BackgroundStatsTabOverlay]
Meter=Image
ImageName=#@#images\bgMusicOverlay.png
X=0
Y=0
UpdateDivider=-1
Group=StatsTab



;============= Progress ===============

[MeasureProgressHD1_1]
Measure=Calc
Formula=Min(50,MeasureHD1F/MeasureHDT1*100)*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab


[MeasureProgressHD1_2]
Measure=Calc
Formula=(Max(50,MeasureHD1F/MeasureHDT1*100)-50)*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab

[MeasureProgressHD2_1]
Measure=Calc
Formula=(Min(50,MeasureHD2F/MeasureHDT2*100))*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab


[MeasureProgressHD2_2]
Measure=Calc
Formula=(Max(50,MeasureHD2F/MeasureHDT2*100)-50)*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab

[MeasureProgressHD3_1]
Measure=Calc
Formula=(Min(50,MeasureHD3F/MeasureHDT3*100))*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab


[MeasureProgressHD3_2]
Measure=Calc
Formula=(Max(50,MeasureHD3F/MeasureHDT3*100)-50)*2
MaxValue=100
UpdateDivider=1000
Group=StatsTab


[MeterProgressHD1_1]
Meter=Bar
MeasureName=MeasureProgressHD1_1
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(-120)));(-sin(Rad(-120)));(sin(Rad(-120)));(cos(Rad(-120)));412;745
UpdateDivider=1000
Group=StatsTab

[MeterProgressHD1_2]
Meter=Bar
MeasureName=MeasureProgressHD1_2
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(60)));(-sin(Rad(60)));(sin(Rad(60)));(cos(Rad(60)));385;195
UpdateDivider=1000
Group=StatsTab

[MeterProgressHD2_1]
Meter=Bar
MeasureName=MeasureProgressHD2_1
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(0)));(-sin(Rad(0)));(sin(Rad(0)));(cos(Rad(0)));630;321
UpdateDivider=1000
Group=StatsTab

[MeterProgressHD2_2]
Meter=Bar
MeasureName=MeasureProgressHD2_2
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(-60)));(-sin(Rad(-60)));(sin(Rad(-60)));(cos(Rad(-60)));643;596
UpdateDivider=1000
Group=StatsTab

[MeterProgressHD3_1]
Meter=Bar
MeasureName=MeasureProgressHD3_1
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(120)));(-sin(Rad(120)));(sin(Rad(120)));(cos(Rad(120)));154;344
UpdateDivider=1000
Group=StatsTab

[MeterProgressHD3_2]
Meter=Bar
MeasureName=MeasureProgressHD3_2
BarImage=#@#images\progressSeg.png
BarOrientation=Vertical
Flip=1
DynamicVariables=1
TransformationMatrix=(cos(Rad(180)));(-sin(Rad(180)));(sin(Rad(180)));(cos(Rad(180)));168;619
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG1]
Meter=Bar
MeasureName=MeasureHD1F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(30)));(-sin(Rad(30)));(sin(Rad(30)));(cos(Rad(30)));165;329
; Y=373
; X=-24
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG1_2]
Meter=Bar
MeasureName=MeasureHD1F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(-30)));(-sin(Rad(-30)));(sin(Rad(-30)));(cos(Rad(-30)));399;196
; Y=-24
; X=447
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG2]
Meter=Bar
MeasureName=MeasureHD2F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(-90)));(-sin(Rad(-90)));(sin(Rad(-90)));(cos(Rad(-90)));637;338
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG2_2]
Meter=Bar
MeasureName=MeasureHD2F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(-150)));(-sin(Rad(-150)));(sin(Rad(-150)));(cos(Rad(-150)));635;607
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG3]
Meter=Bar
MeasureName=MeasureHD3F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(90)));(-sin(Rad(90)));(sin(Rad(90)));(cos(Rad(90)));162;605
; Y=165
; X=-605
UpdateDivider=1000
Group=StatsTab

[MeterProgressBG3_2]
Meter=Bar
MeasureName=MeasureHD3F
Percentual=1
BarImage=#@#images\driveProgress.png
ImageAlpha=128
BarOrientation=Vertical
DynamicVariables=1
TransformationMatrix=(cos(Rad(150)));(-sin(Rad(150)));(sin(Rad(150)));(cos(Rad(150)));395;740
UpdateDivider=1000
Group=StatsTab

; ----- Drive 1 ----
[Drive1]
Meter=String
StringAlign=Center
FontSize=86
FontColor=#TextColor#
FontFace=#Font#
Text=#Drive1Label#
AntiAlias=1
X=(#SkinWidth#/2)
Y=300
LeftMouseDownAction=!Execute ["#Drive1#"]
UpdateDivider=1000
Group=StatsTab

[HDD1]
Meter=String
MeasureName=MeasureHD1
StringAlign=Center
FontSize=28
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 110)
Y=275
Angle=(Rad(-30))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab

[HDDTotal1]
Meter=STRING
MeasureName=MeasureHDT1
StringAlign=Center
FontSize=28
FontColor=#HighlightColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 110)
Y=275
Angle=(Rad(30))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab

; ----- Drive 2 ----
[Drive2]
Meter=String
StringAlign=Center
FontSize=86
FontColor=#TextColor#
FontFace=#Font#
Text=#Drive2Label#
AntiAlias=1
X=(#SkinWidth#/2 + 90)
Y=450
LeftMouseDownAction=!Execute ["#Drive2#"]
UpdateDivider=1000
Group=StatsTab

[HDD2]
Meter=String
MeasureName=MeasureHD2
StringAlign=Center
FontSize=28
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 180)
Y=465
Angle=(Rad(-90))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab

[HDDTotal2]
Meter=STRING
MeasureName=MeasureHDT2
StringAlign=Center
FontSize=28
FontColor=#HighlightColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 100)
Y=630
Angle=(Rad(-30))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab


; ----- Drive 3 ----
[Drive3]
Meter=String
StringAlign=Center
FontSize=86
FontColor=#TextColor#
FontFace=#Font#
Text=#Drive3Label#
AntiAlias=1
X=(#SkinWidth#/2 - 90)
Y=450
LeftMouseDownAction=!Execute ["#Drive3#"]
UpdateDivider=1000
Group=StatsTab

[HDD3]
Meter=String
MeasureName=MeasureHD3
StringAlign=Center
FontSize=28
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 100)
Y=630
Angle=(Rad(30))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab

[HDDTotal3]
Meter=STRING
MeasureName=MeasureHDT3
StringAlign=Center
FontSize=28
FontColor=#HighlightColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 180)
Y=465
Angle=(Rad(90))
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=1000
Group=StatsTab

; ---- CPU ----

[MeterCPU]
Meter=STRING
MeasureName=MeasureCPU
StringAlign=Center
FontSize=48
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 100)
Y=805
AntiAlias=1
UpdateDivider=20
Group=StatsTab

[ImageCPU]
Meter=Image
ImageName=#@#images\CPU.png
X=(#SkinWidth#/2 - 250)
Y=800
AntiAlias=1
UpdateDivider=20
Group=StatsTab
LeftMouseDownAction=!Execute [taskmgr.exe]

; ---- RAM ----

[MeterRAM]
Meter=STRING
MeasureName=MeasureRAM
Percentual=1
StringAlign=Center
FontSize=48
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 100)
Y=805
AntiAlias=1
UpdateDivider=20
Group=StatsTab

[ImageRAM]
Meter=Image
ImageName=#@#images\RAM.png
X=(#SkinWidth#/2 + 150)
Y=800
AntiAlias=1
UpdateDivider=20
Group=StatsTab
LeftMouseDownAction=!Execute [taskmgr.exe]


; ---- NET ----

[ImageNET]
Meter=Image
ImageName=#@#images\NET.png
X=(#SkinWidth#/2 - 45)
Y=980
AntiAlias=1
UpdateDivider=20
Group=StatsTab

[MeterNetIn]
Meter=STRING
MeasureName=MeasureNetIn
StringAlign=Left
FontSize=32
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 60)
Y=975
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=20
Group=StatsTab

[MeterNetInTotal]
Meter=STRING
MeasureName=MeasureNetInTotal
StringAlign=Left
FontSize=32
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 + 60)
Y=1020
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=20
Group=StatsTab

[MeterNetOut]
Meter=STRING
MeasureName=MeasureNetOut
StringAlign=Right
FontSize=32
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 60)
Y=975
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=20
Group=StatsTab

[MeterNetOutTotal]
Meter=STRING
MeasureName=MeasureNetOutTotal
StringAlign=Right
FontSize=32
FontColor=#TextColor#
FontFace=#Font#
X=(#SkinWidth#/2 - 60)
Y=1020
Text=%1B
AntiAlias=1
AutoScale=1
NumOfDecimals=1
UpdateDivider=20
Group=StatsTab
