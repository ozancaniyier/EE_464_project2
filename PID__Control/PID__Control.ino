#include <PID_v1.h>
//#define PIN_INPUT 0
#define PIN_OUTPUT 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
 
//Specify the links and initial tuning parameters
double Kp=0.4, Ki=4, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
//
//int Pwm_pin = 3;
//int V_sense = A0;
//int Pwm_new = 0;

void setup() {
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
  Serial.begin(9600);
  
  pinMode(PIN_OUTPUT, OUTPUT);

 //initialize the variables we're linked to
 // Input = analogRead(PIN_INPUT);
 Setpoint = 106;
 myPID.SetOutputLimits(34,156);
 //turn the PID on
 myPID.SetMode(AUTOMATIC);

analogWrite(PIN_OUTPUT, 70);
 // myPID.SetSampleTime(0.03);
}

void loop() { 

 Input = analogRead(0);
 Input= map(Input, 0, 1023, 0, 255);
 myPID.Compute();
 
 analogWrite(PIN_OUTPUT, Output);
  
// Pwm_new = analogRead(V_sense); 
// Pwm_new = map(Pwm_new, 0, 1023, 0, 255);
// analogWrite(Pwm_pin, Pwm_new);
myPID.GetKp();
myPID.GetKi();
myPID.GetKd();
myPID.GetMode();
myPID.GetDirection();

  Serial.println(Output);
Serial.println(Input);
// delay(500);
}
