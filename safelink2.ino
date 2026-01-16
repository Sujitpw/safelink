#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

/* ------------ GSM & GPS ------------ */

// GSM Module (SIM800 / SIM900)
SoftwareSerial Gsm(2, 3);   // RX, TX

// GPS Module (NEO-6M)
AltSoftSerial gpsSerial;    // D8 (RX), D9 (TX)
TinyGPSPlus gps;

/* ------------ PHONE NUMBER ------------ */

char phone_no[] = "+917254020251";   // change if needed

/* ------------ PINS ------------ */

const int SWITCH = 6;
const int Buzzer = 12;

/* ------------ SETUP ------------ */

void setup() {
  Serial.begin(9600);        // Serial Monitor
  Gsm.begin(115200);         // 🔥 IMPORTANT: GSM baud
  gpsSerial.begin(9600);     // GPS baud

  pinMode(SWITCH, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);

  delay(3000);
  Serial.println("System Ready");
}

/* ------------ LOOP ------------ */

void loop() {

  // Continuously read GPS data
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (digitalRead(SWITCH) == LOW) {
    digitalWrite(Buzzer, HIGH);
    Serial.println("SOS PRESSED");

    sendEmergencySMS();

    digitalWrite(Buzzer, LOW);
    delay(5000);   // avoid repeated SMS
  }
}

/* ------------ SEND SMS FUNCTION ------------ */

void sendEmergencySMS() {

  // Set GSM to text mode
  Gsm.print("AT+CMGF=1\r");
  delay(500);

  // SMS command
  Gsm.print("AT+CMGS=\"");
  Gsm.print(phone_no);
  Gsm.println("\"");
  delay(500);

  // If GPS location is valid
  if (gps.location.isValid()) {
    Gsm.print("EMERGENCY PLEASE HELP ME\n");
    Gsm.print("My Location:\n");
    Gsm.print("https://www.google.com/maps?q=");
    Gsm.print(gps.location.lat(), 6);
    Gsm.print(",");
    Gsm.print(gps.location.lng(), 6);

    Serial.println("SMS sent with GPS location");
  }
  // If GPS not available
  else {
    Gsm.print("EMERGENCY PLEASE HELP ME\n");
    Gsm.print("Location not available");

    Serial.println("SMS sent without GPS");
  }

  // End SMS
  Gsm.write(26);   // CTRL+Z
  delay(5000);
}
