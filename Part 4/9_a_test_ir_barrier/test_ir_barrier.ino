int IRsensor = 2; // digital pin 2

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(IRsensor, INPUT); // set the IR sensor as input
}

void loop() {
  int val = digitalRead(IRsensor); // read the IR sensor value
  if (val == LOW) { // active low output
    Serial.println("Obstacle detected!"); // print a message if an obstacle is detected
  }
  delay(100);
}
