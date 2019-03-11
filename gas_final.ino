int LED = 8;
void setup()
{
pinMode(LED,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
int output;
output=analogRead(0);
Serial.print("Gas value: ");
Serial.println(output,DEC);
delay(1000);
if (output >= 300)
{
  Serial.println("High Gas content...Danger awakes !!  ");
  digitalWrite(LED,HIGH);
}
else 
{
Serial.println("Nothing series ...Be Cool^^^");
digitalWrite(LED,LOW);
}
delay(100);
}
