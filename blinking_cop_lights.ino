// C++ code
//

const int redLED = 2;
const int blueLED = 1;
void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop()
{
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
}
