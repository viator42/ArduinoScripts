/*

*/

int speed1 = 128;
int speed2 = 255;

boolean direction1 = true;
boolean direction2 = true;

void setup() {
  // set the digital pin as output:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
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
  motorSet(A0, 2, 3, true, 255);
  motorSet(A1, 4, 5, true, 255);
  
}
