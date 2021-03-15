#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
char auth[] = "aUkhRrCSpHaJpvauYWoLuiZvJxKyzrRZ"; //YourToken
// Your WiFi credentials.
char ssid[] = "nama wifi"; //YourNetworkName
char pass[] = "pass wifi"; //YourPassword
BlynkTimer timer;
const byte L298N_A_pin = D1; // ENA for Ln298 motor drive
const byte L298N_A_In1_pin = D2; // in1 for Ln298 motor drive
const byte L298N_A_In2_pin = D3; // in2 for Ln298 motor drive
const byte L298N_B_In3_pin = D4; // in3 for Ln298 motor drive
const byte L298N_B_In4_pin = D5; // in4 for Ln298 motor drive
const byte L298N_B_pin = D6; // ENB for Ln298 motor drive
byte LeftTurnSignal = 0;
byte RightSignal = 0;
void motorSpeed(int prmA, byte prmA1, byte prmA2, int prmB, byte prmB1, byte prmB2)
{
 analogWrite(L298N_A_pin,prmA);
 analogWrite(L298N_B_pin,prmB);
 digitalWrite(L298N_A_In1_pin,prmA1);
 digitalWrite(L298N_A_In2_pin,prmA2);
 digitalWrite(L298N_B_In3_pin,prmB1);
 digitalWrite(L298N_B_In4_pin,prmB2);
}
BLYNK_WRITE(V1) {
 int x = param[0].asInt();
 int y = param[1].asInt();
// x =  -10..-2 -1 0 1 2 ..10   
// Y =  -10..-2 -1 0 1 2 ..10
if ((x==0) && (y==0)) // stop
{
  motorSpeed(0,LOW,LOW,0,LOW,LOW); 
}
else if (((x>=-3) && (x<=3)) && (y>0)) // forward 
{
 if (y==1){ motorSpeed(100,HIGH,LOW,100,HIGH,LOW); }
 else if (y==2){ motorSpeed(200,HIGH,LOW,200,HIGH,LOW); }
 else if (y==3){ motorSpeed(300,HIGH,LOW,300,HIGH,LOW); }
 else if (y==4){ motorSpeed(400,HIGH,LOW,400,HIGH,LOW); }
 else if (y==5){ motorSpeed(500,HIGH,LOW,500,HIGH,LOW); }
 else if (y==6){ motorSpeed(600,HIGH,LOW,600,HIGH,LOW); }
 else if (y==7){ motorSpeed(700,HIGH,LOW,700,HIGH,LOW); }
 else if (y==8){ motorSpeed(800,HIGH,LOW,800,HIGH,LOW); }
 else if (y==9){ motorSpeed(900,HIGH,LOW,900,HIGH,LOW); }
 else if (y==10){ motorSpeed(1000,HIGH,LOW,1000,HIGH,LOW); }
}
}
void setup() {
 Serial.begin(9600);
 pinMode(L298N_A_In1_pin,OUTPUT);
 pinMode(L298N_A_In2_pin,OUTPUT);
 pinMode(L298N_B_In3_pin,OUTPUT);
 pinMode(L298N_B_In4_pin,OUTPUT);
digitalWrite(L298N_A_In1_pin,LOW);
digitalWrite(L298N_A_In2_pin,LOW);
digitalWrite(L298N_B_In3_pin,LOW);
digitalWrite(L298N_B_In4_pin,LOW);
 Blynk.begin(auth, ssid, pass);
}
void loop() {
 Blynk.run();
 timer.run();
}
