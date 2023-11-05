#include <Wire.h>

const int lm35Pin = A1; // Pin analógico al que está conectado el LM35

void setup() {
  Wire.begin(); // Inicializa la comunicación I2C
}

void loop() {
  int rawValue = analogRead(lm35Pin);
  float temperature = (rawValue / 1024.0) * 500.0; // Convierte el valor analógico a grados Celsius

  Wire.beginTransmission(8); // Dirección del Arduino receptor (o ESP32)
  Wire.write((byte *)&temperature, sizeof(temperature)); // Envía los datos como bytes
  Wire.endTransmission();

  delay(1000); // Espera un segundo antes de tomar otra lectura
}