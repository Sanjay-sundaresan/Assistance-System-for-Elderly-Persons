#include<LiquidCrystal.h>
int A = 0;
int B;
int sensorpin = A0;
int AC = 13;
int min_t = 25;
LiquidCrystal lcd(12,11,5,4,3,2); //Initializing LCD

void setup() {
  lcd.begin(16, 2);
  pinMode(AC, OUTPUT);
}

void loop() {
  //lcd.clear();
  A = analogRead(sensorpin);
  B = A/2;
  if(B < min_t){
    digitalWrite(AC, LOW);
    lcd.setCursor(0,0);
    lcd.print("Normal: AC OFF."); 
  } 
  if(B > min_t){
    digitalWrite(AC, HIGH);
    lcd.setCursor(0,0);
    lcd.print("High: AC IS ON."); 
  }

}
