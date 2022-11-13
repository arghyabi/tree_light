all:
	@rm -rf src/build-*
	@cd src && make
	@cp src/build-uno/src_.hex tree_light.hex
	@rm -rf src/build-*


clean:
	@rm -rf src/build-*
	@rm -rf *.hex


burn:
	@sudo avrdude -v -Cavrdude.conf -patmega328p -carduino -P/dev/ttyUSB0 -b57600 -D -Uflash:w:tree_light.hex:i
