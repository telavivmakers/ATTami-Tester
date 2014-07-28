# ATtiny85 Blink

Runs on the Tel Aviv Makers ATtami board.

## Prerequisites

 - AVR GCC
 - ATMEL USB ISP (USBASP) programmer

Recommended to use the following udev rule:

```bash
$ cat /etc/udev/rules.d/98-usbasp.rules
SUBSYSTEM=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="users", MODE="0666"
```

## Usage

Connect the following pins:

 - Vcc
 - Ground
 - PB0 -- MOSI
 - PB1 -- MISO
 - PB2 -- SCK
 - PB5 -- RST

Then, run: 

```bash
$ make
``` 
## Credits

Based on work done by https://github.com/casebeer/attiny85-hello-world

