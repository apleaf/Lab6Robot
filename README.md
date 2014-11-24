Lab6Robot
=========

ROBOT

**###Functionality**
Requiered Functionality Checked by Dr. Coulston 24 November

##Pre Lab
**Consider your hardware (timer subsystems, chip pinout, etc.) and how you will use it to achieve robot control.**

-I will use compare and an output mode 7: reset/set to generate my two PWM signal. I will use pins 3,4, and 6 to generatet he PWM signals.  One will go to one input on the motor driver, one will go to another input on the motor driver, and the other will go to the 1,2 en on the motor driver which will choose if one, or both wheels are receiving power.

**Which pins will output which signals you need?**

-Motor A, the right motor, will use pin P1.1 and I will chosoe the TA0.0 signal to be output from that pin, and motor B, the left motor will use pin P1.2 with TA0.1 as the output.  

**How will you use these signals to achieve forward / back / left / right movement?**

-I plan on outputting two PWM signals, one for each wheel.

-When I want the robot to go forward, I will use SET both PWM signals to the wheels and the 1,2 EN signal to make sure both signals are being transmitted to the wheels.  When I want one of them to move and cause the robot to turn, I will have one of the PWM signals SET and the other REST, causing only one wheel to turn

**Consider what additional hardware you'll need (regulator, motor driver chip, decoupling capacitor, etc.) and how you'll configure / connect it.**

-	I will need the voltage regulator to downstep the voltage from the battery to power the MSP430.  My motor driver chip will have 3 inputs, which are shown in my schematic diagram.  One input for each motor, and another input to choose between the two signals (1,2EN).  The decoupling capacitor will go on the voltage supply to prevent any overpowering when a voltage spike happens, which could either short out the device or cause a reset to happen.


**Methods to be used**

-moveForward
-moveBackward
-lessThan45Left
-lessThan45Right
-moreThan45Left
-moreThan45Right

####Hardware Schematic
![alt text](http://i61.tinypic.com/2vxoyrt.png)



