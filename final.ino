#include <Stepper.h> // Include the header file


// Define Constants
 
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing
 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 

int soundSensor=2;
int LED=4;
boolean LEDStatus=false;
boolean on=false;



void setup() {
 Serial.begin(9600);  
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);

}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  
  if(SensorData==HIGH){

    Serial.print(SensorData);
    
    if(on==true){
        digitalWrite(LED,HIGH);

         StepsRequired  = STEPS_PER_OUT_REV / 2;   
         steppermotor.setSpeed(700);  
         steppermotor.step(StepsRequired);

         LEDStatus=false;
         digitalWrite(LED,LOW);

         on=false;
          
         
         delay(500);
    }
    else{
        digitalWrite(LED,HIGH);

       StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
       steppermotor.setSpeed(700);  
       steppermotor.step(StepsRequired);

       on=true;
       delay(500);

       
    }

    delay(500);
  }
  
 } 
