/*-----------------------------------------------------
'     APLIKASI 1
'     ULTRASONIC RANGE METER
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
unsigned int jarak, timer;

void setup(){
  lcd.begin(16, 2);
  lcd.print("   ULTRASONIC");
  lcd.setCursor(0, 1);
  lcd.print("  RANGE METER");
  delay(2000);
  lcd.clear();
  lcd.print("Range=");
  
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
                      
  lcd.setCursor(6, 0);
  lcd.print(jarak); 
  lcd.print(" cm ");
  delay(1000);    
}

