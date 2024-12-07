#include "BluetoothSerial.h" // Include BluetoothSerial library for ESP32

BluetoothSerial SerialBT; // Initialize Bluetooth serial object
byte inbytes[4];          // Correctly declare the array with a semicolon

void setup() {
  Serial.begin(115200);        // Start serial communication for debugging
  SerialBT.begin("ESP32_BT");  // Initialize Bluetooth with the device name "ESP32_BT"
  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
  // Check if there is data available from Bluetooth
  if (SerialBT.available() >= 4) { // Ensure there are at least 4 bytes to read
    SerialBT.readBytes(inbytes, 4); // Read 4 bytes into the inbytes array

    // Print the received values to the serial monitor
    Serial.print(inbytes[0]);
    Serial.print(" ");
    Serial.print(inbytes[1]);
    Serial.print(" ");
    Serial.print(inbytes[2]);
    Serial.print(" ");
    Serial.println(inbytes[3]);
  }
}
