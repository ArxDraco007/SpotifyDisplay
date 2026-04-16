#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

const char* pcIP = "192.168.1.47";
const int port = 5000;

// Buttons
#define NEXT_BTN 12
#define PREV_BTN 13
#define PLAY_BTN 14

// Encoder
#define CLK 32
#define DT 33
#define SW 25  // optional press

int lastCLK;

void sendCommand(String cmd) {
  WiFiClient client;

  if (client.connect(pcIP, port)) {
    client.print("GET /" + cmd + " HTTP/1.1\r\n");
    client.print("Host: " + String(pcIP) + "\r\n");
    client.print("Connection: close\r\n\r\n");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(NEXT_BTN, INPUT_PULLUP);
  pinMode(PREV_BTN, INPUT_PULLUP);
  pinMode(PLAY_BTN, INPUT_PULLUP);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);

  lastCLK = digitalRead(CLK);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected!");
}

void loop() {

  // 🔘 BUTTONS
  if (digitalRead(NEXT_BTN) == LOW) {
    sendCommand("next");
    delay(300);
  }

  if (digitalRead(PREV_BTN) == LOW) {
    sendCommand("prev");
    delay(300);
  }

  if (digitalRead(PLAY_BTN) == LOW) {
    sendCommand("play");
    delay(300);
  }

  // 🔄 ROTARY ENCODER
  int currentCLK = digitalRead(CLK);

  if (currentCLK != lastCLK) {
    if (digitalRead(DT) != currentCLK) {
      Serial.println("Volume Up");
      sendCommand("volup");
    } else {
      Serial.println("Volume Down");
      sendCommand("voldown");
    }
  }

  lastCLK = currentCLK;

  // 🔘 ENCODER BUTTON (optional mute)
  if (digitalRead(SW) == LOW) {
    sendCommand("play");  // or mute if you want
    delay(300);
  }
}