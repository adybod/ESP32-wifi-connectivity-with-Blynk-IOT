#define BLYNK_TEMPLATE_ID
#define BLYNK_TEMPLATE_NAME
#define BLYNK_AUTH_TOKEN
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Your WiFi SSID";
char pass[] = "Your WiFi Password";


BLYNK_WRITE(V4) {
  int value = param.asInt();
  digitalWrite(D10, value);  // Turn LED on or off
}

BLYNK_WRITE(V1) {
  int sliderValue = param.asInt();  // Get value from app
  analogWrite(D10, sliderValue);      // Send it to pin 7 (for PWM devices like buzzer/LED)
}

void setup() {
  Serial.begin(115200);
  pinMode(D10, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}