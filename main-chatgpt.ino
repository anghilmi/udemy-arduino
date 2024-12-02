#include <LiquidCrystal.h>

// Pin untuk LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pin dan variabel untuk sensor LDR
int LdrPin = A0;          // Pin analog untuk sensor cahaya
int LdrLedPin = 13;       // Pin digital untuk LED indikator
int LdrSensorValue = 0;   // Variabel untuk menyimpan nilai sensor LDR

// Pin dan variabel untuk sensor PIR
int ledPIR = 6;           // Pin untuk LED output
int bacaPIR = A1;         // Pin untuk Sensor PIR
int dataPIR = 0;          // Variabel untuk menyimpan data dari PIR

// Variabel waktu
unsigned long ledOnTime = 0;  // Waktu LED mulai menyala
const unsigned long delayTime = 300000; // Durasi 5 menit (300.000 ms)

void setup() {
  // Inisialisasi pin
  pinMode(LdrLedPin, OUTPUT);
  pinMode(ledPIR, OUTPUT);
  pinMode(LdrPin, INPUT);
  pinMode(bacaPIR, INPUT);

  // Inisialisasi Serial Monitor
  Serial.begin(9600);

  // Inisialisasi LCD
  lcd.begin(16, 2);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Baca nilai dari sensor
  LdrSensorValue = analogRead(LdrPin);  // Baca nilai LDR
  dataPIR = digitalRead(bacaPIR);      // Baca nilai PIR

  // Tampilkan nilai sensor di Serial Monitor
  Serial.print("LDR: ");
  Serial.print(LdrSensorValue);
  Serial.print(" | PIR: ");
  Serial.println(dataPIR);

  // Logika nyala LED
  if (dataPIR == HIGH && LdrSensorValue > 500) {
    digitalWrite(LdrLedPin, HIGH);     // Nyalakan LED
    ledOnTime = millis();             // Catat waktu LED mulai menyala
  }

  // Matikan LED setelah 5 menit
  if (millis() - ledOnTime >= delayTime) {
    digitalWrite(LdrLedPin, LOW);
  }

  // Tampilkan data di LCD
  lcd.setCursor(0, 0);
  lcd.print("PIR:");
  lcd.print(dataPIR ? "Gerak" : "Diam");
  lcd.setCursor(8, 0);
  lcd.print("LDR:");
  lcd.print(LdrSensorValue);

  lcd.setCursor(0, 1);
  lcd.print("LED:");
  lcd.print(digitalRead(LdrLedPin) ? "ON " : "OFF");
  lcd.setCursor(8, 1);
  lcd.print("Time:");
  lcd.print((millis() - ledOnTime) / 1000);

  delay(500); // Delay untuk pembaruan tampilan
}
