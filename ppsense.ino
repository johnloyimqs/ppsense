
#include <Servo.h> 

int servoPin = 3;
int distancePin = A0; 
int constant = 6787;

Servo s; 

void setup() { 

   Serial.begin(9600);

   // setup servo
   s.attach(servoPin); 

}

float getDistance(int raw){
  float val = (constant / (raw - 3)) - 4;
  return val;
}

// power modes state machine
// drive servo gracefully              
// main state machine, ppActive, ppIdle, minPPTime, maxPPTime, ppCounter

void loop(){ 

  int rawValue = analogRead(distancePin);

  float distance = getDistance(rawValue);
  Serial.print(" d: ");
  Serial.println(distance);
  
  delay(100);
  
  
}
