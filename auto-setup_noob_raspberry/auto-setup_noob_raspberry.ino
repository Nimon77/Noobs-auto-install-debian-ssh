#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  delay(1000);
  
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(500); // wait until switch to login screen
  
  Keyboard.println("root");
  delay(500);
  Keyboard.println("raspberry");
  delay(1000); // wait login

  Keyboard.println("mount /dev/sda1 /mnt2");
  delay(500); // wait mount USB key

  Keyboard.println("mount -o remount,rw /dev/mmcblk0p1 /mnt");
  delay(500); // remount first partition of SD card in RW mode

  Keyboard.println("rm -r /mnt/os/Libre*");
  delay(500); // delete useless distro (LibreELEC)

  Keyboard.println("cp /mnt2/boot.tar.xz /mnt/os/RaspiOS_Full_armhf/.");
  delay(5000); // move new boot archive for Raspbian with SSH enable to the SD Card

  Keyboard.println("echo -n \" silentinstall\" >> /mnt/recovery.cmdline");
  delay(500); // enable silent install for the next boot
  
  Keyboard.println("reboot -f"); // reboot to start silent install
}

void loop() {
  exit(0);
}
