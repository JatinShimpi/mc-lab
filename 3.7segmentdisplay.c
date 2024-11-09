#include <reg51.h>
#define SEGMENT_PORT P2 // Define the port connected to the 7-segment display
// Segment values for digits 0 to 9
unsigned char segment_code[10] = {0x3F,0x06,0x5E,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void delay(unsigned int ms)
 {
 unsigned int i, j;
 for (i = 0; i < ms; i++)
{
 for (j = 0; j < 1275; j++);
 }
}
void main() {
 unsigned char i;
 while (1)
{
 for (i = 0; i < 10; i++)
 {
 SEGMENT_PORT = segment_code[i]; // Send the segment code to the port
 delay(1000); // Delay for 1 second
 }
 }
}