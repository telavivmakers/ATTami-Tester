#include <avr/io.h>
// F_CPU frequency to be defined at command line
#include <util/delay.h>

// LED is on pin 2, PB3
#define LED      PB3
#define DELAY_MS 500

int main () {
	uint8_t high = 0;
	uint16_t ms = 0;

	DDRB |= (1 << LED);
	PORTB &= ~(1 << LED);

	while (1) {	
		high = !high;

		if (high) {
			PORTB |= (1 << LED);
		} else {
			PORTB &= ~(1 << LED);
		}

		for (ms = DELAY_MS; ms > 0; ms -= 10) {
			_delay_ms(10);
		}
	}

	return 0;
}

