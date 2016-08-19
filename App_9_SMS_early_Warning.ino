/*-----------------------------------------------------
'     APLIKASI 9
'     SMS ERALY WARNING
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     Baud Rate 9600 bps
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

#define ECHOPIN 9                            
#define TRIGPIN 8 

LiquidCrystal lcd(2, 3, 4, 5,6,7);
unsigned int jarak, timer;
byte f1,f2,f3;

String inString="";
char str,f;
int distance,l,b,s;
const int rxpin = 10; // pin used to receive 
const int txpin = 11; // pin used to transmit 
SoftwareSerial gsm(rxpin, txpin); 
String noHP;

String statusbanjir="",isisms;

//************************************
void setup() { 
  Serial.begin(9600);
  gsm.begin(9600);   
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);  
  //----- NOMOR HP HARUS DIISI DENGAN NOMOR TUJUAN
  noHP="085xxxxxxxxx";
    
  statusbanjir=="Standby";
  lcd.begin(16, 2);
  lcd.print(" Early Warning");
  lcd.setCursor(0, 1);
  lcd.print(" Banjir");
  delay(2000);
  lcd.clear();
  lcd.print("L=");
  lcd.setCursor(0, 1);
  lcd.print("Status");
  delay(1000);
  
}

void loop() {
  
  getdistance(); 
  lcd.setCursor(2,0);
  lcd.print(jarak); 
   if(jarak>100)
    {     
      statusbanjir="Standby";
      lcd.setCursor(7,1);
      lcd.print("Aman  "); 
    }
  else if ((jarak>75)&&(f1==0))
    {
      lcd.setCursor(7,1);
      lcd.print("Waspada");                
      sendsms(noHP,"WASPADA ! ");delay(1000);   
      f1=1;    
    } 
    
  else if ((jarak>50)&&(f2==0))
    {    
      lcd.setCursor(7,1);
      lcd.print("Awas !");                
      sendsms(noHP,"AWAS ! ");delay(1000);   
      f2=1;   
    }   
  else if ((jarak>25)&&(f3==0))
    {    
      lcd.setCursor(7,1);
      lcd.print("Bahaya !");                
      sendsms(noHP,"BAHAYA ! ");delay(1000);   
      f3=1;   
    }   
 
}

void getdistance(){
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;
  delay(50);                                    
}
//----------------------
void sendsms(String nomorHP,String pesan)
{
   gsm.print("AT+CMGS="); 
   gsm.write((byte)34);
   gsm.print(nomorHP);
   gsm.write((byte)34); 
   gsm.println();     
   delay(1000);
   Serial.println();
   gsm.print(pesan); 
   gsm.write((byte)26); 
   gsm.println();   
   delay(1000);   
   delay(2000);  
}

