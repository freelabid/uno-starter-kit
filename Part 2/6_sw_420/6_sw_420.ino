int vibratePin  = 2; //sets the digital pin(d0)of the vibration sensor @pin 7
int ledPin  = 13;  //sets the LED @pin 2
int value;        //defines the value variable

void setup() {
  pinMode(vibratePin,INPUT);  //sets the vibration sensor as INPUT
  pinMode(ledPin,OUTPUT);   //sets the LED as OUTPUT
}
void loop() {
  value=digitalRead(vibratePin);  //reads the sensors status
  if(value==1)      //if sensor sends a HIGH signal
  {
    digitalWrite(ledPin,HIGH);  //turns LED on
    delay(3000);      //duration of 3 seconds
   }
   else   //otherwise 
   digitalWrite(ledPin,LOW);  //LED is turned off
}
