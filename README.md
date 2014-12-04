Lab6Robot
=========

ROBOT

###**Functionality**
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
-turnBigLeft
-turnSmallRight
-turnSmallLeft
-turnBigRight

####Hardware Schematic
![alt text](http://i61.tinypic.com/2vxoyrt.png)

After realizing I still did not fully understand what I was doing in the lab, I went in for EI with Captain Trimble and we talked about what I needed to to to turn the wheels.  Chaning my initial plan, I decided to go with sending two pulse with modulation signals to each wheel, using set/reset and set to vary the PWM signal depending on what I wanted the robot to do.  An updated final schematic is below.


**Debugging**
I did not have much trouble figuring out the code, but I struggled hooking up the robot correctly.  I hooked up my wires and everything and ran my code on C2C Cabusora's robot, and it worked fine.  So i figured out that i must have connected everything wrong on my robot, or their wasa component broken.  I troubleshooted some more and realized I did not have a ground hooked up correctly for the MSP.  But even fixing that did not solve my problem.  I grabbed a voltemeter and measured the voltage input at the voltage regulator, and it only measured 2 volts, so i realized it must be a component on the robot broken that I did not hook up.  I measured the resistances of the fuses and one of them showed 2.3M ohms.  This was the problem.  Mr. Evans put in a new fuse for me, and turning the robot on worked perfectly.  

**Testing Methodology/Results**
Testing my robot I ran a while loop that put the robot through all of its motions, forward, backward, small left, big left, small right, and big right.  The robot worked and I demonstrated my functionality to Dr. Coulston.

**Observations and Conclusions**
Contrary to what my first thoughts were, the hardware gave me a lot more trouble than the software.  If I had a question on the software, I could just ask an instructor to take a quick look at it to make sure I wrote it correctly or had the right idea.  For example, Dr. Coulston looked at my code one and explained how I was setting the wrong signal.  After that, I simply changed a few lines in the code.  Hardware was not so easy.  When the robot didnt work there were so many things to check.  A part such as a capacitor or the motor driver could have gone bad, the MSP430 chip could have been blow, or like in my case a fuse could have gotten burnt up.  This lab showed me the valuability of methodically going through the robot piece by piece and having a plan.  I did not go into it with this mindset and spent far more time troubleshooting my hardware than I did my software.

Documentation: Dr. Coulston helped me troubleshoot some of my code and made sure I was getting correct PWM signals.  Captain Trimble helped me with my pre lab and helped me troubleshoot my hardware and gave me the idea of checking my fuses because they might be blown.  C2C Kevin Cabusora helped me initially understand what I needed to connect on my robot, such as where the capacitors went.  



