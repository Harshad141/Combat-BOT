Code:-To run this code checkout if your arduino IDE has all the libraries installed..


#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
#include <Servo.h>   
const int trigPin = 12;
const int echoPin = 11; 
const int lm1=7; 
const int lm2=6; 
const int rm1=5; 
const int rm2=4; 
const int servoPin=2; 
 
Servo myservo; 
long duration; 
int distance; 
int distance_f; 
int distance_r; 
int distance_l; 
int maxLowDistance=30; 
 

void setup() 
{  
Serial.begin(9600);  
lcd.begin(16,2);  
pinMode(trigPin, OUTPUT);
// Sets the trigPin as an Output 
pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
pinMode(lm1,OUTPUT); 
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT); 
 
myservo.attach(servoPin); 
myservo.write(90); 

 Serial.begin(9600); // Starts the serial communication } 
 void loop()
 {   
 distance_f=ping();     
 if(distance_f > maxLowDistance)
 {  
 displayDistance();  
 front();    
 delay(400); 
 }
 else
 {     
 Break();  
 get_Distance();     
 if(distance_r > maxLowDistance)
 {  
 displayDistance();   
 right();     
 delay(400);   
 front();      
 }
 else if(distance_l > maxLowDistance)
 {      
 displayDistance();     
 left();    
 delay(400);       
 front();    
 }
 else
 {    
 displayDistance();       
 back();   
 delay(400);    
 Break();   
 }   
 }
 } 
 void displayDistance()
 {   
 lcd.clear();  //Start at character 0 on line 0      
 Serial.print("Right Distance : ");  
 lcd.setCursor(12,0);     
 lcd.print("R:");    
 Serial.print(distance_r);   
 lcd.setCursor(14,0);          
 lcd.print(distance_r);   
 Serial.println("");  
 Serial.print("Front Distance : ");   
 lcd.setCursor(6,1);    
 lcd.print("F:"); 
 Serial.print(distance_f);  
 lcd.setCursor(8,1);     
 lcd.print(distance_f);  
 Serial.println(""); 
 lcd.setCursor(12,1);   
 Serial.print("L: "); 
 lcd.print("L:");    
 Serial.print(distance_l);  
 lcd.setCursor(14,1); 
 lcd.print(distance_l);  
 Serial.println("");   
 //delay(100);    
} 
void front() 
{ 
//lcd.clear();  
lcd.setCursor(0,0);
Serial.println("Forward Move"); 
lcd.println("Forward");
digitalWrite(lm2,HIGH); 
digitalWrite(rm2,HIGH); 
digitalWrite(lm1,LOW); 
digitalWrite(rm1,LOW); 
 
} 
void back() 
{  
lcd.clear();  
lcd.setCursor(0,0);
Serial.println("Back Move");    
lcd.println("Back Move");
digitalWrite(lm1,HIGH);   
digitalWrite(rm1,HIGH);   
digitalWrite(lm2,LOW); 
digitalWrite(rm2,LOW);
} 
void left()
{ 
lcd.clear(); 
lcd.setCursor(0,0);  
lcd.println("Left move");
digitalWrite(rm2,HIGH);  
digitalWrite(rm1,LOW);   
digitalWrite(lm1,HIGH); 
digitalWrite(lm2,LOW);
}
void right() 
{  
lcd.clear();  
lcd.setCursor(0,0);  
lcd.println("right move");   
digitalWrite(lm2,HIGH);  
digitalWrite(lm1,LOW); 
digitalWrite(rm1,HIGH);  
digitalWrite(rm2,LOW);
}
void Break() 
{  
lcd.clear();  
lcd.setCursor(0,0);
lcd.println("Break!!!!!");
digitalWrite(lm2,LOW); 
digitalWrite(lm1,LOW); 
digitalWrite(rm1,LOW); 
digitalWrite(rm2,LOW);
} 
 
void get_Distance()
{ 
myservo.write(0);
delay(300);  
int temp_r1=ping();
myservo.write(45); 
  delay(300); 
  int temp_r2=ping();
  if(temp_r1<temp_r2)
  { 
  distance_r=temp_r1; 
  }
  else
  {   
  distance_r=temp_r2;  
  } 
  myservo.write(90);  
  delay(300); 
  distance_f=ping(); 
  myservo.write(135);
  delay(300); 
  int temp_l1=ping();
  myservo.write(180); 
  delay(300);
  int temp_l2=ping();   
  if(temp_l1<temp_l2)
  {   
  distance_l=temp_l1;
  }
  else
  {
  distance_l=temp_l2; 
  }
  myservo.write(90);   
  }
  
 
int ping()
{  
// Clears the trigPin  
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
// Sets the trigPin on HIGH state for 10 micro seconds  
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);   
digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds  
duration = pulseIn(echoPin, HIGH);   // Calculating the distance 
distance= duration*0.034/2;   // Prints the distance on the Serial Monitor 
return distance; 
} 
