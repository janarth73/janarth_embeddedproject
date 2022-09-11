#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
int gas = A1;
int motor = 7;
int irSensor = A2;
int val;
int gas_oh;
float sv;
float analog = A1;
void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  pinMode(irSensor, INPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("car security");
  delay(1000);
  lcd.clear();
  
}
void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(1, 0);
  lcd.print("recording");
  delay(1000);
  val = digitalRead(irSensor);
  gas_oh = digitalRead(gas);
  sv = analogRead(analog);
  // read sensor value
  if (val == HIGH) {
    lcd.setCursor(2,1);
    lcd.print(" dirver inside");
    delay(1000);
    lcd.clear();// check if the sensor is HIGH
    if (gas_oh == LOW)
    { lcd.setCursor(1,1);
      lcd.print("gas level");
      lcd.print(sv);
      delay(1000);
      lcd.clear();
      digitalWrite(motor, HIGH);   // turn LED ON
      lcd.setCursor(2, 1);
      lcd.print("dirver not drunked");
      delay(1000);
      lcd.clear();
    }
    else {
      lcd.setCursor(2,1);
      lcd.print(sv);
      delay(1000);
      lcd.clear();
      digitalWrite(motor, LOW);
      lcd.setCursor(2, 1);
      lcd.print("dirver drunked");
      delay(1000);
      lcd.clear();
    }
  }

  else {
    lcd.setCursor(2, 1);
    lcd.print(" dirvernotinside");
    delay(1000);
    lcd.clear();

  }

}
