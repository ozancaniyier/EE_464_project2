float pwm=20;
void setup() {
  pinMode(3, OUTPUT);
TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 31372.55 Hz
Serial.begin(9600);
}
void loop() {

  int voltage = analogRead(A0);
  Serial.print ("voltage");
  voltage = map(voltage, 0 , 1023 , 0 , 100);
  
  Serial.println (voltage);
    if (voltage==0){
    pwm=20; 
    analogWrite(3,map(pwm,0,100,0, 255));
      }
  else if (voltage<=45) {

    pwm=pwm+0.5;

    if(pwm<0){
      pwm=0;
      }
    if (pwm>60){
      pwm=60;
      }
    analogWrite(3,map(pwm,0,100,0, 255));
    }

  else if (voltage>45) {
    pwm=pwm-0.5;
    if(pwm<0){
      pwm=0;
      }
    if (pwm>60){
      pwm=60;
      }
    analogWrite(3,map(pwm,0,100,0, 255));
    }
   delay(200);

}
