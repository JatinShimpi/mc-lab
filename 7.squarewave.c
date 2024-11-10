#include <p18f4550.h>

void delay_timer() {
    T0CON = 0x08;        // Timer 0, 16-bit mode, no prescaler
    TMR0H = 0xFB;        // Set high byte for 0.1 ms delay
    TMR0L = 0x50;        // Set low byte for 0.1 ms delay
    T0CONbits.TMR0ON = 1; // Timer 0 On
    while (INTCONbits.TMR0IF == 0); // Wait until TMR0IF is set
    T0CONbits.TMR0ON = 0; // Timer 0 Off
    INTCONbits.TMR0IF = 0; // Clear Timer 0 interrupt flag
}

void main() {
    TRISCbits.RC0 = 0; // Configure RC0 as output

    while (1) {
        PORTCbits.RC0 = 1;
        delay_timer();
        PORTCbits.RC0 = 0;
        delay_timer();
    }
}
