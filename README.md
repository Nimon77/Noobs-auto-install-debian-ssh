# Noobs auto install debian with auto-enabled ssh
Arduino micro rubber ducky to auto install raspbian with noobs and enable ssh without screen or keyboard

# Setup
- Open `auto-setup_noob_raspberry.ino` in Arduino IDE and flash it on a 32u4 or SAMD micro based boards
- Put `boot.tar.xz` at the root of an USB key (formated in FAT)
- Connect the USB key into the raspberry
- Power on the Raspberry and wait aproximatly 2 min
- Connect the arduino and wait until the LED on the board blink
