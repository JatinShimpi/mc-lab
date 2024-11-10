#include <p18f4550.h>

#pragma config FOSC = HS      // High-speed oscillator
#pragma config WDT = OFF      // Watchdog Timer disabled
#pragma config LVP = OFF      // Low Voltage Programming disabled

void PWM_Init(unsigned int duty);

void main(void) {
    TRISCbits.TRISC2 = 0;    // Set RC2 as output for PWM signal
    PWM_Init(512);           // Initialize PWM with 50% duty cycle (512 out of 1023)

    while (1) {
        // The motor will run continuously with a 50% duty cycle
        // You can change the duty cycle by calling PWM_Init with a different value
    }
}

void PWM_Init(unsigned int duty) {
    PR2 = 0xFF;              // Set the PWM period to maximum (~490 Hz)
    CCP1CON = 0x0C;          // Set CCP1 in PWM mode
    T2CON = 0x04;            // Timer2 on with 1:1 prescaler

    // Set PWM duty cycle
    CCPR1L = duty >> 2;                // Load the 8 most significant bits
    CCP1CONbits.DC1B = duty & 0x03;    // Load the 2 least significant bits

    T2CONbits.TMR2ON = 1;    // Start Timer2, which enables the PWM
}
