#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Motor A
#define ENA 25
#define IN1 26
#define IN2 27

// Motor B
#define ENB 14
#define IN3 12
#define IN4 13

int velocidade = 200; // 0 a 255

void setup() {
  Serial.begin(115200);

  SerialBT.begin("Carrinho_ESP32");
  Serial.println("Bluetooth iniciado como: Carrinho_ESP32");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  parar();
}

void loop() {
  if (SerialBT.available()) {
    char comando = SerialBT.read();

    Serial.print("Comando recebido: ");
    Serial.println(comando);

    if (comando == 'F') {
      frente();
    }

    else if (comando == 'B') {
      tras();
    }

    else if (comando == 'L') {
      esquerda();
    }

    else if (comando == 'R') {
      direita();
    }

    else if (comando == 'S') {
      parar();
    }
  }
}

void frente() {
  Serial.println("Frente");

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {
  Serial.println("Tras");

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda() {
  Serial.println("Esquerda");

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {
  Serial.println("Direita");

  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void parar() {
  Serial.println("Parar");

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}