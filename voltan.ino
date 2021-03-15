#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
char auth[] = "aUkhRrCSpHaJpvauYWoLuiZvJxKyzrRZ"; //YourToken
// Your WiFi credentials.
char ssid[] = "NakApaAnjayy"; //YourNetworkName
char pass[] = "18062000"; //YourPassword
BlynkTimer timer;
const byte MOTOR1_DIR = D1;
const byte MOTOR1_PWM = D2;
const byte MOTOR2_DIR = D3; 
const byte MOTOR2_PWM = D4;
const byte MOTOR3_DIR = D5;
const byte MOTOR3_PWM = D6;
byte LeftTurnSignal = 0;
byte RightSignal = 0;
//void motorSpeed(int PWM1, byte PWM2, byte PWM3, int DIR1, byte DIR2, byte DIR3)
//{
// analogWrite(MOTOR1_PWM, PWM1);
// analogWrite(MOTOR2_PWM, PWM2);
// analogWrite(MOTOR3_PWM, PWM3);
// digitalWrite(MOTOR1_DIR, DIR1);
// digitalWrite(MOTOR2_DIR, DIR2);
// digitalWrite(MOTOR3_DIR, DIR3);
//}
BLYNK_WRITE(V1) {
 int x = param[0].asInt();
 int y = param[1].asInt();
// x =  -10..-2 -1 0 1 2 ..10   
// Y =  -10..-2 -1 0 1 2 ..10
 Serial.print ("x = ");
 Serial.print (x);
 Serial.print ("y = ");
 Serial.println (y);
 if (x == 0 && y == 0){
   analogWrite(MOTOR1_PWM, 0);
   analogWrite(MOTOR2_PWM, 0);
   analogWrite(MOTOR3_PWM, 0);
   digitalWrite(MOTOR1_DIR, LOW);
   digitalWrite(MOTOR2_DIR, LOW);
   digitalWrite(MOTOR3_DIR, LOW);
  }

 else if (x == 10 && y == 0){
   analogWrite(MOTOR1_PWM, 1000
   );
   analogWrite(MOTOR2_PWM, 0);
   analogWrite(MOTOR3_PWM, 0);
   digitalWrite(MOTOR1_DIR, LOW);
   digitalWrite(MOTOR2_DIR, LOW);
   digitalWrite(MOTOR3_DIR, LOW);
  }

}
void setup() {
 Serial.begin(9600);
 pinMode(MOTOR1_PWM,OUTPUT);
 pinMode(MOTOR2_PWM,OUTPUT);
 pinMode(MOTOR3_PWM,OUTPUT);
 pinMode(MOTOR1_DIR,OUTPUT);
 pinMode(MOTOR2_DIR,OUTPUT);
 pinMode(MOTOR3_DIR,OUTPUT);
 Blynk.begin(auth, ssid, pass);
}
void loop() {
 Blynk.run();
 timer.run();
}
