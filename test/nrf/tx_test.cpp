#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN  9
#define CSN_PIN 10
RF24 radio(CE_PIN, CSN_PIN);

// 5-byte address (exactly 5 bytes; NOT a null-terminated string)
const uint8_t pipeAddr[5] = {'R','x','A','A','A'};

struct pot { int value; } pkt;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

  radio.begin();
  radio.setDataRate(RF24_250KBPS);  // match RX
  radio.openWritingPipe(pipeAddr);
  radio.stopListening(); // TX mode

  Serial.println("TX ready");
}

void loop() {
  int raw = analogRead(A1);          // 0..1023
  pkt.value = raw;

  bool ok = radio.write(&pkt, sizeof(pkt));
  Serial.print("\nSent pot: "); Serial.print(raw);
  delay(500);
}
