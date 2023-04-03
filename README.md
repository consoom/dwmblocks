# My build of dwmblocks

My personal build of dwmblocks

## About
dwmblocks is a very simple program that essentially sets the name of the root window of the X server. My window manager, [dwm](https://github.com/consoom/dwm), displays the name of this window in the top right corner. This way, we essentiall create a statusbar with informational elements by changing the name of the root window to a string with the outputs of [various scripts I wrote](https://github.com/consoom/comfydots/tree/main/scripts/.local/bin/statusbar).

This statusbar is supposed to be used in combination with [my dotfiles](https://github.com/consoom/comfydots) and all other programs I use with them.

The unique thing about dwmblocks is that unlike wrapper scripts using `xsetroot -name "imaginary statusbar"`, dwmblocks can manage the time intervals between runs of your scripts (called blocks) and supports signals, which enables external programs to force a refresh of a certain block in the statusbar. This can optimize performance, because scripts will only run when needed. On top of that, this build also supports passing through mouse actions on blocks to scripts.

## Signals
Most statusbars constantly rerun every script every several seconds to update. This is an option here, but a superior choice is giving your block a signal in *config.c*, so that you can send a signal to it which updates the block on a relevant event, rather than having it rerun idly.

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
This build of dwmblocks is based on [UtkarshVerma/dwmblocks-async commit a9f7763](https://github.com/UtkarshVerma/dwmblocks-async/commit/a9f77635963af0b9e178e8d2cc7bddbe9a791626). It has support for clickable blocks out of the box and was not patched by me in any way.

## Installation
This program is supposed to be installed and used together with my [dotfiles](https://github.com/consoom/comfydots), which will install this build of dwm and all of the other tools and configurations I use automatically for you. I don't recommend using my personal configurations without first changing them to your own needs, but feel free to experiment and contribute to them.

## Example screenshot
![Example statusbar](https://user-images.githubusercontent.com/33983173/166840608-f505e0c4-adfa-4229-a52d-1c80861ce383.png)

## Credits
[dwmblocks-async](https://github.com/UtkarshVerma/dwmblocks-async) by [Utkarsh Verma](https://github.com/UtkarshVerma)
utkarshverma [at] protonmail [dot] com
