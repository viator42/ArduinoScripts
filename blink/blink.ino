
int led = 7;


void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}


void loop() {
  digitalWrite(led, HIGH); 
  delay(500);          
  digitalWrite(led, LOW);
  delay(1000);
}
