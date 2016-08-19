/*-----------------------------------------------------
'     APLIKASI 8
'     TONGKAT TUNA NETRA
'     TRIG --> Pin 8
'     ECHO --> Pin 9
'     BUZZER --> Pin 11
'     Hasilnya tampilkan ke LCD
'     www.inkubator-teknologi.com
'------------------------*/

#define ECHOPIN 9                            
#define TRIGPIN 8                            

int jarak,timer;
void setup(){
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
  if (jarak>200){
      digitalWrite(11,0);
  }
  else if(jarak>100){
      digitalWrite(11,1);
      delay(1000);
      digitalWrite(11,0);
      delay(1000);
  }
  else {      
      digitalWrite(11,1);
      delay(200);
      digitalWrite(11,0);
      delay(200);
  }
                      
  
 
}

