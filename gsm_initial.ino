 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(115200);
  Serial.begin(115200);
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");   
  delay(1000);  
  mySerial.println("AT+CMGS=\"+917010655985\"\r");
  delay(1000);
  mySerial.println("I am SMS from GSM Module");
  delay(100);
   mySerial.println((char)26);
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); 
  delay(1000);
 }
 
