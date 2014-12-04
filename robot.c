/*
 * robot.c
 *
 *
 *
 */
#include <msp430g2553.h>
#include "robot.h"

void initTimerOutputSignals()
{
	P1DIR|=BIT1; //TA0.0
	P1DIR|=BIT2; //TA0.1
	P2DIR|=BIT0; //TA1.0
	P2DIR|=BIT1; //TA1.1

	P1SEL|=BIT1;
	P1SEL|=BIT2;
	P2SEL|=BIT0;
	P2SEL|=BIT1;
}

void configureA0andA1Timers()
{
	TA0CTL &= ~MC1|MC0;

	TA0CTL |= TACLR;

	TA0CTL |= TASSEL1;

	TA1CTL &= ~MC1|MC0;

	TA1CTL |= TACLR;

	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;
	TA0CCR1 = 50;
	TA1CCR0 = 100;
	TA1CCR1 = 50;

	TA0CTL |= MC0;          // count up

	TA1CTL |= MC0;		    //count up
}

void clearModes()
{
	TA0CCTL1 &= ~OUTMOD_7;
	TA0CCTL0 &= ~OUTMOD_7;

	TA1CCTL1 &= ~OUTMOD_7;
	TA1CCTL0 &= ~OUTMOD_7;
}

void turnSmallRight()
{
	clearModes();
	TA0CCR1 = 30;
	TA1CCR1 = 30;
	TA0CCTL1 |= OUTMOD_5;        // TACCTL1 Reset mode
	TA0CCTL0 |= OUTMOD_7;		 // TACCTL0 Reset/Set

	TA1CCTL1 |= OUTMOD_7; //reset/set
	__delay_cycles(200000);
	clearModes();
}

void turnBigRight()
{
	clearModes();
	TA0CCR1 = 30;
	TA1CCR1 = 30;
	TA0CCTL1 |= OUTMOD_5;        //Reset
	TA0CCTL0 |= OUTMOD_7;		 //TACCTL0 to Reset/Set

	TA1CCTL1 |= OUTMOD_7; //reset/set
	__delay_cycles(300000);
	clearModes();
}

void turnSmallLeft()
{
	clearModes();
	TA0CCR1 = 30;
	TA1CCR1 = 30;
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_7;

	TA0CCTL1 |= OUTMOD_7;
	__delay_cycles(200000);
	clearModes();
}

void turnBigLeft()
{
	clearModes();
	TA0CCR1 = 30;
	TA1CCR1 = 30;
	TA1CCTL1 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_7;		 // set TACCTL0 to Reset

	TA0CCTL1 |= OUTMOD_7;
	__delay_cycles(300000);
	clearModes();
}

void moveForward()
{
	clearModes();
	TA0CCR1 = 50;
	TA1CCR1 = 50;
	TA1CCTL1 |= OUTMOD_7; //reset/set
	TA0CCTL1 |= OUTMOD_7; //reset/set
	__delay_cycles(900000);
	clearModes();
}

void moveBackward()
{
	clearModes();
	TA0CCR1 = 5;
	TA1CCR1 = 5;
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_7;
	TA0CCTL1 |= OUTMOD_5;
	TA0CCTL0 |= OUTMOD_7;
	__delay_cycles(500000);
	clearModes();
}

