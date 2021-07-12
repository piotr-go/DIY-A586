# DIY-A586 by Piotr Gozdur <piotr_go>

- [Board](#board)
- [Schematic](#schematic)
- [Menu of main core](#menu-of-main-core)
- [Running Minimig core](#running-minimig-core)
- [Floppy splitter](#floppy-splitter)
- [Gotek Floppy Emulator](#gotek-floppy-emulator)
- [Initial flashing of the firmware](#initial-flashing-of-the-firmware)
    - [Using CH341A 24 25 Series EEPROM Flasher](#using-ch341a-24-25-series-eeprom-flasher)
- [Links](#links)

## Board
![DIY-A586 top](img/foto_003.jpg)
![DIY-A586 bottom](img/foto_004.jpg)

## Schematic
![Schematic](pcb/v1.6/schemat.png)

## Menu of main core
![Main core menu](img/foto_007.jpg)

## Running Minimig core
![Minimig core](img/foto_008.jpg)
![Minimig core](img/foto_009.jpg)

## Floppy splitter
![Minimig core](img/foto_010.jpg)

## Gotek Floppy Emulator

If you are using a Gotek drive with FlashFloppy, don't copy files **HXCSDFE.CFG** and **AUTOBOOT.HFE** to the USB stick. The FlashFloppy/HxC File Selector will not work with DIY-A586. Copy only the **.adf** files to the USB stick and select the files with buttons or the rotary knob.

![Minimig core](img/diy-a586-with-gotek.jpg)

## Initial flashing of the firmware

### Using CH341A 24 25 Series EEPROM Flasher

This shows the initial flashing with the CH341A programmer on Ubuntu using the [flashrom tool](https://manpages.ubuntu.com/manpages/focal/man8/flashrom.8.html).

![Minimig core](img/flash-firmware-ch341a.jpg)
flashrom has the weird behaviour that the bin file must have the exact size of the flash rom. This can be fixed with the following workaround:

* read empty flash and write to local .bin file: ```sudo flashrom --programmer ch341a_spi -r example.bin```
* copy main.bin into example.bin with: ```dd if=main.bin of=example.bin conv=notrunc```
* check result: ```vbindiff main.bin example.bin```

![Minimig core](img/flash-bin-file-size-workaround.png)

* now you have a bin file with correct size to flash: ```sudo flashrom --programmer ch341a_spi -w example.bin```
* you're done ;o)

> Change the example filenames above to your needs respectively to current main.bin version!

## Links
* https://www.elektroda.com/rtvforum/topic3598849.html or https://www.elektroda.de/rtvforum/topic3598849.html
* https://www.youtube.com/watch?v=OAxe3ryDPwQ&list=PLbiryfyA62EBfDKSVf1hBP-nj-KQiV575
