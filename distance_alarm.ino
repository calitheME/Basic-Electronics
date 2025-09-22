
// Pin definitions
const int redLED = 2;
const int blueLED = 3;
const int pingPin = 6;
const int buzzer = 8;

// Variables
long duration;
int distance;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
}

void loop() {
  // Send ultrasonic pulse
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);  // a short HIGH pulse
  digitalWrite(pingPin, LOW);
  
  // Read the echo response
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Check if object is closer than 10 cm
  if (distance <= 10 && distance > 0) {
    triggerAlarm();
  }
  delay(100); // Wait before next check
}

void triggerAlarm() {
  unsigned long startTime = millis();
  while (millis() - startTime < 5000) { // Alarm for 5 seconds
    digitalWrite(buzzer, HIGH);
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
    delay(250);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    delay(250);
  }
  // Turn everything off after alarm
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(buzzer, LOW);
}
