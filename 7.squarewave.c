// Program to generate Square Wave
#include<P18F4550.h>
void delay_timer (){
    TOCON=0x08; // Timer 0, 16 bit, no prescalar
    TMR0H=0xFB: // Values calculated for 0.1 ms delay
    TMR0L 0x50;
    TOCON.TMR0ON=1: // Timer 0 On
    while(INTCON.TMR0IF==0); // Wait until TMROIF gets flagged
    T0CON.TMR0ON=0; // Timer 0 Off
    INTCON.TMR0IF=0; // Clear Timer 0 interrupt flag
}

void main(){
    TRISC.RC0=0: // Configure PORTC as output
    
    While(1){
        PORTC.RC0=1
        delay_timer();
        PORTC.RC0=0
        delay_timer();
    }
} 