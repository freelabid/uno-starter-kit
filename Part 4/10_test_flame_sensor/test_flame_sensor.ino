int flamePin = 2; // digital pin 2
int ledPin = 13; // digital pin 13
bool flameDetected = false; // flag to track flame detection

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(flamePin, INPUT); // set the flame sensor as input
  pinMode(ledPin, OUTPUT); // set the LED as output
}

void loop() {
  int val = digitalRead(flamePin); // read the flame sensor value
  if (val == LOW) { // flame detected
    if (!flameDetected) { // first time flame detection
      flameDetected = true;
      Serial.println("Fire detected!"); // print a message if fire is detected
      digitalWrite(ledPin, HIGH); // turn on the LED if fire is detected
    }
  } else { // no flame detected
    flameDetected = false;
    digitalWrite(ledPin, LOW); // turn off the LED if no fire is detected
  }
  delay(100);
}
