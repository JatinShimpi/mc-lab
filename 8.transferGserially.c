// Write a C program for the PIC18 to transfer the letter 'G' serially at 9600 baud,
// continuously. Use 8-bit data and 1 stop bit. Assume XTAL = 10 MHz.
#include <P18F4520.h>
void main(void)
{
    TXSTA=0x20; //choose low baud rate, 8-bit
    SPBRG=15; //9600 baud rate/ XTAL 10 MHz
    TXSTAbits.TXEN=1; // Enable transmission
    RCSTAbits.SPEN=1; // Enable serial port (configures TX/CK pins)
    
    while (1){
    TXREG='G'; //place value in buffer
        while (PIR1bits.TXIF==0); //wait until all gone
    }
} 
