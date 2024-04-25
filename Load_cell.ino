#define BLYNK_TEMPLATE_ID "TMPL2EnutY7m-"
#define BLYNK_TEMPLATE_NAME "Load cell"
#define BLYNK_AUTH_TOKEN "_zqKu4R5hIIdZhhsHC56meDuzlxp_mBE"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define Sensor_Data A0

#define Green_led D0
#define Red_led D2
#define Buzz D1
#define offset 210

// Your WiFi credentials
char ssid[] = "Bits";
char pass[] = "1234567890";

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Setup LED pin as an output
  pinMode(Green_led, OUTPUT);
  pinMode(Red_led, OUTPUT);
  pinMode(Buzz, OUTPUT);

}

void loop() {
  Blynk.run();
  digitalWrite(Green_led, LOW);
  digitalWrite(Red_led, LOW);
  digitalWrite(Buzz, LOW);

  // Read analog input
  float rawValue = analogRead(Sensor_Data);
  
  float weight = 10 * ((rawValue - offset) / (1024 - offset));

  if ((weight >= 0.5) && (weight < 8)) {

    digitalWrite(Green_led, HIGH);
    digitalWrite(Red_led, LOW);
    digitalWrite(Buzz, LOW);
  } 
  else if ((weight >= 8) && (weight <= 10)) {
  
  // Button is released, turn off the LED
    digitalWrite(Green_led, LOW);
    digitalWrite(Red_led, HIGH);
    digitalWrite(Buzz, HIGH);
  } 
else {
  Serial.println("Invalid weight range");
}

  // Display the weight in Blynk app
  Blynk.virtualWrite(V0, weight);
  Serial.print("Weight: ");
  Serial.println(weight);

  Serial.print("Raw Value: ");
  Serial.println(rawValue);

  delay(100);  // Adjust the delay as needed
}

