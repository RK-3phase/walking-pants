// Arduino Mega Basic Diagnostic Test

const int ledPin = 13;
const int analogPin = A0;
unsigned long t0 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin, INPUT);

  Serial.println("Starting diagnostics...");

  // Serial confirm
  Serial.println("Serial OK");

  // ADC test
  int value = analogRead(analogPin);
  if (value >= 0 && value <= 1023) {
    Serial.println("ADC OK");
  } else {
    Serial.println("ADC FAIL");
  }

  // Timer test (verify millis increments)
  unsigned long m1 = millis();
  delay(100);
  unsigned long m2 = millis();
  if (m2 > m1) {
    Serial.println("Timer OK");
  } else {
    Serial.println("Timer FAIL");
  }

  Serial.println("Now testing LED blink... (press RESET to confirm restart)");
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);

  if (millis() - t0 > 2000) {
    t0 = millis();
    Serial.println("blinking...");
  }
}
