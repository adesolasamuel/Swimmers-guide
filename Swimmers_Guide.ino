#include "DHT.h"
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11


int trig = 10; //Trigger pin 
int echo =7;  // Echo Pin
float distances;
int duration;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(3000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  Serial.print(F("Environment Humidity: "));
  Serial.println(h);
  Serial.print(F("Water Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

  digitalWrite(trig, LOW);
delayMicroseconds(20);
digitalWrite(trig, HIGH);
delayMicroseconds(100);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distances = abs((duration / 29.387)/2);

  Serial.print(F("Depth of Water: "));
Serial.println(distances);

}
