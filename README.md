# My build of dwmblocks

My personal build of dwmblocks

## About
dwmblocks is a very simple program that essentially sets the name of the root window of the X server. My window manager, [dwm](https://github.com/consoom/dwm), displays the name of this window in the top right corner. This way, we can basically create a statusbar with informational elements, by changing the name of the root window to a string with the outputs of [various scripts I wrote](https://github.com/consoom/comfydots/tree/main/scripts/.local/bin/statusbar). This statusbar is supposed to be used in combination with my [my dotfiles](https://github.com/consoom/comfydots) and all other programs I use with it. This build uses scripts I personally use, which doesn't make it independently portable and usable. However, you could take inspiration out of this build or contribute and suggest improvements. 

The unique thing about dwmblocks is that unlike wrapper scripts using `xsetroot -name "imaginary statusbar"`, dwmblocks can manage the time intervals between runs of your scripts (called blocks), and supports signals, which enables external programs to force a refresh of a certain block in the statusbar. This can optimize performance, because not all scripts have to run all the time, instead, only when needed. On top of that, this build also supports passing through mouse actions on blocks to scripts. These mouse actions get signaled to dwmblocks via [dwm](https://github.com/consoom/dwm).

## Signals
Most statusbars constantly rerun every script every several seconds to update. This is an option here, but a superior choice is giving your block a signal in *blocks.h*, so that you can signal to it which updates the block on a relevant event, rather than having it rerun idly.

For example, the volume block has the update signal 10 by default. Thus, running `pkill -RTMIN+10 dwmblocks` will update it (running the command that belongs to that block).

You can also run `kill -44 $(pidof dwmblocks)` which will have the same effect, but is faster. Just add 34 to your typical signal number.

## Clickable blocks
The special feature of this dwmblocks build is that it passes a `$BLOCK_BUTTON` variable to scripts and commands belonging to a block that has been clicked on. This allows you to write scripts that react on mouse presses, for example:
```
#!/bin/sh
case $BLOCK_BUTTON in
	1) notify-send "CPU usage" "$(ps axch -o cmd,%cpu --sort=-%cpu | head)" ;;
	3) st -e htop ;;
esac
```
**Note: for clickable buttons to work, dwm has to send mouse action signals to dwmblocks, which requires the statuscmd patch for dwm. [My version of dwm](https://github.com/consoom/dwm) already includes this patch. [Here](https://dwm.suckless.org/patches/statuscmd/) you can find the required patch.**

## Async blocks
This build of dwmblocks is based on [UtkarshVerma/dwmblocks-async commit f1c0370](https://github.com/UtkarshVerma/dwmblocks-async/tree/f1c037037d0ab60b219ca2c39c1beb77371ca2fe). It has support for clickable blocks out of the box and was not patched by me in any way.

## Installation
I don't recommend using my personal build without changing the configuration, as it's adopted to satisfy my own workflow. It's supposed to be installed and used together with my [dotfiles](https://github.com/consoom/comfydots). Here are the install instructions:
```
git clone https://github.com/consoom/dwmblocks
cd dwmblocks
sudo make clean install
```

## Example screenshot
![Example statusbar](https://user-images.githubusercontent.com/33983173/166840608-f505e0c4-adfa-4229-a52d-1c80861ce383.png)

## Credits
[dwmblocks-async](https://github.com/UtkarshVerma/dwmblocks-async) by [Utkarsh Verma](https://github.com/UtkarshVerma)
utkarshverma [at] protonmail [dot] com
