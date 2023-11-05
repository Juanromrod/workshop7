#include <Wire.h>

const int ledPin = 7; // Cambia el número del pin al que está conectado tu LED externo

void setup() {
  Wire.begin(8); // Inicializa la comunicación I2C y establece la dirección del Arduino receptor o ESP32
  Wire.onReceive(receiveData); // Configura la función de recepción de datos
  Serial.begin(9600); // Inicializa el Monitor Serie
  pinMode(ledPin, OUTPUT); // Configura el pin del LED externo como salida
  digitalWrite(ledPin, LOW); // Apaga el LED al inicio
}

void loop() {
  // El bucle principal no necesita hacer nada aquí, ya que la recepción de datos se maneja en receiveData
}

void receiveData(int byteCount) {
  if (byteCount == sizeof(float)) {
    float temperature;
    Wire.readBytes((byte *)&temperature, sizeof(temperature));

    Serial.print("Temperatura recibida: ");
    Serial.print(temperature);
    Serial.println(" grados Celsius");

    if (temperature >= 30.0) {
      digitalWrite(ledPin, HIGH); // Enciende el LED externo si la temperatura es igual o superior a 30 grados
    } else {
      digitalWrite(ledPin, LOW); // Apaga el LED externo si la temperatura es inferior a 30 grados
    }
  }
}