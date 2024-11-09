Case 1: // Full drive Mode
#include<reg51.h>
void msdelay(unsigned int time)
 {
 unsigned i,j ;
 for(i=0;i<time;i++)
 for(j=0;j<1275;j++);
 }
void main()
{
 while(1)
 {
 P2 = 0x03; //0011 P2_0=1,P2_1=1,P2_2=0,P2_3=0
 msdelay(1);
 P2 = 0x06; //0110
 msdelay(1);
 P2 = 0x0C; //1100
 msdelay(1);
 P2 = 0x09; //1001
 msdelay(1);
 }
}


Case 2:
#include <reg51.h>
sbit LED_pin = P2^0; // Set the LED pin as P2.0
void delay(int ms) {
 unsigned int i, j;
 for(i = 0; i < ms; i++) { // Outer for loop for given milliseconds value
 for(j = 0; j < 1275; j++) {
 // Execute in each millisecond;
 } 
 }
}
void main() {
 unsigned char rot_angle[] = {0x0C, 0x06, 0x03, 0x09}; // Corrected array declaration
 int i;
 while(1) {
 for(i = 0; i < 4; i++) { // Infinite loop for LED blinking
 P0 = rot_angle[i];
 delay(100);
 }
 }
} 