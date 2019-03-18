

make BOARD=feather_nrf52840_express clean

make BOARD=feather_nrf52840_express all combinehex

#To flash the bootloader with JLink:
##make BOARD=feather_nrf52840_express flash
#To upgrade the bootloader using DFU Serial via port /dev/ttyACM0
##make BOARD=feather_nrf52840_express SERIAL=/dev/ttyACM0 dfu-flash
#To flash SoftDevice (and chip erase):
##make BOARD=feather_nrf52840_express sd
#To erase all of flash:
##make BOARD=feather_nrf52840_express erase
