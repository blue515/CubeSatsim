This is the RPi Ground Station Build Guide (Using 24-03-12 ARMv7 image)

The easiest way to build the ground station on Raspberry 3/4 is using the
pre-built ground station image.
The ARISS Radio Pi image has FoxTelem, OpenWebRX, CubicSDR, QSSTV, and 
Gpredict. The ground station RPi image can be downloaded from,
http://cubesatsim.org/download/FIAB-V1.12z3-aj2.iso.zip


Or, build the ground station from scratch.

Here are the steps we use to create the ground station on Raspberry 3/4/5

Start from the scratch OS using 2024-03-12-raspios-bullseye-armhf.img
(Fox-in-Box-v3 uses 2020-06-02 ARMV7 32bit image)

Using Hostname: rpi-032 (or any legal hostname)
(Specified in RPi Imager)

The WiFi configuration is also specified in RPi Imager.

Inter SD card into the raspberry pi and boot,

Connect to RPi using Putty or ssh command in PowerShell:
ssh rpi-032.local (or the hostname specified in RPi Imager)

To enable debug uart, add
    enable_uart=1

to /root/confit.txt    

NOTE: Newer PI OS keep the file in /root/firmware/config.txt


Reboot,


To specify a static IP address,

do the followings in raspi-config,
Enable NetworkManager
Enable VNC server

Reboot,

Config network, static IP, 192.168.0.32

$ nmtui


Reboot,
