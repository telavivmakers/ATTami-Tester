1. solder attami board.
2. connect boot usb (usbasp) connector to chip, 
	make sure white dot corresponds to dot on ATTiny.
	when connecting, 1 red and 1 blue leds should turn on in the ATTami.
3. enter `dmesg` in a terminal to see that the usb is connected. should show ****fill in later**** 
4. install arduino ide (so avrdude will work).
5. run `avrdude -c usbasp -p attiny85 -v` to see that the fuses are all ok.
	(usbasp is the usb stick, attiny85 is the chip.)
6. clone [ATTami-tester repo](https://github.com/telavivmakers/ATTami-Tester)  
	6.1 maybe use the rules defined there:  
		$ cp 98-usbasp.rules /etc/udev/rules.d/  
		$ udevadm control --reload-rules  
	6.2 open terminal in the folder where `ATTami-Tester.hex` is located.  
7. assuming everything works, test the leds and ability to burn by running:
`avrdude -v -pattiny85 -cusbasp -e -Uefuse:w:0xFE:m -Uhfuse:w:0b11011111:m -Ulfuse:w:0xF1:m -Uflash:w:./ATTami-Tester.hex:i`
8. second blue light should blink.
9. now the moment of truth, burn the bootloader (for the usb bit-banger):
	`avrdude -v -pattiny85 -cusbasp -e -Uefuse:w:0xFE:m -Uhfuse:w:0b11011111:m -Ulfuse:w:0xF1:m -Uflash:w:./t85_entry_on_power_on_no_pullup_fast_exit_on_no_USB.hex:i`
assuming it said everything was ok, you should now be able to compile code on the arduino IDE (with some setup), and upload your compiled code to the ATTami using the USB alone.
10. first, disconnet the burner USB and connect the ATTami via the usb port.
11. check its connection with `dmesg`.
if it doesn't recognize the device, check the pins. jig will be made soon.
	12. otherwise, setup arduino settings for attiny85 and compile file. then, setup attiny compiler on arduino (from [attiny repo](https://github.com/sonyhome/attiny`)):

	Menu: File -> Preferences -> Settings -> Additional Boards Manager URLs:

	`https://raw.githubusercontent.com/sonyhome/attiny/master/package_damellis_attiny_index.json`

	Now go to the boards manager to fetch and install AtTiny support.

	Menu: Tools/Board/Boards Manager...

	Scroll until you find the AtTiny support, and click the install button.

13. then, select the attiny85 board from Tools -> Boards.
14. verify code (note pins are as described in the board diagram in [attami](https://github.com/telavivmakers/at-tami) repo
15. go to File -> Preferences and check "show verbose output during" -> compilation.
16. compile.
17. find the .hex file from the verbose output, and copy file to some nice directory.

18. final steps taken from [tami wiki](https://wiki.telavivmakers.org/ATtami#micronucleus_.28command_line.29)\
 we'll download the latest micronucleus release from [here](https://github.com/micronucleus/micronucleus/releases).  \
 unzip, and  
 - `cd micronucleus/commandline`  
 - `make`  
 
 finally, 
 `run micronucleus --run <your_compiled_code.hex>`\
 now plug in your board and you should get a confirmation from MNuc when its done. \
 Maybe try pressing the restart button if it doesn't work.\
 19. code should work now.
 
DONE!!!! 🍻🎉🎊🥳🥂
wiki has instructions on how to be able to upload straight from arduino IDE I think.
