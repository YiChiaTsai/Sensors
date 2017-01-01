#include <SoftwareSerial.h>       

const int ledpin=13;              //LED pin
const int flamepin=2;            //flame sensor pin

void setup()
{ 
  pinMode(ledpin,OUTPUT);             //LED pin as OUTPUT
  pinMode(flamepin,INPUT);            //FLAME SENSOR pin as INPUT
  
  Serial.begin(9600); 
  Serial.println("Start detecting...");
  
  digitalWrite(ledpin,LOW); 
}
void loop()
{
    //variable declaration   
    int flameval;                     //flame flag (fire or not)
    int gasreading;
    int gascon;
    
    
    flameval=digitalRead(flamepin);    //read flame sensor pin and assign to flameval
    gasreading = analogRead(A1);
    
    Serial.print(flameval);
    Serial.print(",");
    Serial.println(gasreading);        
        
    if((flameval==HIGH) || (gasreading>200))                //check fire & smoke concentration
      digitalWrite(ledpin,HIGH);    
    else
      digitalWrite(ledpin,LOW);
    
    delay(1500);
}
