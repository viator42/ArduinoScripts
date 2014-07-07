int EN1 = 11;
void setup() {
  // set the digital pin as output:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}
 
void loop()
{
  int value;
   for(value = 0 ; value <= 255; value+=5)
    {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    analogWrite(EN1, value);
    delay(250);
    }
}
