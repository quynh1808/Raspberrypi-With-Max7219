# Raspberrypi-With-Max7219

* Using Raspberry pi to display up to arbitrary max7219.
* To use this code file you need to install the WiringPi library
You need to open terminal and type: '''sudo apt-get install wiringpi'''
* Connect Rasp to Max7219
  - VCC   3.3V:        17 physical
  - GND   0v:          20
  - Din   MOSI:        19
  - CS    CE0,CE1:     24,26, using Pin 24
  - SCLK:              23
* In the file code I have shown the birthday and the text "covid19" on the Max7219, you can change the text as you like.

* Complie: gcc max7219.c -o "name" -lwiringPi 
* I have attached the datasheet of max7219, you can refer to it.
