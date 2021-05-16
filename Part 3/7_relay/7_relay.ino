#define RELAY_PIN 2

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RELAY_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN, HIGH);   // matikan RELAY (NO != COM)
  delay(5000);                       // wait for 5 seconds
  digitalWrite(RELAY_PIN, LOW);    // nyalakan RELAY (NO = COM)
  delay(5000);                       // wait for 5 seconds
}
