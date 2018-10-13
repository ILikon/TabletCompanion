; Measures

[MeasureTime]
Measure=Time
Format="%H:%M"
UpdateDivider=20

[MeasureMonthDay]
Measure=Time
Format=%#d
UpdateDivider=1000

[MeasureMonth]
Measure=Time
Format=%B
UpdateDivider=1000
;Substitute="January":"JANEIRO","February":"FEVEREIRO","March":"MARCO","April":"ABRIL","May":"MAIO","June":"JUNHO","July":"JULHO","August":"AGOSTO","September":"SETEMBRO","October":"OUTUBRO","November":"NOVEMBRO","December":"DEZEMBRO"

[MeasureWeekDay]
Measure=Time
Format=%A
UpdateDivider=1000
;Substitute="Monday":"SEGUNDA","Tuesday":"TERCA","Wednesday":"QUARTA","Thursday":"QUINTA","Friday":"SEXTA","Saturday":"SABADO","Sunday":"DOMINGO"


; Meters

[BackgroundTopBar]
Meter=Image
ImageName=#@#images\topbar.png
X=0
Y=0
UpdateDivider=-1

[MeterTime]
Meter=String
MeasureName=MeasureTime
AntiAlias=1
FontFace=#Font#
FontColor=#TextColor#
FontSize=#FontSizeTime#
StringAlign=CenterBottom
X=95
Y=95
UpdateDivider=20


[MeterDate]
Meter=String
MeasureName=MeasureMonthDay
MeasureName2=MeasureWeekDay
MeasureName3=MeasureMonth
AntiAlias=1
Text="%2, %1 %3"
FontFace=#Font#
FontColor=#TextColor#
FontSize=#FontSizeDate#
StringAlign=RightBottom
X=(#SkinWidth# - 15)
Y=90
UpdateDivider=1000