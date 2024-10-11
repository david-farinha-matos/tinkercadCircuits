// C++ code
//
#define speakerPin 12
#define ledPin 11
#define sensorPin 2
int sensorState = 0;
void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  sensorState = digitalRead(sensorPin);
  if (sensorState == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(speakerPin, HIGH);
    delay(1);
    digitalWrite(ledPin, LOW);
    digitalWrite(speakerPin, LOW);
  }
  else if (sensorState == LOW) {
    digitalWrite(ledPin, LOW);
    digitalWrite(speakerPin, LOW);
  }
}