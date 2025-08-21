#include <ArduinoJson.h>
#include <DHT.h>

StaticJsonDocument<32> doc;
DHT dht(7, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(13, OUTPUT);
}

void loop() {
  String output;
  doc["temperatura"] = dht.readTemperature();
  doc["umidade"] = dht.readHumidity();

  serializeJson(doc, output);
  Serial.println(output);
  delay(800);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
}
