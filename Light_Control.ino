#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define LDR  A1  //LDR Sensor Pin (Photoresistor or Light Dependent Resistor)

#define relay 0 // For the Light

int read_l =0;
int brightness;

void setup(){

pinMode(LDR, INPUT);

pinMode(relay, OUTPUT);

lcd.begin(16,2);  
lcd.setCursor(0,0);
lcd.print(" This is a");
lcd.setCursor(0,1);
lcd.print("Smart Light");
delay(2000); 
lcd.clear();
}

void loop(){   
read_l = analogRead(LDR); // read analogue to digital value 0 to 1023
brightness = read_l /10.23; //Analog to digitl value cannot exceed 1023

lcd.setCursor(0, 0);
lcd.print(" Brightness: ");
lcd.print(brightness);
lcd.print("%  ");
lcd.setCursor(0,1); 
lcd.print("  Light is ");

if(brightness<30){digitalWrite(relay,HIGH); lcd.print(" ON");}
if(brightness>60){digitalWrite(relay,LOW);  lcd.print("OFF");}

delay(100); 
}
