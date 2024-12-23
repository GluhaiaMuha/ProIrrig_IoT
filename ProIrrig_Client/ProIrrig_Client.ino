#include <ESP8266WiFi.h>
#include <DHT22.h>
#include <ArduinoJson.h>

#ifndef STASSID
#define STASSID "" // WIFI SSID - aka name of the WiFi point of access
#define STAPSK "" // Password for the WiFi
#endif

#define SOIL_MOISTURE_PIN A0    // Soil moisture sensor on A0
#define DHT_PIN D1             // DHT22 on D1
DHT22 dht22(DHT_PIN); 

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "";
const uint16_t port = 1;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  static bool wait = false;
  JsonDocument doc;

  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(host, port)) {
    Serial.println("connection failed");
    delay(5000);
    return;
  }

  // Read DHT22 sensor data and save to json
  Serial.println("Reading Sensor Data");
  float airTemperature = dht22.getTemperature();
  float airHumidity = dht22.getHumidity();
  if(dht22.getLastError() == dht22.OK){
    doc["airTemperature"] = airTemperature;
    doc["airHumidity"] = airHumidity;
  }else if(dht22.getLastError() != dht22.OK) {
    Serial.print("last error :");
    Serial.println(dht22.getLastError());
  }

  Serial.print("Humidity=");Serial.print(airHumidity,1);Serial.print("\t");
  Serial.print("Temperature=");Serial.println(airTemperature,1);


  Serial.println();
  Serial.println("closing connection");
  client.stop();

  if (wait) {
    delay(300000);  // execute once every 5 minutes, don't flood remote service
  }
  wait = true;
}
