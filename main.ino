//////////////////////// DEFAULT

// void setup() {
//   // put your setup code here, to run once:

// }

// void loop() {
//   // put your main code here, to run repeatedly:

// }

//////////////////////// DEFAULT END


//////////////////////// TES BLINK
// void setup() {
//   // initialize digital pin LED_BUILTIN as an output.
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// // the loop function runs over and over again forever
// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
//   delay(1000);                      // wait for a second
//   digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
//   delay(1000);                      // wait for a second
// }

//////////////////////// END BLINK

//////////////////////// LDR

// int sensorPin = A0; // Pin analog untuk sensor cahaya

// int ledPin = 13;    // Pin digital untuk LED

// int sensorValue = 0; // Variabel untuk menyimpan nilai sensor

// void setup() {

//   pinMode(ledPin, OUTPUT); // Atur pin LED sebagai output

//   Serial.begin(9600);      // Memulai komunikasi serial

// }

// void loop() {

//   sensorValue = analogRead(sensorPin); // Baca nilai dari sensor cahaya

//   Serial.println(sensorValue); // Cetak nilai sensor ke Serial Monitor

//   // Jika nilai sensor di bawah ambang batas, nyalakan LED

//   if (sensorValue > 500) { //ada koreksi

//     digitalWrite(ledPin, HIGH);

//   } else {

//     digitalWrite(ledPin, LOW);

//   }

//   delay(100); // Tunggu 100 ms sebelum membaca nilai sensor lagi

// }

//////////////////////// LDR END

//////////////////////// LCD

// include the library code:
// #include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// void setup() {
//   // set up the LCD's number of columns and rows:
//   lcd.begin(16, 2);
//   // Print a message to the LCD.
//   lcd.print("hello, world!");
// }

// void loop() {
//   // set the cursor to column 0, line 1
//   // (note: line 1 is the second row, since counting begins with 0):
//   lcd.setCursor(0, 1);
//   // print the number of seconds since reset:
//   lcd.print(millis() / 1000);
// }

//////////////////////// LCD END

//////////////////////// PIR

// int led = 6; // Deklarasi LED pada pin D6
// int PIR = A1; // Deklarasi Pin Sensor PIR pada A0
// int data = 0;       // variabel untuk menampung data PIR

// void setup() {
// pinMode(led, OUTPUT); //set pin D6 sbg output
// pinMode(PIR, INPUT); // set pin A1 sbg input
// Serial.begin(9600); //serial monitor
// }

// void loop(){
//   data = digitalRead(PIR);               // baca nilai digital sensor
//   Serial.print("Logic PIR: ");           // menampilkan nilai digital sensor pada serial monitor
//   Serial.print(data);
//   Serial.print(".\n");
//   delay(1000);
  
//   if (data == HIGH){                     // Instrukasi untuk mengaktifkan LED jika gerakan terdeteksi
//   digitalWrite(led, HIGH);               // Mengaktifkan indikator LED
//   Serial.println("Gerakan Terdeteksi");  
// } 

//   else if (data == LOW){                 // Instruksi untuk mematikan LED jika tidak terdeteksi adanya gerakan
//   digitalWrite(led, LOW);                // Mematikan LED jika gerakan tidak terdeteksi
//   Serial.println("Tidak ada gerakan");   
// }
// }

//////////////////////// PIR END

//////////////////////// GABUNG 

// // include the library code:
#include <LiquidCrystal.h>

// // initialize the library by associating any needed LCD interface pin
// // with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ledPIR = 6; // Deklarasi LED pada pin D6
int bacaPIR = A1; // Deklarasi Pin Sensor PIR pada A1
int dataPIR = 0;       // variabel untuk menampung data PIR

int LdrPin = A0; // Pin analog untuk sensor cahaya
int LdrLedPin = 13;    // Pin digital untuk LED
int LdrSensorValue = 0; // Variabel untuk menyimpan nilai sensor

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Udemy - Arduino");
  delay(1000);
  lcd.clear();
  pinMode(ledPIR, OUTPUT); //set pin D6 sbg output
  pinMode(bacaPIR, INPUT); // set pin A1 sbg input
  Serial.begin(9600); //serial monitor

  pinMode(LdrLedPin, OUTPUT); // Atur pin LED sebagai output


}

void loop() {

  // tahap 1, sesuaikan LCD
  // lcd.setCursor(0, 1);
  // lcd.print("yo");
  // delay(1000);

  // lcd.setCursor(0, 1);
  // lcd.print("ya");
  // delay(1000);

  // tahap 2, gabung PIR dan LCD

  // dataPIR = digitalRead(bacaPIR);// baca nilai digital sensor
  // Serial.print("Logic PIR: ");   // menampilkan nilai digital sensor pada serial monitor
  // Serial.print(dataPIR);
  // Serial.print(".\n");
  // delay(500);
  
  // if (dataPIR == HIGH){          // Instrukasi untuk mengaktifkan LED jika gerakan terdeteksi
  //   digitalWrite(ledPIR, HIGH);     // Mengaktifkan indikator LED
  //   Serial.println("Gerakan Terdeteksi"); 

  //   lcd.setCursor(0, 1);
  //   lcd.print("Gerakan Terdeteksi");
  //   delay(500); 
  // } 

  // else if (dataPIR == LOW){   // Instruksi untuk mematikan LED jika tidak terdeteksi adanya gerakan
  //   digitalWrite(ledPIR, LOW);      // Mematikan LED jika gerakan tidak terdeteksi
  //   Serial.println("Tidak ada gerakan"); 

  //   lcd.setCursor(0, 1);
  //   lcd.print("Tidak ada gerakan");
  //   delay(500);       
  // }

  // tahap 3 gabung PIR, LCD, dan LDR
  // lcd.clear();

  dataPIR = digitalRead(bacaPIR);// baca nilai digital sensor
  Serial.print("Logic PIR: ");   // menampilkan nilai digital sensor pada serial monitor
  Serial.print(dataPIR);
  Serial.print(".\n");
  delay(100);

  lcd.setCursor(0, 0);
  lcd.print("PIR:");
  lcd.setCursor(4, 0);
  lcd.print(dataPIR);
  delay(500); 

  LdrSensorValue = analogRead(LdrPin); // Baca nilai dari sensor cahaya
  Serial.println(LdrSensorValue); // Cetak nilai sensor ke Serial Monitor
  
  lcd.setCursor(6, 0);
  lcd.print("LDR:");
  lcd.setCursor(10, 0);
  lcd.print(LdrSensorValue);
  delay(500); 
  
  if (dataPIR == HIGH && LdrSensorValue > 500){          // Instrukasi untuk mengaktifkan LED jika gerakan terdeteksi
    digitalWrite(ledPIR, HIGH);     // Mengaktifkan indikator LED
    Serial.println("Lampu Nyala"); 

    digitalWrite(LdrLedPin, HIGH);


    lcd.setCursor(0, 1);
    lcd.print("Lampu Nyala");
    delay(300000); //5 menit
  } 

  else if (dataPIR == LOW){   // Instruksi untuk mematikan LED jika tidak terdeteksi adanya gerakan
    digitalWrite(ledPIR, LOW);      // Mematikan LED jika gerakan tidak terdeteksi
    Serial.println("Lampu Padam"); 

    digitalWrite(LdrLedPin, LOW);


    lcd.setCursor(0, 1);
    lcd.print("Lampu Padam");
    delay(500);       
  }

//   Serial.println(sensorValue); // Cetak nilai sensor ke Serial Monitor
//   // Jika nilai sensor di bawah ambang batas, nyalakan LED
//   if (sensorValue > 500) { //ada koreksi
//     digitalWrite(ledPin, HIGH);
//   } else {
//     digitalWrite(ledPin, LOW);
//   }
//   delay(100); // Tunggu 100 ms sebelum membaca nilai sensor lagi
}

//////////////////////// GABUNG END

