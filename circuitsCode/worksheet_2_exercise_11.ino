#include <LiquidCrystal.h>
#define echoPin 10
#define triggerPin 9
#define speakerPin 13
#define redLedPin 6
#define orangeLedPin 7
#define greenLedPin 8

float time = 0;
float distance = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(orangeLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  lcd.begin(16, 2);
}
 
void loop() {
  lcd.clear();
  digitalWrite(triggerPin, HIGH);
  digitalWrite(triggerPin, LOW);

  //equation to work out distance from sensor
  time = pulseIn(echoPin,HIGH);
  distance = 0.01716*time;
  
  lcd.setCursor(3,0);
  lcd.print("Distance -");
  lcd.setCursor(5,1);
  lcd.print(float(distance));  
  lcd.print("cm"); 
  delay(1000);
  
  if (distance > 100) {
    allOff();
  }
  else if (distance < 100 && distance > 80) {
  	greenLedOn();
  }
  else if (distance < 80 && distance > 60) {
  	orangeLedOn();
  }
  else if (distance < 60 && distance > 40) {
  	redLedOn();
  }
  else if (distance < 40) {
  	redLedBlinkAndSpeakerOn();
  }
}

void greenLedOn() {
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(orangeLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(speakerPin, LOW);
}

void orangeLedOn() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(orangeLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  digitalWrite(speakerPin, LOW);
}

void redLedOn() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(orangeLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(speakerPin, LOW);
}
void redLedBlinkAndSpeakerOn() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(orangeLedPin, LOW);
  digitalWrite(speakerPin, HIGH);
  digitalWrite(redLedPin, HIGH);
  delay(1000);
  digitalWrite(redLedPin, LOW);
  delay(1000);
  digitalWrite(redLedPin, HIGH);
  delay(1000);
}
void allOff() {
  digitalWrite(greenLedPin, LOW);
  digitalWrite(orangeLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(speakerPin, LOW);
}