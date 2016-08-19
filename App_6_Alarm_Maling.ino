/*-----------------------------------------------------
'     APLIKASI 6
'     ALARM ANTI MALING
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     BUZER --> pin 11
'     Hasilnya tampilkan ke LCD

'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5,6,7);
unsigned int jarak, timer;

void setup(){
  lcd.begin(16, 2);
  lcd.print("      ALARM  ");
  lcd.setCursor(0, 1);
  lcd.print("  ANTI MALING  ");
  delay(2000);
  lcd.clear();
  lcd.print("Kondisi=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
 
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  if(jarak<100) {
      lcd.setCursor(8, 0);
      lcd.print("Bahaya"); 
       digitalWrite(10,1);
        digitalWrite(11,1);
        delay(50);   
        digitalWrite(11,0);
        delay(50); 
      }
  
   else{
       lcd.setCursor(8, 0);
       lcd.print("Aman"); 
       digitalWrite(10,0);
       delay(500);
   }
}

