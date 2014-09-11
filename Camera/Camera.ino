#include <SoftwareSerial.h>
  
byte ZERO = 0x00;
  
byte incomingbyte;
SoftwareSerial mySerial(5,6);          // Set Arduino pin 4 and 5 as softserial
  
long int a=0x0000,j=0,k=0,count=0,i=0;
uint8_t MH,ML;
boolean EndFlag=0;
  
void SendResetCmd();
void SetBaudRateCmd();
void SetImageSizeCmd();
void SendTakePhotoCmd();
void SendReadDataCmd();
void StopTakePhotoCmd();
  
void setup()
{
    
  Serial.begin(38400);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
    
  mySerial.begin(38400);
    
}
  
void loop()
{
  byte a[32];
  int ii;
  
  SendResetCmd();
  delay(4000);                            //Wait 2-3 second to send take picture command
  
  SendTakePhotoCmd();
  
  while(mySerial.available()>0)
  {
    incomingbyte=mySerial.read();
  }
  
  while(!EndFlag)
  {
    j=0;
    k=0;
    count=0;
    SendReadDataCmd();
      
    delay(20); //250 for regular
      
    while(mySerial.available()>0)
    {
      incomingbyte=mySerial.read();
      k++;
      if((k>5)&&(j<32)&&(!EndFlag))
      {
        a[j]=incomingbyte;
        if((a[j-1]==0xFF)&&(a[j]==0xD9))     //tell if the picture is finished
        EndFlag=1;
        j++;
        count++;
      }
    }
    
    for(j=0;j<count;j++)
    {
      if(a[j]<0x10)
      Serial.print("0");
      Serial.print(a[j],HEX);           // observe the image through serial port
      Serial.print(" ");
    }
    
    for(ii=0; ii<count; ii++)
    {
      Serial.print(a[ii]);
    }
    i++;
  }
  
  
}
  
void SendResetCmd()
{
  mySerial.write(0x56);
  mySerial.write(ZERO);
  mySerial.write(0x26);
  mySerial.write(ZERO);
}
  
void SetImageSizeCmd()
{
  mySerial.write(0x56);
  mySerial.write(ZERO);
  mySerial.write(0x31);
  mySerial.write(0x05);
  mySerial.write(0x04);
  mySerial.write(0x01);
  mySerial.write(ZERO);
  mySerial.write(0x19);
  mySerial.write(0x11);
}
  
void SetBaudRateCmd()
{
  mySerial.write(0x56);
  mySerial.write(ZERO);
  mySerial.write(0x24);
  mySerial.write(0x03);
  mySerial.write(0x01);
  mySerial.write(0x2A);
  mySerial.write(0xC8);
}
  
void SendTakePhotoCmd()
{
    mySerial.write(0x56);
    mySerial.write(ZERO);
    mySerial.write(0x36);
    mySerial.write(0x01);
    mySerial.write(ZERO);
}
  
void SendReadDataCmd()
{
    MH=a/0x100;
    ML=a%0x100;
    mySerial.write(0x56);
    mySerial.write(ZERO);
    mySerial.write(0x32);
    mySerial.write(0x0c);
    mySerial.write(ZERO);
    mySerial.write(0x0a);
    mySerial.write(ZERO);
    mySerial.write(ZERO);
    mySerial.write(MH);
    mySerial.write(ML);
    mySerial.write(ZERO);
    mySerial.write(ZERO);
    mySerial.write(ZERO);
    mySerial.write(0x20);
    mySerial.write(ZERO);
    mySerial.write(0x0a);
    a+=0x20;
}
  
void StopTakePhotoCmd()
{
    mySerial.write(0x56);
    mySerial.write(ZERO);
    mySerial.write(0x36);
    mySerial.write(0x01);
    mySerial.write(0x03);
}

