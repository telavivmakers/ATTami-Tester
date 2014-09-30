
#include <avr/eeprom.h>
#include <avr/io.h>
#include <util/delay.h>

uint8_t state;


int main() {
	state = eeprom_read_byte((uint8_t*)0) & 1;
	if ((MCUSR & (1 << PORF)) != 0) {
		MCUSR = 1;
		state ^= 1;
		eeprom_write_byte((uint8_t*)0, state);
	}

	DDRB |= _BV(DDB0);
	DDRB |= _BV(DDB1);
	DDRB |= _BV(DDB2);
	DDRB |= _BV(DDB3);
	DDRB |= _BV(DDB4);

	while (1) {
		if (state == 1) {
			PORTB ^= _BV(PB4);
			_delay_ms(500);
			PORTB ^= _BV(PB4);

			PORTB ^= _BV(PB3);
			_delay_ms(500);
			PORTB ^= _BV(PB3);

			PORTB ^= _BV(PB2);
			_delay_ms(500);
			PORTB ^= _BV(PB2);

			PORTB ^= _BV(PB1);
			_delay_ms(500);
			PORTB ^= _BV(PB1);

			PORTB ^= _BV(PB0);
			_delay_ms(500);
			PORTB ^= _BV(PB0);
		}
		else {
			PORTB ^= _BV(PB0);
			_delay_ms(500);
			PORTB ^= _BV(PB0);

			PORTB ^= _BV(PB1);
			_delay_ms(500);
			PORTB ^= _BV(PB1);

			PORTB ^= _BV(PB2);
			_delay_ms(500);
			PORTB ^= _BV(PB2);

			PORTB ^= _BV(PB3);
			_delay_ms(500);
			PORTB ^= _BV(PB3);

			PORTB ^= _BV(PB4);
			_delay_ms(500);
			PORTB ^= _BV(PB4);
	    }
	}
}

