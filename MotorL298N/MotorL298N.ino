
int speed1 = 128;
int speed2 = 255;

boolean direction1 = true;
boolean direction2 = true;

void setup() {
  // set the digital pin as output:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}

void motorSet(int en, int in1, int in2, boolean dir, int speed)
{
  if(dir == true)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  
  analogWrite(en, speed);
}

void loop()
{
  motorSet(8, 9, 10, true, 255);
  motorSet(11, 12, 13, true, 255);
  
}
