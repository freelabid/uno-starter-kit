int IRsensor = 2; // digital pin 2
int duration = 0; // obstacle duration in milliseconds
bool obstacleDetected = false; // flag to track obstacle detection
unsigned long startTime = 0; // start time of obstacle detection
int buzzer = 3; // digital pin 3

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(IRsensor, INPUT); // set the IR sensor as input
  pinMode(buzzer, OUTPUT); // set the buzzer as output
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
      tone(buzzer, 1000, 500); // sound short alarm
    } else if (duration > 10000) {
      tone(buzzer, 500, 1000); // sound long alarm
    }
  } else { // no obstacle detected
    obstacleDetected = false;
    duration = 0;
    noTone(buzzer); // stop the alarm
  }
  delay(100);
}
