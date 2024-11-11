// Example code for setting up PWM on PIC18F4550
#include <p18f4550.h>

void PWM_Init(void) {
    // Set CCP1 pin as output
    TRISCbits.TRISC2 = 0;
    
    // Set up Timer2
    T2CON = 0x04; // Prescaler 1:1, Timer2 on
    PR2 = 255;    // PWM period
    
    // Configure CCP1 module for PWM mode
    CCP1CON = 0x0C;
    CCPR1L = 0x7F; // 50% duty cycle initially
    
    // Start Timer2
    T2CONbits.TMR2ON = 1;
}

void PWM_SetDutyCycle(unsigned int duty) {
    // Duty cycle is 10-bit, so we split it
    CCPR1L = duty >> 2;
    CCP1CONbits.DC1B = duty & 0x03;
}
void main() {
    PWM_Init();
    
    // Set direction pins (example: PORTB pins)
    TRISBbits.TRISB0 = 0; // Direction control pin 1
    TRISBbits.TRISB1 = 0; // Direction control pin 2
    
    while(1) {
        // Set direction
        LATBbits.LATB0 = 1;
        LATBbits.LATB1 = 0;
        
        // Control speed with PWM duty cycle
        PWM_SetDutyCycle(128); // 50% speed, for example
        
        // Add code to change speed or direction as needed
        Delay10KTCYx(100);
        
        // Change direction
        LATBbits.LATB0 = 0;
        LATBbits.LATB1 = 1;
        
        // Adjust speed
        PWM_SetDutyCycle(192); // 75% speed
        Delay10KTCYx(100);
    }
}
