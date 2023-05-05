int IRsensor = 2; // digital pin 2
int duration = 0; // obstacle duration in milliseconds
bool obstacleDetected = false; // flag to track obstacle detection
unsigned long startTime = 0; // start time of obstacle detection

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(IRsensor, INPUT); // set the IR sensor as input
}

void loop() {
  int val = digitalRead(IRsensor); // read the IR sensor value
  if (val == LOW) { // obstacle detected
    if (!obstacleDetected) { // first time obstacle detection
      obstacleDetected = true;
      startTime = millis(); // record start time
    }
    duration = millis() - startTime; // calculate duration
    if (duration > 5000 && duration < 10000) {
      Serial.println("Obstacle detected for more than 5 seconds but less than 10 seconds!");
    } else if (duration > 10000) {
      Serial.println("Obstacle detected for more than 10 seconds!");
    }
  } else { // no obstacle detected
    obstacleDetected = false;
    duration = 0;
  }
  delay(100);
}
