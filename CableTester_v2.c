/*
 * Project name:
     Cable Tester
 * Description:
     This code demonstrates how to use LCD 4-bit library. LCD is first
     initialized, then some text is written, then the text is moved.
 * Hardware configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     LCD:    		  Character Lcd 2x16
                      http://www.mikroe.com/store/components/various/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/mikroc/pic/
*/

// Lcd display connections
sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End Lcd display connections


bit cable0;
bit cable1;
bit cable2;
bit cable3;
bit cable4;
bit cable5;
bit cable6;
bit cable7;
bit cable8;
bit cable9;
bit cable10;
bit cable11;
bit cable12;
bit cable13;
bit cable14;
bit cable15;
bit cable16;
bit cable17;
bit cable18;
bit cable19;
bit cable20;
bit cable21;
bit cable22;
bit cable23;
bit cable24;
bit cable25;
bit cable26;


void main() {

  TRISA = 0;           // set direction to be output
  TRISB = 0;           // set direction to be output
  TRISC = 0;           // set direction to be output
  TRISD = 0;           // set direction to be output

  TRISG0_bit = 1;     // Input
  TRISG1_bit = 0;     // Output
  TRISG2_bit = 0;     // Output
  TRISG3_bit = 1;     // Input
  TRISG4_bit = 1;     // Input


// Disable AN Ports
ANCON0=0b00000000;
ANCON1=0b00000000;
ANCON2=0b00000000;
CM1CON=0;
CM2CON=0;
CM3CON=0;
  
   // Set Button connections
   TRISJ0_bit = 1;             //Set RJ0 as input
   LATJ0_bit = 0;              //Initial RC0 value
   TRISJ1_bit = 1;
   LATJ1_bit = 0;
   TRISJ2_bit = 1;
   LATJ2_bit = 0;
   TRISJ3_bit = 1;
   LATJ3_bit = 0;
   TRISJ4_bit = 1;
   LATJ4_bit = 0;
   TRISJ5_bit = 1;
   LATJ5_bit = 0;
   TRISJ6_bit = 1;
   LATJ6_bit = 0;
   TRISJ7_bit = 1;
   LATJ7_bit = 0;


   Lcd_Init();
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_CURSOR_OFF);
   Lcd_Out(1, 4, "Select cable");
   Delay_ms(500);



   do {

cable0 = 0;
cable1 = 0;
cable2 = 0;
cable3 = 0;
cable4 = 0;
cable5 = 0;
cable6 = 0;
cable7 = 0;
cable8 = 0;
cable9 = 0;
cable10 = 0;
cable11 = 0;
cable12 = 0;
cable13 = 0;
cable14 = 0;
cable15 = 0;
cable16 = 0;
cable17 = 0;
cable18 = 0;
cable19 = 0;
cable20 = 0;
cable21 = 0;
cable22 = 0;
cable23 = 0;
cable24 = 0;
cable25 = 0;
cable26 = 0;

PORTA.F0 = 0x00;
PORTA.F1 = 0x00;
PORTA.F2 = 0x00;
PORTA.F3 = 0x00;
PORTA.F4 = 0x00;
PORTA.F5 = 0x00;
PORTA.F6 = 0x00;
PORTA.F7 = 0x00;
PORTC.F0 = 0x00;
PORTC.F1 = 0x00;
PORTC.F2 = 0x00;
PORTC.F3 = 0x00;
PORTC.F4 = 0x00;
PORTC.F5 = 0x00;
PORTC.F6 = 0x00;
PORTC.F7 = 0x00;
PORTD.F0 = 0x00;
PORTD.F1 = 0x00;
PORTD.F2 = 0x00;
PORTD.F3 = 0x00;
PORTD.F4 = 0x00;
PORTD.F5 = 0x00;
PORTD.F6 = 0x00;
PORTD.F7 = 0x00;
PORTG.F1 = 0x00;
PORTG.F2 = 0x00;

        // GDSP Cable test / 4 wire / button on RJ0
        if (Button(&PORTJ, 0, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "4 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 ) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 ) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 ) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 ) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // END of GDSP Cable test / 4 wire / button on RJ0
        

// -----------------------------------------------------------//

        
        // 8 pin Cable test / button on RJ1
        if (Button(&PORTJ, 1, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "8 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 && 
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 ) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 ) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 ) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 ) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

//  Cable Pin 5 Test
         PORTA.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==1  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 ) {
            cable4 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F4 = 0x00;    // set PIN Low
// END Cable Pin 5 Test

//  Cable Pin 6 Test
         PORTA.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==1 && PortE.B6==0 && PortE.B7==0 ) {
            cable5 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F5 = 0x00;    // set PIN Low
// END Cable Pin 6 Test

//  Cable Pin 7 Test
         PORTB.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==1 && PortE.B7==0 ) {
            cable6 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F6 = 0x00;    // set PIN Low
// END Cable Pin 7 Test

//  Cable Pin 8 Test
         PORTB.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==1 ) {
            cable7 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F7 = 0x00;    // set PIN Low
// END Cable Pin 8 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1 && cable4==1 && cable5==1 && cable6==1 && cable7==1) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // 8 pin Cable test / button on RJ1
        
        
// -----------------------------------------------------------//

        // 14 pin Cable test / button on RJ2
        if (Button(&PORTJ, 2, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "14 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B5==0) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

//  Cable Pin 5 Test
         PORTA.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==1  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable4 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F4 = 0x00;    // set PIN Low
// END Cable Pin 5 Test

//  Cable Pin 6 Test
         PORTA.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==1 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable5 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F5 = 0x00;    // set PIN Low
// END Cable Pin 6 Test

//  Cable Pin 7 Test
         PORTB.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==1 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable6 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F6 = 0x00;    // set PIN Low
// END Cable Pin 7 Test

//  Cable Pin 8 Test
         PORTB.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==1 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable7 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F7 = 0x00;    // set PIN Low
// END Cable Pin 8 Test

//  Cable Pin 9 Test
         PORTC.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==1  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable8 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F0 = 0x00;    // set PIN Low
// END Cable Pin 9 Test

//  Cable Pin 10 Test
         PORTC.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==1 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable9 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F1 = 0x00;    // set PIN Low
// END Cable Pin 10 Test

//  Cable Pin 11 Test
         PORTC.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==1 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0) {
            cable10 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F2 = 0x00;    // set PIN Low
// END Cable Pin 11 Test

//  Cable Pin 12 Test
         PORTC.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==1 &&
            PortF.B5==0 && PortF.B6==0) {
            cable11 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F3 = 0x00;    // set PIN Low
// END Cable Pin 12 Test

//  Cable Pin 13 Test
         PORTC.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==1 && PortF.B6==0) {
            cable12 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F4 = 0x00;    // set PIN Low
// END Cable Pin 13 Test

//  Cable Pin 14 Test
         PORTC.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==1) {
            cable13 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F5 = 0x00;    // set PIN Low
// END Cable Pin 14 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1 && cable4==1 &&
            cable5==1 && cable6==1 && cable7==1 && cable8==1 && cable9==1 &&
            cable10==1 && cable11==1 && cable12==1 && cable13==1) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // 14 pin Cable test / button on RJ2


// -----------------------------------------------------------//

        // 15 pin Cable test / button on RJ3
        if (Button(&PORTJ, 3, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "15 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B5==0 && PortF.B7==0) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

//  Cable Pin 5 Test
         PORTA.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==1  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable4 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F4 = 0x00;    // set PIN Low
// END Cable Pin 5 Test

//  Cable Pin 6 Test
         PORTA.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==1 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable5 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F5 = 0x00;    // set PIN Low
// END Cable Pin 6 Test

//  Cable Pin 7 Test
         PORTB.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==1 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable6 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F6 = 0x00;    // set PIN Low
// END Cable Pin 7 Test

//  Cable Pin 8 Test
         PORTB.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==1 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable7 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F7 = 0x00;    // set PIN Low
// END Cable Pin 8 Test

//  Cable Pin 9 Test
         PORTC.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==1  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable8 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F0 = 0x00;    // set PIN Low
// END Cable Pin 9 Test

//  Cable Pin 10 Test
         PORTC.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==1 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable9 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F1 = 0x00;    // set PIN Low
// END Cable Pin 10 Test

//  Cable Pin 11 Test
         PORTC.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==1 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable10 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F2 = 0x00;    // set PIN Low
// END Cable Pin 11 Test

//  Cable Pin 12 Test
         PORTC.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==1 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0) {
            cable11 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F3 = 0x00;    // set PIN Low
// END Cable Pin 12 Test

//  Cable Pin 13 Test
         PORTC.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==1 && PortF.B6==0 && PortF.B7==0) {
            cable12 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F4 = 0x00;    // set PIN Low
// END Cable Pin 13 Test

//  Cable Pin 14 Test
         PORTC.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==1 && PortF.B7==0) {
            cable13 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F5 = 0x00;    // set PIN Low
// END Cable Pin 14 Test

//  Cable Pin 15 Test
         PORTC.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==1) {
            cable14 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F6 = 0x00;    // set PIN Low
// END Cable Pin 15 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1 && cable4==1 &&
            cable5==1 && cable6==1 && cable7==1 && cable8==1 && cable9==1 &&
            cable10==1 && cable11==1 && cable12==1 && cable13==1&& cable14==1 ) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // 15 pin Cable test / button on RJ4
        
// -----------------------------------------------------------//

        // 25 pin Cable test / button on RJ3
        if (Button(&PORTJ, 4, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "25 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 && 
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 && 
            PortH.B7==0 && PortG.B3==0 ) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B5==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

//  Cable Pin 5 Test
         PORTA.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==1  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable4 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F4 = 0x00;    // set PIN Low
// END Cable Pin 5 Test

//  Cable Pin 6 Test
         PORTA.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==1 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable5 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F5 = 0x00;    // set PIN Low
// END Cable Pin 6 Test

//  Cable Pin 7 Test
         PORTB.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==1 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable6 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F6 = 0x00;    // set PIN Low
// END Cable Pin 7 Test

//  Cable Pin 8 Test
         PORTB.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==1 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable7 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F7 = 0x00;    // set PIN Low
// END Cable Pin 8 Test

//  Cable Pin 9 Test
         PORTC.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==1  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable8 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F0 = 0x00;    // set PIN Low
// END Cable Pin 9 Test

//  Cable Pin 10 Test
         PORTC.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==1 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable9 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F1 = 0x00;    // set PIN Low
// END Cable Pin 10 Test

//  Cable Pin 11 Test
         PORTC.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==1 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable10 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F2 = 0x00;    // set PIN Low
// END Cable Pin 11 Test

//  Cable Pin 12 Test
         PORTC.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==1 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable11 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F3 = 0x00;    // set PIN Low
// END Cable Pin 12 Test

//  Cable Pin 13 Test
         PORTC.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==1 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable12 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F4 = 0x00;    // set PIN Low
// END Cable Pin 13 Test

//  Cable Pin 14 Test
         PORTC.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==1 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable13 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F5 = 0x00;    // set PIN Low
// END Cable Pin 14 Test

//  Cable Pin 15 Test
         PORTC.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==1 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable14 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F6 = 0x00;    // set PIN Low
// END Cable Pin 15 Test

//  Cable Pin 16 Test
         PORTC.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==1 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable15 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F7 = 0x00;    // set PIN Low
// END Cable Pin 16 Test

//  Cable Pin 17 Test
         PORTD.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==1 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable16 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F0 = 0x00;    // set PIN Low
// END Cable Pin 17 Test

//  Cable Pin 18 Test
         PORTD.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==1 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable17 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F1 = 0x00;    // set PIN Low
// END Cable Pin 18 Test

//  Cable Pin 19 Test
         PORTD.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==1 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable18 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F2 = 0x00;    // set PIN Low
// END Cable Pin 19 Test

//  Cable Pin 20 Test
         PORTD.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==1 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable19 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F3 = 0x00;    // set PIN Low
// END Cable Pin 20 Test

//  Cable Pin 21 Test
         PORTD.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==1 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable20 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F4 = 0x00;    // set PIN Low
// END Cable Pin 21 Test

//  Cable Pin 22 Test
         PORTD.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==1 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable21 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F5 = 0x00;    // set PIN Low
// END Cable Pin 22 Test

//  Cable Pin 23 Test
         PORTD.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==1 &&
            PortH.B7==0 && PortG.B3==0 ) {
            cable22 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F6 = 0x00;    // set PIN Low
// END Cable Pin 23 Test

//  Cable Pin 24 Test
         PORTD.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==1 && PortG.B3==0 ) {
            cable23 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F7 = 0x00;    // set PIN Low
// END Cable Pin 24 Test

//  Cable Pin 25 Test
         PORTG.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==1 ) {
            cable24 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTG.F1 = 0x00;    // set PIN Low
// END Cable Pin 25 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1 && cable4==1 &&
            cable5==1 && cable6==1 && cable7==1 && cable8==1 && cable9==1 &&
            cable10==1 && cable11==1 && cable12==1 && cable13==1 && cable14==1 && 
            cable15==1  && cable16==1 && cable17==1 && cable18==1 && cable19==1 &&
            cable20==1  && cable21==1 && cable22==1 && cable23==1 && cable24==1 ) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // 25 pin Cable test / button on RJ4

// -----------------------------------------------------------//

        // 26 pin Cable test / button on RJ3
        if (Button(&PORTJ, 5, 50, 1)) {  // Detect logical one
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 4, "26 Pin Cable");
            Lcd_Out(2, 5, "Testing...");
//  Cable Pin 1 Test
         PORTA.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==1 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable0 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F0 = 0x00;    // set PIN Low
// END Cable Pin 1 Test

//  Cable Pin 2 Test
         PORTA.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==1 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable1 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F1 = 0x00;    // set PIN Low
// END Cable Pin 2 Test

//  Cable Pin 3 Test
         PORTA.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==1 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B5==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable2 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F2 = 0x00;    // set PIN Low
// END Cable Pin 3 Test

//  Cable Pin 4 Test
         PORTA.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
            if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==1 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable3 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F3 = 0x00;    // set PIN Low
// END Cable Pin 4 Test

//  Cable Pin 5 Test
         PORTA.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==1  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable4 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F4 = 0x00;    // set PIN Low
// END Cable Pin 5 Test

//  Cable Pin 6 Test
         PORTA.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==1 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable5 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTA.F5 = 0x00;    // set PIN Low
// END Cable Pin 6 Test

//  Cable Pin 7 Test
         PORTB.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==1 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable6 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F6 = 0x00;    // set PIN Low
// END Cable Pin 7 Test

//  Cable Pin 8 Test
         PORTB.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==1 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable7 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTB.F7 = 0x00;    // set PIN Low
// END Cable Pin 8 Test

//  Cable Pin 9 Test
         PORTC.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==1  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable8 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F0 = 0x00;    // set PIN Low
// END Cable Pin 9 Test

//  Cable Pin 10 Test
         PORTC.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==1 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable9 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F1 = 0x00;    // set PIN Low
// END Cable Pin 10 Test

//  Cable Pin 11 Test
         PORTC.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==1 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable10 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F2 = 0x00;    // set PIN Low
// END Cable Pin 11 Test

//  Cable Pin 12 Test
         PORTC.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==1 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable11 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F3 = 0x00;    // set PIN Low
// END Cable Pin 12 Test

//  Cable Pin 13 Test
         PORTC.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==1 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable12 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F4 = 0x00;    // set PIN Low
// END Cable Pin 13 Test

//  Cable Pin 14 Test
         PORTC.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==1 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable13 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F5 = 0x00;    // set PIN Low
// END Cable Pin 14 Test

//  Cable Pin 15 Test
         PORTC.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==1 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable14 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F6 = 0x00;    // set PIN Low
// END Cable Pin 15 Test

//  Cable Pin 16 Test
         PORTC.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==1 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable15 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTC.F7 = 0x00;    // set PIN Low
// END Cable Pin 16 Test

//  Cable Pin 17 Test
         PORTD.F0 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==1 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable16 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F0 = 0x00;    // set PIN Low
// END Cable Pin 17 Test

//  Cable Pin 18 Test
         PORTD.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==1 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable17 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F1 = 0x00;    // set PIN Low
// END Cable Pin 18 Test

//  Cable Pin 19 Test
         PORTD.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==1 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable18 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F2 = 0x00;    // set PIN Low
// END Cable Pin 19 Test

//  Cable Pin 20 Test
         PORTD.F3 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==1 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable19 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F3 = 0x00;    // set PIN Low
// END Cable Pin 20 Test

//  Cable Pin 21 Test
         PORTD.F4 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==1 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable20 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F4 = 0x00;    // set PIN Low
// END Cable Pin 21 Test

//  Cable Pin 22 Test
         PORTD.F5 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==1 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable21 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F5 = 0x00;    // set PIN Low
// END Cable Pin 22 Test

//  Cable Pin 23 Test
         PORTD.F6 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==1 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==0 ) {
            cable22 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F6 = 0x00;    // set PIN Low
// END Cable Pin 23 Test

//  Cable Pin 24 Test
         PORTD.F7 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==1 && PortG.B3==0 && PortG.B4==0 ) {
            cable23 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTD.F7 = 0x00;    // set PIN Low
// END Cable Pin 24 Test

//  Cable Pin 25 Test
         PORTG.F1 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==1 && PortG.B4==0 ) {
            cable24 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTG.F1 = 0x00;    // set PIN Low
// END Cable Pin 25 Test

//  Cable Pin 26 Test
         PORTG.F2 = 0xFF;    // set PIN High
         Delay_ms(50);      // wait
           if ( PortE.B0==0 && PortE.B1==0 && PortE.B2==0 && PortE.B3==0 &&
            PortE.B4==0  && PortE.B5==0 && PortE.B6==0 && PortE.B7==0 &&
            PortF.B1==0  && PortF.B2==0 && PortF.B3==0 && PortF.B4==0 &&
            PortF.B5==0 && PortF.B6==0 && PortF.B7==0 &&
            PortG.B0==0 && PortH.B0==0 && PortH.B1==0 && PortH.B2==0 &&
            PortH.B3==0 && PortH.B4==0 && PortH.B5==0 && PortH.B6==0 &&
            PortH.B7==0 && PortG.B3==0 && PortG.B4==1 ) {
            cable25 = 1;        // set flag
            }
         Delay_ms(50);      // wait
         PORTG.F2 = 0x00;    // set PIN Low
// END Cable Pin 26 Test

            if ( cable0==1 && cable1==1 && cable2==1 && cable3==1 && cable4==1 &&
            cable5==1 && cable6==1 && cable7==1 && cable8==1 && cable9==1 &&
            cable10==1 && cable11==1 && cable12==1 && cable13==1 && cable14==1 &&
            cable15==1  && cable16==1 && cable17==1 && cable18==1 && cable19==1 &&
            cable20==1  && cable21==1 && cable22==1 && cable23==1 && cable24==1 && cable25==1 ) {
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Cmd(_LCD_CURSOR_OFF);
            Lcd_Out(1, 6, "Test OK");
            Delay_ms(500);
            }

              else {
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
                 Lcd_Cmd(_LCD_CLEAR);
                 Lcd_Cmd(_LCD_CURSOR_OFF);
                 Delay_ms(200);
                 Lcd_Out(1, 3, "!!! ERROR !!!");
                 Delay_ms(200);
              }

        }
        // 26 pin Cable test / button on RJ4

// -----------------------------------------------------------//
        
   }  while (1);
 }