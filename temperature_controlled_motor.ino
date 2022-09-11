#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float temp;
float tempr;
float tempPin=A1;
int motor =7;
int pirSensor=A3;
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor,OUTPUT);
  pinMode(pirSensor,INPUT);
  pinMode(tempPin,INPUT);
  
  Serial.begin(9600);

 lcd.begin(16,2);
 lcd.setCursor(1,0);
 lcd.print("jana e-fan");
 delay(1000);
 lcd.clear();
 lcd.setCursor(1,1);
 lcd.print("temp in place");
 delay(1000);
 lcd.clear();
 
 

}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(3,0);
 lcd.print("recording");
 lcd.setCursor(2,1);
 lcd.print("temperature");
 delay(3000);
 lcd.clear();
 lcd.setCursor(0,2);
 temp=analogRead(tempPin);
 tempr=temp*0.48828125;
 lcd.setCursor(0,0);
 lcd.print("temperature");
 lcd.setCursor(4,1);
 lcd.print(tempr);
 lcd.print("C");
 delay(3000);
 lcd.clear();
 val = digitalRead( pirSensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(motor, HIGH);   // turn LED ON
    delay(2000); 

 if (temp<20)
 {
  analogWrite(7,0);
  lcd.print("motor off");
  delay(2000);
  lcd.clear();
 }
 else if (temp<22)
 {
  analogWrite(motor,51);
  lcd.print("motor speed: 20%");
  delay(2000);
  lcd.clear();
 }
 else if (temp<25)
 {
  analogWrite(motor,102);
  lcd.print("motor speed:40%");
  delay(2000);
  lcd.clear();
 }
 else if (temp<27)
 {
  analogWrite(motor,154);
  lcd.print("motor speed:60%");
  delay(2000);
  lcd.clear();
 }
 else if (temp<30)
 {
  analogWrite(motor,205);
  lcd.print("motor speed:80%");
  delay(2000);
  lcd.clear();
 }
 else if (temp>30)
 {
  analogWrite(motor,255);
  lcd.print("motor speed:100%");
  delay(2000);
  lcd.clear();
 }
 }
  
 else{
      digitalWrite(motor, LOW); // turn LED OFF
      delay(2000);
      }
      }
