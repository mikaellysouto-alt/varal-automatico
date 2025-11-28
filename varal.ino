#include <Servo.h>
#include <DHT.h>

#define LDR_PIN A0     // LDR conectado ao pino A0
#define DHTPIN 2       // Pino do DHT11
#define DHTTYPE DHT11  // Tipo do sensor

Servo varal;
DHT dht(DHTPIN, DHTTYPE);  // Declaração correta do objeto DHT

int ldrValor;
float umidade;

void setup() {
  Serial.begin(9600);
  varal.attach(9);   // Servo no pino 9
  dht.begin();       // Inicia o DHT (sem parâmetro!)
}

void loop() {
  // Lê LDR
  ldrValor = analogRead(LDR_PIN);

  // Lê umidade
  umidade = dht.readHumidity();

  // Mostra no monitor serial
  Serial.print("LDR: ");
  Serial.print(ldrValor);
  Serial.print(" | Umidade: ");
  Serial.println(umidade);

  // Controle do varal
  if (ldrValor < 500 || umidade > 70) {
    varal.write(0);   // Recolhe
  } else {
    varal.write(90);  // Estende
  }

  delay(1000);  // Atualiza a cada 1s
}
