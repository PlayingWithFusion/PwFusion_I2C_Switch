# PwFusion_I2C_Switch

Are you looking for a way to take your project to the next level? Playing with Fusion's I2C Switch board is the way to go! This device greatly simplifies connectivity to a microcontroller through the QWIIC system. The typical 2 wires required to a toggle switch with a microcontroller can be reduced to one QWIIC cable. You can even chain multiple QWIIC devices together for maximum wiring efficiency! If that isn't enough, Playing with Fusion provides Arduino libraries to make writing code for these boards as easy as possible! Weather you are a beginner looking for a simple introduction to the world of hobbyist electronics or an advanced user looking for a rapid prototyping tool, Playing with Fusion's I2C Joystick is right for you!

## I2C Addresses

ADR   |   Address  
uncut |   0x13  
cut   |   0x14  


Each Playing with Fusion I2C interface board comes with 2 available I2C addresses, which can be easily selected by disconnecting a jumper on the printed circuit board. This allows for 2 of the same boards (ex: 2 toggle switch boards) to be used on the same QWIIC chain. If you would like more than 2, see docs/Programming Instructions and flash a modified firmware with additional I2C address options.

## Example Projects
RC Transmitter: https://github.com/PlayingWithFusion/RC_Transmitter

## Related
PwFusion_I2C_Toggle_Arduino_Library:    https://github.com/PlayingWithFusion/PwFusion_I2C_Toggle_Arduino_Library
PwFusion_Data_Transfer:                 https://github.com/PlayingWithFusion/PwFusion_Data_Transfer

IFB-40001 PwFusion_I2C_Encoder:     https://github.com/PlayingWithFusion/PwFusion_I2C_Encoder
IFB-40002 PwFusion_I2C_Joystick:    https://github.com/PlayingWithFusion/PwFusion_I2C_Joystick
IFB-40003 PwFusion_I2C_Switch:      https://github.com/PlayingWithFusion/PwFusion_I2C_Switch
IFB-40004 PwFusion_I2C_Buttons:     https://github.com/PlayingWithFusion/PwFusion_I2C_Buttons

Visit https://www.playingwithfusion.com/ for more information.
