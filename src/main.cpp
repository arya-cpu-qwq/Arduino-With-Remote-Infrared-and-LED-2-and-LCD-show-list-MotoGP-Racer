#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// --- Konfigurasi Pin ---
const int RECV_PIN = 2;
const int LED_HIJAU = 3; // Sesuaikan dengan kabel di Wokwi (biasanya pin 3)
const int LED_MERAH = 5; // Sesuaikan dengan kabel di Wokwi (biasanya pin 5)

// --- Nilai command tombol remote ---
#define CMD_NEXT 0x30     // Tombol "1"
#define CMD_PREV 0x18     // Tombol "2"

LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Data Pembalap ---
String tim[] = {"Ducati Lenovo", "Repsol Honda", "Monster Yamaha", "Red Bull KTM", "Aprilia Racing"};
String pembalap[] = {"Pecco Bagnaia", "Marc Marquez", "Fabio Quartararo", "Brad Binder", "Aleix Espargaro"};

int currentIndex = -1; 
int totalData = 5;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  // Inisialisasi LED sebagai OUTPUT
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);

  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Daftar MotoGP");
  lcd.setCursor(0, 1);
  lcd.print("Tekan 1 atau 2");
}

void displayRider(int index) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(tim[index]);
  lcd.setCursor(0, 1);
  lcd.print(pembalap[index]);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;

    if (command == CMD_NEXT) {
      currentIndex++;
      if (currentIndex >= totalData) currentIndex = 0;
      
      displayRider(currentIndex);

      // Nyalakan LED Hijau sebentar
      digitalWrite(LED_HIJAU, HIGH);
      delay(200); 
      digitalWrite(LED_HIJAU, LOW);
    }

    else if (command == CMD_PREV) {
      currentIndex--;
      if (currentIndex < 0) currentIndex = totalData - 1;
      
      displayRider(currentIndex);

      // Nyalakan LED Merah sebentar
      digitalWrite(LED_MERAH, HIGH);
      delay(200);
      digitalWrite(LED_MERAH, LOW);
    }

    IrReceiver.resume();
  }
}