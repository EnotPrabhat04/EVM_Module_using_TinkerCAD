
// i2c LCD Library 
// https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);
#define sw1 A0 // Button 1
#define sw2 A1 // Button 2
#define sw3 A2 // Button 3
#define sw4 A3 // Button 4
#define sw5 7 // Button 5 for result
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup()
{
pinMode(sw1, INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
pinMode(sw4,INPUT);
pinMode(sw5,INPUT);
pinMode(13,OUTPUT);// Red LED
pinMode(12,OUTPUT);// Green LED

lcd_1.begin(16, 2);
lcd_1.setCursor(0,0);
lcd_1.print("VOTING MACHINE ");
lcd_1.setCursor(0,1);
lcd_1.print("Circuit desigh ");
delay(3000);
digitalWrite(sw1, HIGH);
digitalWrite(sw2, HIGH);
digitalWrite(sw3, HIGH);
digitalWrite(sw4, HIGH);
digitalWrite(sw5, HIGH);
lcd_1.clear();
lcd_1.setCursor(0,0);
lcd_1.print("BJP");
lcd_1.setCursor(4,0);
lcd_1.print("INC");
lcd_1.setCursor(8,0);
lcd_1.print("AAP");
lcd_1.setCursor(12,0);
lcd_1.print("OTH");
}
void loop()
{
lcd_1.setCursor(0,0);
lcd_1.print("BJP");
lcd_1.setCursor(1,1);
lcd_1.print(vote1);
lcd_1.setCursor(4,0);
lcd_1.print("INC");
lcd_1.setCursor(5,1);
lcd_1.print(vote2);
lcd_1.setCursor(8,0);
lcd_1.print("AAP");
lcd_1.setCursor(9,1);
lcd_1.print(vote3);
lcd_1.setCursor(12,0);
lcd_1.print("OTH");
lcd_1.setCursor(13,1);
lcd_1.print(vote4);

if(digitalRead(sw1)==0)
{ 
vote1++;
  digitalWrite(12,HIGH);
 delay(500);
while(digitalRead(sw1)==0);
digitalWrite(12,LOW);
delay(1000);

}

if(digitalRead(sw2)==0)
{

vote2++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw2)==0);
digitalWrite(12,LOW);
delay(1000);

}

if(digitalRead(sw3)==0)
{

vote3++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw3)==0);
digitalWrite(12,LOW);
delay(1000);
}

if(digitalRead(sw4)==0)
{

vote4++;
  digitalWrite(12,HIGH);
  delay(500);
while(digitalRead(sw4)==0);
digitalWrite(12,LOW);
delay(1000 );
}

if(digitalRead(sw5)==0)
{
digitalWrite(13,HIGH);
int vote=vote1+vote2+vote3+vote4;
if(vote)
{
if((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
{
lcd_1.clear();
lcd_1.print("BJP Wins");
delay(5000);
lcd_1.clear();
}
else if((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
{
lcd_1.clear();
lcd_1.print("INC Wins");
delay(5000);
lcd_1.clear();
}
else if((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
{
lcd_1.clear();
lcd_1.print("AAP Wins");
delay(5000);
lcd_1.clear();
}
else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd_1.setCursor(0,0);
lcd_1.clear();
lcd_1.print("OTH Wins");
delay(5000);
lcd_1.clear();
}

else if(vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
{
lcd_1.setCursor(0,0);
lcd_1.clear();
lcd_1.print("OTH Wins");
delay(2000);
lcd_1.clear();
}

else
{
lcd_1.clear();
lcd_1.print(" Tie Up Or ");
lcd_1.setCursor(0,1);
lcd_1.print(" No Result ");
delay(5000);
lcd_1.clear();
}

}
else
{
lcd_1.clear();
lcd_1.setCursor(0,0);
lcd_1.print("  No Voting….         ");
delay(5000);
lcd_1.clear();
}
vote1=0;vote2=0;vote3=0;vote4=0,vote=0;
lcd_1.clear();
digitalWrite(12,LOW);
digitalWrite(13,LOW);
}

}
