#include<reg51.h>
void T1M1Delay(void);
void main (void)
{
 unsigned char x;
 P2=0x55;
 while(1) // infinite loop
 {
 P2=~P2; //toggle all bits of P2
P3 = 0x00;
 for(x=0; x<20;x++)
 T1M1Delay();
 }
} 
void T1M1Delay(void)
{
 TMOD= 0X10; // TIMER 1 MODE 1 (16 BIT)
 TL1= 0XFE; //LOAD TL1
 TH1=0XA5; //LOAD TH1
 TR1=1; // START TIMER 1
 while(TF1==0); //WAIT TILL TF1 TO ROLL OVER
 TR1=0; //STOP TIMER
 TF1=0; // RESET FLAG
} 