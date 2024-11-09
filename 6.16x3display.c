// Draw and explain interfacing of 16x2 LCD with PIC18FXXX microcontroller in 8-bit
// mode and also write an Embedded C Program to display word "SPPU".
#include<p18f4520.h>
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF
//Function Prototype declaration
void lcdcmd (unsigned char value) ;
void lcddata (unsigned char value);
void msdelay(unsigned int itime);
#define ldata PORTD //Declare ldata variable for PORTD
#define rs PORTEbits.RE0 //Declare rs variable for pin RE0
#define rw PORTEbits.RE1 //Declare rw variable for pin RE1
#define en PORTEbits.RE2 //Declare en variable for pin RE2
void main(){
TRISD = 0x00; //Set direction of PORTD as output
TRISE=0X00; //set direction of PORTE as output
msdelay(50);
lcdcmd(0x38); //16x2 LCD
msdelay(50);
lcdcmd(0x0E); // Display on Cursor on
msdelay(15);
lcdcmd(0x01); //clear Display screen
msdelay(15);
lcdcmd(0x06); //Increment cursor and shift right
msdelay(15);
lcdcmd(0x80); //Force cursor on first row first position
lcddata('S'); //Display character 'S'
msdelay(50);
lcddata('P'); //Display character 'P'
msdelay(50);
lcddata('P'); //Display character 'P'
msdelay(50);
lcddata('U'); //Display character 'U'
msdelay(50);
lcdcmd(0xC0); //NEXT LINE
msdelay(15);
lcddata('S'); //Display character 'S'
msdelay(50);
lcddata('I'); //Display character 'P'
msdelay(50);
lcddata('T'); //Display character 'P'
msdelay(50);
lcddata('S'); //Display character 'U'
msdelay(50);
}
void lcdcmd (unsigned char value)
{
ldata=value; //Send the command value to PORTD
rs=0; //selection of command register of LCD
rw=0; // write mode is selected
en=1; //Generate High to Low pulse on Enable pin
msdelay(1);
en=0;
}
void lcddata (unsigned char value)
{
ldata=value; //Send the command value to PORTD
rs=1; //selection of DATA register of LCD
rw=0; // write mode is selected
en=1; //Generate High to Low pulse on Enable pin
msdelay(1);
en=0;
}
void msdelay (unsigned int itime)
{
int i,j;
for(i=0;i<itime;i++)
for(j=0;j<135;j++);
} 