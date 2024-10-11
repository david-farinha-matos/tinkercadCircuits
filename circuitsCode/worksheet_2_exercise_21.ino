// C++ code
//
#include <Servo.h>
Servo myServo;

void setup()
{
  myServo.attach(8);
  Serial.begin(9600);
}

void loop()
{
  float getVoltage = convertVoltage();
  if (getVoltage > 2.5) {
    myServo.write(90);
    delay(100);
  }
  else if (getVoltage < 2.5) {
    myServo.write(-90);
    delay(100);
  }
}
  
  float convertVoltage() {
    int potentiometerValue = analogRead(A0);
    float voltageValue = potentiometerValue * (5.0/1023.0);
    Serial.print(voltageValue);
    Serial.println("V");
    return voltageValue;
  }