#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN  9
#define CSN_PIN 10
RF24 radio(CE_PIN, CSN_PIN);

// Must match TX exactly (5 bytes)
const uint8_t pipeAddr[5] = {'R','x','A','A','A'};

struct pot { int value; };

void setup() {
  Serial.begin(115200);

 radio.begin();
  radio.setDataRate(RF24_250KBPS);  // match TX
  radio.openReadingPipe(1, pipeAddr);
  radio.startListening();

  Serial.println("RX ready");
}

void loop() {
  while (radio.available()) {
    pot received{};
    radio.read(&received, sizeof(received));
    Serial.print("Data received: ");
    Serial.println(received.value);
  }
}
