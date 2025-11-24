#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

String serverName = "http://10.0.0.101:1880/iot/checkin";  
// TROCAR PELO IP DO SEU NODE-RED

const int BTN = 13; 
const int LED = 2;

bool estudando = false;

void setup() {
  Serial.begin(115200);

  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.println("Conectando...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.println(WiFi.localIP());
}

void enviar(String tipo) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"deviceId\":\"esp32-mnm\",\"tipo\":\"" + tipo + "\"}";
    int resp = http.POST(payload);
    Serial.print("Evento enviado: ");
    Serial.println(resp);

    http.end();
  }
}

void loop() {
  int leitura = digitalRead(BTN);

  if (leitura == LOW && !estudando) {
    estudando = true;
    digitalWrite(LED, HIGH);
    enviar("checkin");
    delay(1000);
  }

  if (leitura == HIGH && estudando) {
    estudando = false;
    digitalWrite(LED, LOW);
    enviar("checkout");
    delay(1000);
  }
}
