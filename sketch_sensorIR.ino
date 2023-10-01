// Deklarasi pin yang akan digunakan
const int sensorPin = 2;  // Pin sensor IR terhubung ke pin 2 Arduino
const int relayPin = 3;   // Pin relay terhubung ke pin 3 Arduino

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Mengatur pin sensor sebagai input
  pinMode(sensorPin, INPUT);

  // Mengatur pin relay sebagai output
  pinMode(relayPin, OUTPUT);

  // Matikan relay awalnya
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Membaca nilai dari sensor
  int sensorValue = digitalRead(sensorPin);

  // Jika sensor mendeteksi objek (objek berada dekat sensor)
  if (sensorValue == LOW) {

    Serial.println("Objek Terdeteksi!");
    // Hidupkan relay (misalnya, untuk mengaktifkan perangkat eksternal)
    digitalWrite(relayPin, LOW);
  } else {
    Serial.println("Tidak ada objek.");

    // Matikan relay (misalnya, untuk mematikan perangkat eksternal)
    digitalWrite(relayPin, HIGH);
  }

  // Tunggu sejenak sebelum membaca sensor lagi
  delay(1000);  // Delay 1 detik
}
