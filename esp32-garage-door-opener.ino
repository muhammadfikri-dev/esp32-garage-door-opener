#define PIN_RELAY_TRIGGER 26
#define PIN_REED_CLOSED 27

void toggleDoor() {
  digitalWrite(PIN_RELAY_TRIGGER, LOW);
  delay(500);
  digitalWrite(PIN_RELAY_TRIGGER, HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY_TRIGGER, OUTPUT);
  digitalWrite(PIN_RELAY_TRIGGER, HIGH);
  pinMode(PIN_REED_CLOSED, INPUT_PULLUP);
}

void loop() {
  bool isClosed = (digitalRead(PIN_REED_CLOSED) == LOW);
  Serial.printf("Garage Door Status: %s\n", isClosed ? "CLOSED" : "OPEN");
  delay(2000);
}