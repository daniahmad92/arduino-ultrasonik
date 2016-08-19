/*-----------------------------------------------------
'     APLIKASI 7
'     KRAN OTOMATIS
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     Relay --> Pin 10
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                          
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5,6,7);
unsigned int jarak, timer;

void setup(){
  lcd.begin(16, 2);
  lcd.print("KRAN OTOMATIS ");
  lcd.setCursor(0, 1);
  lcd.print("Kondisi=");
  delay(2000);
   
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(10, OUTPUT);
 
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  if(jarak<10) {
      lcd.setCursor(8, 1);
      lcd.print("Open  "); 
      digitalWrite(10,1);
  }
   else{
       lcd.setCursor(8, 1);
       lcd.print("Closed"); 
       digitalWrite(10,0);
   }
   delay(100);
}

