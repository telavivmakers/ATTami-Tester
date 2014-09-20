
#include <avr/io.h>
#include <util/delay.h>

int
main (void)
{
	DDRB |= _BV(DDB0);
	DDRB |= _BV(DDB1);
	DDRB |= _BV(DDB2);
	DDRB |= _BV(DDB3);
	DDRB |= _BV(DDB4);
	while(1) {
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

