#include "LPC17xx.h"

void init_timer2()
{
	LPC_PINCON->PINSEL0 |= (0x3<<16);						   	//Select PIN0.8 as MAT2.2
	LPC_SC->PCLKSEL1 |= (0x3<<12);									//Select Peripheral clock as cpu clock(1/8)
	LPC_TIM2->PR = 0;
	LPC_TIM2->MR2 = 200;
	LPC_TIM2->MCR = (0x2<<6);										  	//To set without intrrupt & reset
	LPC_TIM2->EMR = (3<<8);											  	//To toggle MR2
}

int main()
{
 	init_timer2();
	LPC_TIM2->TCR = 1;
	while(1){}
	return 0;
}