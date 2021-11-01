#include "Keyboard.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(100); // wait switch screen to recovery
  
  Keyboard.println("root");
  Keyboard.println("raspberry");
  delay(1000); // wait login

  Keyboard.println("mount /dev/sda1 /mnt2");
  delay(500); // wait mount USB key

  Keyboard.println("mount -o remount,rw /dev/mmcblk0p1 /mnt");
  delay(500); // remount first partition of SD card in RW mode

  Keyboard.println("rm -r /mnt/os/Libre*");
  delay(100); // delete useless distro (LibreELEC)

  Keyboard.println("cp /mnt2/boot.tar.xz /mnt/os/RaspiOS_Full_armhf/.");
  delay(5000); // move new boot archive for Raspbian with SSH enable to the SD Card

  Keyboard.println("echo -n " silentinstall" >> /mnt/recovery.cmdline");
  delay(100);
  
  Keyboard.println("reboot -f");
}

void loop() {
  // blink when complete
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
