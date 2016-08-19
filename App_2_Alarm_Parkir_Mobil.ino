/*-----------------------------------------------------
'     APLIKASI 2
'     ALARM PARKIR MOBIL
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     BUZZER --> Pin 11
'     Hasilnya tampilkan ke LCD
'  dadan ahmad dani
'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5,6,7);
int jarak,timer;
void setup(){
  lcd.begin(16, 2);
  lcd.print("   ALARM PARKIR");
  lcd.setCursor(0, 1);
  lcd.print("      MOBIL    ");
  delay(2000);
  lcd.clear();
  lcd.print("Status=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  if (jarak>25){
      lcd.setCursor(7,0);
      lcd.print("Aman    ");
  }
  else if(jarak>20){
      lcd.setCursor(7,0);
      lcd.print("Awas   ");
      digitalWrite(11,1);
      delay(500);
      digitalWrite(11,0);
      delay(500);
  }
  else if(jarak>10){
      lcd.setCursor(7,0);
      lcd.print("Waspada");
      digitalWrite(11,1);
      delay(300);
      digitalWrite(11,0);
      delay(300);
  }
  else {
      lcd.setCursor(7,0);
      lcd.print("Bahaya ");
      digitalWrite(11,1);
      delay(100);
      digitalWrite(11,0);
      delay(100);
  }
                      
  
 
}

