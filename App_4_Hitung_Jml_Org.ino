/*-----------------------------------------------------
'     APLIKASI 4
'     PENGHITUNG JUMLAH ORANG
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5,6,7);
unsigned int jarak,timer,Jml;
void setup(){
  lcd.begin(16, 2);
  lcd.print("   PENGHITUNG  ");
  lcd.setCursor(0, 1);
  lcd.print("  JUMLAH ORANG");
  delay(2000);
  lcd.clear();
  lcd.print("Jumlah=");
  
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
  if (jarak<20){
      Jml++;
      lcd.setCursor(7,0);
      lcd.print(Jml);
  }
  delay(500);
 
}

