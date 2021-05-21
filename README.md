# ATTami-Tester

Runs on the Tel Aviv Makers [ATtami](https://github.com/telavivmakers/at-tami) board.

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

### check
avrdude -c usbasp -p attiny85 -v

### burn bootloader micronucllius
```cmake
/home/yair/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino18/bin/avrdude -C/home/yair/.arduino15/packages/ATTinyCore/hardware/avr/1.5.2/avrdude.conf -v -pattiny85 -cusbasp -e -Uefuse:w:0xFE:m -Uhfuse:w:0b11011111:m -Ulfuse:w:0xF1:m -Uflash:w:/home/yair/.arduino15/packages/ATTinyCore/hardware/avr/1.5.2/bootloaders/micronucleus/t85_entry_on_power_on_no_pullup_fast_exit_on_no_USB.hex:i
```

## Credits

Based on work done by https://github.com/casebeer/attiny85-hello-world

