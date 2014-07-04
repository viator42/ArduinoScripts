
#include <Arduino.h>

#define A1 8			//引脚命名
#define B1 9
#define C1 10
#define D1 11

void setup()
{
	pinMode(A1,OUTPUT);		//设置引脚为输出引脚
	pinMode(B1,OUTPUT);
	pinMode(C1,OUTPUT);
	pinMode(D1,OUTPUT);
}

void loop()
{
  stepperPhases(10, false);

}

/* dir: direction, false for anti-clockwize, true for clockwize*/
void stepperPhases(int delayTime,boolean dir)
{
  if(dir == true)
  {
    //clockwize
    digitalWrite(A1,LOW);		//A1引脚高电平	
    digitalWrite(B1,LOW);
    digitalWrite(C1,LOW);
    digitalWrite(D1,HIGH);
    delay(delayTime);
    
    digitalWrite(A1,LOW);	
    digitalWrite(B1,LOW);		//B1引脚高电平	
    digitalWrite(C1,HIGH);
    digitalWrite(D1,LOW);
    delay(delayTime);
    
    digitalWrite(A1,LOW);	
    digitalWrite(B1,HIGH);
    digitalWrite(C1,LOW);		//C1引脚高电平	
    digitalWrite(D1,LOW);
    delay(delayTime);
    
    digitalWrite(A1,HIGH);	
    digitalWrite(B1,LOW);
    digitalWrite(C1,LOW);
    digitalWrite(D1,LOW);		//D1引脚高电平	
    delay(delayTime);
  }
  else
  {
    digitalWrite(A1,HIGH);		//A1引脚高电平	
    digitalWrite(B1,LOW);
    digitalWrite(C1,LOW);
    digitalWrite(D1,LOW);
    delay(delayTime);
    
    digitalWrite(A1,LOW);	
    digitalWrite(B1,HIGH);		//B1引脚高电平	
    digitalWrite(C1,LOW);
    digitalWrite(D1,LOW);
    delay(delayTime);
    
    digitalWrite(A1,LOW);	
    digitalWrite(B1,LOW);
    digitalWrite(C1,HIGH);		//C1引脚高电平	
    digitalWrite(D1,LOW);
    delay(delayTime);
    
    digitalWrite(A1,LOW);	
    digitalWrite(B1,LOW);
    digitalWrite(C1,LOW);
    digitalWrite(D1,HIGH);		//D1引脚高电平	
    delay(delayTime);
  }
  
}

