/*-----------------------------------------------------
'     APLIKASI 3
'     VOLUME CONTROL TANGKI AIR
'     TRIG --> Pin 9
'     ECHO --> Pin 8
'     RELAY --> Pin 10
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5,6,7);
unsigned int jarak,timer,T_air,La;
unsigned long Vol;
void setup(){
  lcd.begin(16, 2);
  lcd.print("   WATER LEVEL");
  lcd.setCursor(0, 1);
  lcd.print("     CONTROL  ");
  delay(2000);
  lcd.clear();
  lcd.print("Volume=");
  lcd.setCursor(0,1);
  lcd.print("Status=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(10,OUTPUT);
  // tinggi tangki 1 m (100 cm)
  // diameter alas 60 cm
  // Luas alas = 3.14x30x30 = 2826 cm2
  La=2826;
  
}

void loop(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  if (jarak>100)jarak=100;
  T_air=100-jarak;
  Vol=(unsigned long)La*T_air/1000;
  
  lcd.setCursor(7,0);
  lcd.print(Vol);
  lcd.print(" L ");
  if(Vol<100){
      lcd.setCursor(7,1);
      lcd.print("Pompa ON ");
      digitalWrite(10,1);      
  }
  else if(Vol>250){
      lcd.setCursor(7,1);
      lcd.print("Pompa OFF");
      digitalWrite(10,0);      
  }
  
  delay(500);
}

