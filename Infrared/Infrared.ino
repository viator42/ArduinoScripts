const int InfraredSensorPin = 4;//Connect the signal pin to the digital pin 4
const int LedDisp = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(InfraredSensorPin,INPUT);
  pinMode(LedDisp,OUTPUT);
  digitalWrite(LedDisp,LOW);
}

void loop()
{
  if(digitalRead(InfraredSensorPin) == LOW)  digitalWrite(LedDisp,HIGH);
  else  digitalWrite(LedDisp,LOW);
  Serial.println(digitalRead(InfraredSensorPin));
  delay(500);
}
