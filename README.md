# ATtiny85 Blink

Runs on the Tel Aviv Makers ATtami board.

## Prerequisites

 - avr-gcc
 - avr-libc
 - avrdude
 - ATMEL USB ISP (USBASP) programmer

Recommended to use the udev rule:

```bash
$ cp 98-usbasp.rules /etc/udev/rules.d/
$ udevadm control --reload-rules
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

