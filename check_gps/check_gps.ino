#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Wire.h>

SoftwareSerial Gsm(7, 8);           // RX, TX pins for GSM module
SoftwareSerial gpsSerial(10, 11);   // RX, TX pins for GPS module
char phone_no[] = "+8801752433467"; // Replace with your phone number
TinyGPS gps;

int buttonPin = 3;
int buzzer = 4;
int buttonState;
unsigned long lastButtonPressTime = 0;
bool isSMSsent = false;

void setup() {
  Serial.begin(9600);        // For debugging
  Gsm.begin(9600);           // For GSM module
  gpsSerial.begin(9600);     // For GPS module

  // Configure GSM module
  Gsm.print("AT+CMGF=1\r");  // Set SMS mode to text
  delay(100);
  Gsm.print("AT+CNMI=2,2,0,0,0\r"); // Configure SMS reception
  delay(100);

  // Set up pins
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW); // Ensure buzzer is off initially
}

void loop() {
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
  float flat = TinyGPS::GPS_INVALID_F_ANGLE;
  float flon = TinyGPS::GPS_INVALID_F_ANGLE;

  // Check for new GPS data
  for (unsigned long start = millis(); millis() - start < 1000;) {
    while (gpsSerial.available()) {
      char c = gpsSerial.read();
      if (gps.encode(c)) {
        newData = true;  // New GPS data available
      }
    }
  }

  // Get GPS position
  if (newData) {
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
  }

  // Read button state
  buttonState = digitalRead(buttonPin);

  // Handle button press with debounce
  if (buttonState == LOW && millis() - lastButtonPressTime > 1000) { 
    lastButtonPressTime = millis();  // Update last press time

    if (!isSMSsent) {
      // Validate GPS data
      if (flat == TinyGPS::GPS_INVALID_F_ANGLE || flon == TinyGPS::GPS_INVALID_F_ANGLE) {
        Serial.println("Invalid GPS data. Waiting for valid data...");
        return;
      }

      // Send SMS
      sendSMS(flat, flon);
      digitalWrite(buzzer, HIGH); // Turn on buzzer for alert
      delay(1000);               // Buzzer duration
      digitalWrite(buzzer, LOW); // Turn off buzzer
      isSMSsent = true;          // Mark SMS as sent
    }
  } else if (buttonState == HIGH && isSMSsent) {
    isSMSsent = false;  // Reset SMS flag when button is released
  }

  // Print debug information
  gps.stats(&chars, &sentences, &failed);
  Serial.print("Latitude: "); Serial.println(flat, 6);
  Serial.print("Longitude: "); Serial.println(flon, 6);
  Serial.print("Button State: "); Serial.println(buttonState);
}

// Function to send SMS
void sendSMS(float latitude, float longitude) {
  Gsm.print("AT+CMGS=\"");
  Gsm.print(phone_no);
  Gsm.println("\"");
  delay(200);
  Gsm.print("I am in danger! Lat: ");
  Gsm.print(latitude, 6);  // Send latitude with precision
  Gsm.print(", Lon: ");
  Gsm.print(longitude, 6); // Send longitude with precision
  Gsm.write((char)26);     // End of SMS
  delay(200);
  Serial.println("SMS Sent");
}

