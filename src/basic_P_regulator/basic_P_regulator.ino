#define MOTOR_A_PWM 10
#define MOTOR_A_DIR 12
#define MOTOR_B_PWM 11
#define MOTOR_B_DIR 13

void motors(int a = 0, int b = 0) {
  digitalWrite(MOTOR_A_DIR, a<0);
  analogWrite(MOTOR_A_PWM, constrain(abs(a),0,100)*2.5);  
  digitalWrite(MOTOR_B_DIR, b>0);
  analogWrite(MOTOR_B_PWM, constrain(abs(b),0,100)*2.5);  
}

void setup() {
  pinMode(MOTOR_A_PWM,OUTPUT);
  pinMode(MOTOR_A_DIR,OUTPUT);
  pinMode(MOTOR_B_PWM,OUTPUT);
  pinMode(MOTOR_B_DIR,OUTPUT);
  Serial.begin(9600);

  // motors(255,255);
  // delay(1000);
  // motors();


}

void loop() {
  // Serial.println(analogRead(A1));
  int e = analogRead(A0) - analogRead(A1);
  int pid = e*0.1;
  int M = 70;
  motors(M+pid, M-pid);
}

