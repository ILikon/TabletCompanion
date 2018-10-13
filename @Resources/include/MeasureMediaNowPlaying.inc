[MeasureState]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=State
UpdateDivider=10
Group=MusicTab|MediaPlayer

[MeasurePlayPause]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=State
Substitute="0":"#@#images\play.png","1":"#@#images\pause.png","2":"#@#images\play.png"
UpdateDivider=5
Group=MusicTab|MediaPlayer

[MeasureTrack]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Title
Substitute="":"#NoTitleNameText#"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasureArtist]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Artist
Substitute="":"#NoArtistNameText#"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasureCover]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Cover
; Substitute="":"#@#images\noCover.png"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasurePosition]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Position
UpdateDivider=10
Substitute="0:00":""
Group=MusicTab|MediaPlayer

[MeasureDuration]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Duration
UpdateDivider=20
Substitute="0:00":""
Group=MusicTab|MediaPlayer

[MeasureProgress]
Measure=NowPlaying
PlayerName=#PlayerName#
PlayerType=Progress
UpdateDivider=5
Group=MusicTab|MediaPlayer