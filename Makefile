
default:
	# compile for attiny86 with warnings, optimizations, and 1 MHz clock frequency
	avr-gcc -Wall -Os -DF_CPU=1048576 -mmcu=attiny85 -o hello.o hello.c
	avr-objcopy -j .text -j .data -O ihex hello.o hello.hex
	avrdude -c usbasp -p t85 -U flash:w:hello.hex:i

clean: /dev/null
	rm -f hello.o hello.hex
