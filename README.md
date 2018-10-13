# TabletCompanion
A Rainmeter skin to use on a tablet in order to control music, check statistics of your pc and to stream audio levels to a RGB led controller.

 ## Previews
 <img src="Previews/Preview1.png?raw=true" width="290"><img src="Previews/Preview2.png?raw=true" width="290"><img src="Previews/Preview3.png?raw=true" width="290">
 
## Motivation
Have you ever felt like you have some really cool Rainmeter theme setup on your desktop which you are really proud of, with all the gadgets to control music, check stats and a fancy music visualizer to top it all up, but... in the end you spend 99% of your time without even seeing your desktop because you are allways using your browser or any other app maximized...

At least I did, and that gave me the idea of repurposing an old tablet to use side by side with my computer, use it as a second screen and build a Rainmeter theme to fit into it.
Furthermore, I recently built a circuit to control a pair of led strips through Wifi, and as you can imagine, it would be awesome to be able to control it with a touchable interface on my desk. Rainmeter, "running on the tablet", provides me the perfect interaction for this. But wait, there's more...
Remember I said it is possible to control the led strips through Wifi? Also, I'm guessing you probably already know about the Rainmeter AudioLevel plugin, so... yheap, that's right! Let's make our own home disco, with Rainmeter and leds.

## Features

### Control and visualize music
 - Check which music is currently playing, both on a local music player or on a web player
 - Spectrum visualizer and progress meter
 - Basic music controls - previous, next, start/pause, launch player
 
### Check your PC stats
 - View disk occupation and open respective folder
 - Check current CPU and RAM loads
 - Launch Task Manager from the CPU and RAM meters
 - Check Upload/Download speed and accomulated data transfer

### Control leds and stream music
 - Set led brightness
 - Turn leds On/Off
#### Switch between light modes:
 - Constant - Constant color and intensity
 - Fade - Fade from one color to the next
 - Pulse - Fade brightness from full to none and back
 - Disco - Blink leds to music rythm, one strip reacts to bass and the other to treble
 - Music - Keep brigthness constant but switch color on bass beat
 - Gaming - Dim brightness and blink when reacting to sound (explosions and gun firing), uses reds and yellows as colors
 
## Details and notes

I used an ESP8266 to control a pair of RGB led strips through Wifi. The ESP host a WebSocket server that receives commands to control color, intensity and lighting modes.

This skin connects to the ESP to send commands and to stream the values obtained from the AudioLevel plugin. Thus, for this skin to work, you will need to get my WebSocket client plugin (link bellow). 

The values from the audio are processed by a Lua script implementing an algorithm I developed for the purpose. You can also find bellow a link to a debugging skin I created to help me develop the algorithms, it can be helpfull if you wish to give it a try at tweaking or creating your own.

The Gaming processing algorithm was developped for BF1, I have no idea how well or not it will work in other games.

The skin is developed to fit my tablet resolution in fullscreen, which is 1280*800. You will probably need to make some adjustments to make it fit correctly at diferent resolutions.

I use the spacedesk application (link bellow) to use my tablet as a second computer screen.

For gaming, to improve your performance, you may disable the screen extension app, but do not unload Rainmeter or there will be no audio streaming.

I tried to avoid as much as possible impacting the PC performance, at any time only the visible meters are beeing updated and the audio streaming is only activated in the respective modes.

This skin will automatically turn the leds off when exiting and turn back on when starting.

You might need to edit the skin to match your audio application. Use right-click menu to switch between Web Audio (WebNowPlaying) and local (NowPlaying).

## Todo List (maybe...)
 - [ ] Add color selector for leds
 - [ ] Add color transition switcher
 - [ ] Add color mode switcher
 - [ ] Add a way to quit Rainmeter first before exiting Windows
 - [ ] Add a wheater tab
 - [ ] Make it easy to switch theme color


## Links
 - Websocket plugin to communicate with the ESP8266: 
https://github.com/ILikon/WebSocketPlugins
 - ESP8266 code to control the leds:
https://github.com/ILikon/ESPLedController
 - Rainmeter skin I used to develop and debug the audio processing algorithms:
https://github.com/ILikon/AudioReporter
 - [Spacedesk](https://www.spacedesk.net/multi-monitor-app-desktop-extension-screen-virtual-display) - desktop extension app (free for the moment)
 - Rainmeter forum thread about this skin:
 - Video preview:


## Acknowledgments
 - Some of the code in this skin is inspired or possibly copied and addapted from:
 https://github.com/MarcoPixel/monstercat-visualizer
 - The music bars where inspired by a great Rainmeter skin, Void 2.0 (links no longer available :\ )
 - Thank you Sóbrio for giving me your tablet, otherwise there would be none of this :D
 
