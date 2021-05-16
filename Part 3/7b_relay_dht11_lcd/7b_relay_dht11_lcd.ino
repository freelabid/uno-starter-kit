/*
  Freelab - DHT11

  Baca kelembapan dan temperatur menggunakan DHT11. Menampilkan nilai tersebut di Serial Terminal
  Download library DHT11. Klik Sketch > Include Library > Manage Libraries > Cari "DHT11" > Pilih DHT11 by Adafruit
  Install library DHT11 tersebut  
  
  Rangkaian:
  - DHT11 pin 2 ke Arduino Uno pin 2
  - Hubungkan Vcc DHT11 ke +5V Arduino dan GND DHT11 ke GND Arduino

  https://github.com/adafruit/DHT-sensor-library
*/

#include "DHT.h"

#define DHTPIN 3     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

DHT dht(DHTPIN, DHTTYPE);

int relayPin = 2;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));

  dht.begin();

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Starter Kit");
  lcd.setCursor(1,1);
  lcd.print("LCD DHT11 Relay");
  
  pinMode(relayPin,OUTPUT);   //sets the RELAY as OUTPUT
  digitalWrite(relayPin, HIGH);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  lcd.setCursor(1,0);
  lcd.print(F("Humidity: "));
  lcd.setCursor(11,0);
  lcd.print(h);
  lcd.setCursor(1,1);
  lcd.print(F("Temperature: "));
  lcd.setCursor(14,1);
  lcd.print(t);

  if (h > 68.0) {
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
  }
}
