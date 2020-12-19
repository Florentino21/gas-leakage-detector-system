  #include<LiquidCrystal.h>
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(9,10); //(TX, RX)
  LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);

  int Gas = 13;
  int Buzzer = 8;
  int redLed = 7;
  int greenLed = 6;

  void setup() {
      lcd.begin(16, 1);
      lcd.setCursor(0,1);
      lcd.print("WEL.TO M.DEFENCE");
          delay(6000);
      lcd.setCursor(0,1);
      lcd.print("DESIGN PROJECT...");
          delay(6500);
      lcd.setCursor(0,1);
      lcd.print("BY RUAQUE MOCHI");
          delay(6000);
       digitalWrite(redLed, HIGH);
          delay(1500);
      mySerial.begin(9600);   // Setting the baud rate of GSM Module
      Serial.begin(9600); 
      Serial.println ("GSM SIM900a IS READY");
         delay(100);
       pinMode(Gas , INPUT);
       pinMode(Buzzer, OUTPUT);
       pinMode(redLed, OUTPUT);
       pinMode(greenLed, OUTPUT);  
  }

  void loop() {
  int readGas= 0;
    readGas = digitalRead(Gas);
  if(readGas == 1){
       lcd.setCursor(0,1);
       lcd.print("GAS NOT DETECTED");
       digitalWrite(redLed ,LOW);
       digitalWrite(greenLed, HIGH);
       digitalWrite(Buzzer, LOW);                
         }
 if(readGas == 0){
      lcd.setCursor(0,1);
      lcd.print("GAS DETECTED");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("SENDING MESSAGES");
          delay(3000);
      lcd.setCursor(0,1);
      lcd.print("GAS  IS DETECTED");   
      digitalWrite(greenLed, LOW);
      digitalWrite(Buzzer, HIGH);
      digitalWrite(redLed , HIGH);    
          SendMessage();
            delay(1000);
          SendMessage();
            delay(1000);
          SendMessage();
            delay(1000);
      lcd.setCursor(0,1);
      lcd.print("calling");
          delay(2000);
          MakeCall();
            delay(1500);           
     }
    delay(3000);
  }
 void SendMessage()
 {
    Serial.println ("Sending Messages");
   mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
             delay(1000);
    Serial.println ("Set SMS Number");
   mySerial.println("AT+CMGS=\"+237676612708\"\r"); //Mobile phone number to send message
            delay(500);
    //Serial.println ("Set SMS Number");
  // mySerial.println("AT+CMGS=\"+237672632153\"\r"); //Mobile phone number to send message
           // delay(500);
    Serial.println ("Set SMS Content");
    mySerial.println("GAS LEACKAGE IS ON");// Messsage content
            delay(1000);
            Serial.println ("Set SMS Content");
    mySerial.println("TAKE IMMEDIATE");// Messsage content
            delay(1000);
             Serial.println ("Set SMS Content");
    mySerial.println("ACTION NOW!!!!");// Messsage content
            delay(1000);
    Serial.println ("Finish");
   mySerial.println((char)26);// ASCII code of CTRL+Z
            delay(1000);
    Serial.println ("Message has been sent to Florentino");
 }
 void MakeCall()
{
  mySerial.println("ATD+237676612708;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
  Serial.println("Calling   "); // print response over serial port
   delay(1500);
}
