/*-----------------------------------------------------
'     APLIKASI 5
'     PENGHITUNG TINGGI BADAN
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                           
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 4, 6, 7,8,9);
unsigned int jarak,timer,Tinggi;
void setup(){
  lcd.begin(16, 2);
  lcd.print("   PENGHITUNG  " );
  lcd.setCursor(0, 1);
  lcd.print("  TINGGI BADAN");
  delay(2000);
  lcd.clear();
  lcd.print("Tinggi=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  
  if (jarak>200) jarak=200;
  Tinggi=200-jarak;
  lcd.setCursor(7,0);
  lcd.print(Tinggi);
  lcd.print(" cm ");
  delay(600);
  
}

