
default:
	# compile for attiuser@ubuntu$ avrdude -c stk500v1 -p attiny85 -P /dev/ttyACM0 -b 19200 -U flash:w:blink.hex
	avr-gcc -Wall -Os -DF_CPU=8000000L  -mmcu=attiny85 -o mf-tester.o mf-tester.c
	avr-objcopy -j .text -j .data -O ihex mf-tester.o mf-tester.hex

	avrdude -c stk500v1 -pattiny85 -U flash:w:mf-tester.hex:i -P /dev/ttyACM0

M1M:
	# compile for attiny86 with warnings, optimizations, and 1 MHz clock frequency
	avr-gcc -Wall -Os -DF_CPU=1048576 -mmcu=attiny85 -o mf-tester.o mf-tester.c
	avr-objcopy -j .text -j .data -O ihex mf-tester.o mf-tester.hex
	avrdude -c stk500v1 -p t85 -U flash:w:mf-tester.hex:i -P /dev/ttyACM0

clean: /dev/null
	rm -f mf-tester.o mf-tester.hex
