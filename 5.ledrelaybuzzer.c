//Expt.4: Interfacing LEDs, Switches, Buzzer and Relay
//Includes
#include <p18f4520.h> //Include Controller specific .h
#include <delays.h>
//Declarations
#define BUZZER PORTAbits.RA3 //Buzzer connected to PORTA 3rd PIN
#define SWITCH0 PORTBbits.RB0 //Switch0 connected to PORTB 0th PIN
#define SWITCH1 PORTBbits.RB1 //Switch1 connected to PORTB 1st PIN
//Start of Program Code
void main(void)
{
 TRISA = 0x00; // RA3, Output Direction
 TRISB = 0xff; // RB0, B1 Input Direction
 TRISD = 0x00; // [RD0-3=LED’s] [RD4,5=Relay1,2] Output Direction
 PORTD = 0xff; // [RD0-3=LED’s] [RD4,5=Relay1,2] Initialise as 0xff
 while (1)
 {
 if(!SWITCH1) // Condition for 1st switch
 {
 while (1)
 {
 BUZZER =1; // Buzzer On
 PORTD = 0x37;// (Relay1=1, Relay2=1) & (LED's sequence Left to Right=0111=7)
 Delay10KTCYx(100); // 400mSDelay
 PORTD = 0x3B; // (LED's sequence Left to Right=1011=B)
 Delay10KTCYx(100);
 PORTD = 0x3D;
 Delay10KTCYx(100);
 PORTD = 0x3E;
 Delay10KTCYx(100);
 if(!SWITCH0) // check if 2nd switch is pressed
 break;
 }
 }
 else if(!SWITCH0) // Condition for 2nd switch
 {
 while (1)
 {
 BUZZER =0; // Buzzer Off
 PORTD = 0xcE; // (Relay1=0,Relay2=0) & (LED's sequence Right to Left=1110=E)
 Delay10KTCYx(100);
 PORTD = 0xcD; // LED's sequence Right to Left=1101=D
 Delay10KTCYx(100);
 PORTD = 0xcB;
 Delay10KTCYx(100);
 PORTD = 0xc7;
 Delay10KTCYx(100);
 if(!SWITCH1) // check if 1st switch is pressed
 break;
 }
 }
 }
}