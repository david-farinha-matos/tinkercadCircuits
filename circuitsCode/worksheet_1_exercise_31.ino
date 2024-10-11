// C++ code
//
#define ledPin 5
#define speakerPin 12
#define tempPin A0
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  float temperatureC = getTemperatureC();
  Serial.print(temperatureC);
  Serial.println(" degrees C");
  
  if (temperatureC >= 25 && temperatureC < 50) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(speakerPin, LOW);
  }
  else if (temperatureC >= 50) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(speakerPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(speakerPin, LOW);
  }
}

float getTemperatureC()
{
 int ADCreading = analogRead(tempPin);
  float voltage = (ADCreading * 5.0) / 1024;
  return (voltage - 0.5) * 100; 
}