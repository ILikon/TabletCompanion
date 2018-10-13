[MeasureState]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
UpdateDivider=10
Group=MusicTab|MediaPlayer

[MeasurePlayPause]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
Substitute="0":"#@#images\play.png","1":"#@#images\pause.png","2":"#@#images\play.png","3":"#@#images\play.png"
UpdateDivider=5
Group=MusicTab|MediaPlayer

[MeasureTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
Substitute="":"#NoTitleNameText#"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasureArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
Substitute="":"#NoArtistNameText#"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasureCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
; DefaultPath=#@#images\noCover.png
CoverPath=#@#images\coverWeb.png
; Substitute="":"#@#images\noCover.png"
UpdateDivider=20
Group=MusicTab|MediaPlayer

[MeasurePosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=10
Substitute="0:00":""
Group=MusicTab|MediaPlayer

[MeasureDuration]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=20
Substitute="0:00":""
Group=MusicTab|MediaPlayer

[MeasureProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
UpdateDivider=5
Group=MusicTab|MediaPlayer