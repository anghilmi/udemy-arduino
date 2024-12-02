//PROMPT di bagian bawah
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

/*
PROMPT

coba gabungkan 3 kode arduino ini

#kode pertama

int sensorPin = A0; // Pin analog untuk sensor cahaya

int ledPin = 13;    // Pin digital untuk LED

int sensorValue = 0; // Variabel untuk menyimpan nilai sensor

void setup() {

  pinMode(ledPin, OUTPUT); // Atur pin LED sebagai output

  Serial.begin(9600);      // Memulai komunikasi serial

}

void loop() {

  sensorValue = analogRead(sensorPin); // Baca nilai dari sensor cahaya

  Serial.println(sensorValue); // Cetak nilai sensor ke Serial Monitor

  // Jika nilai sensor di bawah ambang batas, nyalakan LED

  if (sensorValue < 500) {

    digitalWrite(ledPin, HIGH);

  } else {

    digitalWrite(ledPin, LOW);

  }

  delay(100); // Tunggu 100 ms sebelum membaca nilai sensor lagi

}

ubah nama variabel menjadi 

int LdrPin = A0; // Pin analog untuk sensor cahaya
int LdrLedPin = 13;    // Pin digital untuk LED
int LdrSensorValue = 0; // Variabel untuk menyimpan nilai sensor

#kode kedua

int led = A1; // Deklarasi LED pada pin A1
int PIR = A0; // Deklarasi Pin Sensor PIR pada A0
int data = 0;       // variabel untuk menampung data PIR
void setup() {
pinMode(led, OUTPUT); //set pin A1 sbg output
pinMode(PIR, INPUT); // set pin A0 sbg input
Serial.begin(9600); //serial monitor
}
void loop(){
  data = digitalRead(PIR);               // baca nilai digital sensor
  Serial.print("Logic PIR: ");           // menampilkan nilai digital sensor pada serial monitor
  Serial.print(data);
  Serial.print(".\n");
  delay(1000);
  
  if (data == HIGH){                     // Instrukasi untuk mengaktifkan LED jika gerakan terdeteksi
  digitalWrite(led, HIGH);               // Mengaktifkan indikator LED
  Serial.println("Gerakan Terdeteksi");  
} 
  else if (data == LOW){                 // Instruksi untuk mematikan LED jika tidak terdeteksi adanya gerakan
  digitalWrite(led, LOW);                // Mematikan LED jika gerakan tidak terdeteksi
  Serial.println("Tidak ada gerakan");   
}
}

ubah nama variabel menjadi 

int ledPIR = 6; // Deklarasi LED pada pin D6
int bacaPIR = A1; // Deklarasi Pin Sensor PIR pada A1
int dataPIR = 0;       // variabel untuk menampung data PIR

#kode ketiga

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

dengan logika gabungan:

bila sensor PIR mendeteksi gerakan dan nilai pembacaan sensor LDR > 500 maka lampu led akan menyala selama 5 menit.

tampilkan juga nilai pembacaan pir, ldr, dan kondisi led di LCD
*/
