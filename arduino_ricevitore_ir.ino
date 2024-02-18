#include <IRremote.h> // Include the IRremote library

int receiver = 11; // IR receiver pin connected to Arduino digital pin 11
IRrecv irrecv(receiver); // Create an instance of 'irrecv' for receiving IR signals
decode_results results; // Variable to store the decoded IR results

void setup() {
  Serial.begin(9600); // Initialize serial communication for serial monitor output
  irrecv.enableIRIn(); // Start the IR receiver
  pinMode(9, OUTPUT); // Set pin 9 as output for controlling an LED
}

void loop() {
  if (irrecv.decode(&results)) { // Check if we have received an IR signal
    Serial.println(results.value, HEX); // Display the received signal value in hexadecimal on the serial monitor
    irrecv.resume(); // Continue to receive the next IR signal
  }
}
