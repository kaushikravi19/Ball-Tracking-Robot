
 // incoming serial byte
 char inbyte;
 #include <Servo.h>
 Servo myServo;
 Servo myServo2;
void setup()
{
 // start serial port at 9600 bps;
 Serial.begin(9600);
 pinMode(A0,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(A2,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
}
void loop()
{
 //if we get a valid byte,read analog ins:
 
  // get incoming byte:
  //delay(2000);
     inbyte = Serial.read();
     //Serial.println(inbyte);
     //Serial.println("HI");


if (inbyte == 'R') {
 // delay(100);
 //myServo.write(0);
 Serial.println("HI");
 analogWrite(A0,255);
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
 analogWrite(A2,255);
 digitalWrite(6,HIGH);
 digitalWrite(5,LOW); 
// delay(50);
 }

 
else if (inbyte == 'L') 
{
 // delay(100);
 //myServo.write(0);
 Serial.println("HI");
 analogWrite(A0,255);
 digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 analogWrite(A2,255);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW); 
// delay(100);
 }

 
else if (inbyte == 'F')
{
  //delay(100);
  //myServo.write(0);
  Serial.println("HI");
 analogWrite(A0,255);
 digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 analogWrite(A2,255);
 digitalWrite(6,HIGH);
 digitalWrite(5,LOW); 
 //delay(100);
 }

 
else if (inbyte == 'S') 
{ 
 // delay(100);
 
 myServo.attach(3);
 myServo2.attach(9);
 Serial.println("HI");
 analogWrite(A0,255);
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
 analogWrite(A2,255);
 digitalWrite(5,LOW);
 digitalWrite(6,LOW);
 myServo.write(180);
 delay(100);
 myServo.write(0);
// delay(100);
 }
 
}
 

