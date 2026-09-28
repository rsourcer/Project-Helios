/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255
  and uses the result to set the pulse-width modulation (PWM) of an
  output pin (the illumination LED). Also prints the results to the
  serial monitor.

  The circuit:
  * light sensor (photodiode/phototransistor) connected to analog pin A0.
    Center pin of the sensor circuit goes to the analog pin. Side pins
    go to +5V and ground (with appropriate pull-down/bias resistor).
  * Illumination LED connected from digital pin 9 to ground (through a
    current-limiting resistor), on a PWM-capable pin.

  created 29 Dec. 2008
  modified 26 Sept. 2026
  by Raoul Zachary Docteur Salemi
  This code is in the public domain.
*/

int sensorValue = 0;
int outputValue = 0;

const int sensorPin = A0;
const int ledPin = 9;   // must be a PWM-capable pin (3, 5, 6, 9, 10, 11 on Uno)

// Helper function to reject 60Hz/120Hz noise via 16.667ms window integration
int readMainsFilteredSensor(int pin) {
  long sum = 0;
  int samples = 0;
  unsigned long startTime = micros();

  // Accumulate readings across exactly 1 full 60 Hz / 2 full 120 Hz cycles (16,667 microseconds)
  while (micros() - startTime < 16667) {
    sum += analogRead(pin);
    samples++;
  }

  if (samples == 0) return analogRead(pin); // Fallback safeguard
  return (int)(sum / samples);
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Turn on the illumination LED
  digitalWrite(ledPin, HIGH);

  // Read the detector output with 120 Hz line noise rejection
  sensorValue = readMainsFilteredSensor(sensorPin);

  // Convert 0-1023 ADC reading to 0-255 PWM value
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // Drive LED based on measured light intensity
  analogWrite(ledPin, outputValue);

  Serial.print("sensor = ");
  Serial.println(sensorValue);

  // Small delay between output iterations (adjust rate as needed)
  delay(10);
}