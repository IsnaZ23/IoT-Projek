#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

// Definisi Pin Sesuai Rangkaian
#define RST_PIN  4    
#define SS_PIN   5    
#define LED_PIN  2    
#define BUZZER_PIN 3  
#define SERVO_PIN 1   

// Inisialisasi Objek
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

byte authorizedUID[] = {0xDE, 0xAD, 0xBE, 0xEF}; 

void setup() {
  Serial.begin(115200);
  SPI.begin();          
  mfrc522.PCD_Init();   
  
  lcd.init();                      
  lcd.backlight();
  
  myServo.attach(SERVO_PIN);
  myServo.write(0); 
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("  TEMPELKAN KARTU ");
  lcd.setCursor(0, 1);
  lcd.print("   UNTUK AKSES    ");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID Kartu: ");
  bool accessGranted = true;
  
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    
    if (mfrc522.uid.uidByte[i] != authorizedUID[i]) {
      accessGranted = false;
    }
  }
  Serial.println();

  lcd.clear();
  if (accessGranted) {
    lcd.setCursor(0, 0);
    lcd.print(" AKSES DITERIMA ");
    lcd.setCursor(0, 1);
    lcd.print(" Silakan Masuk  ");
    
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    
    myServo.write(90); 
    delay(3000); 
    
    myServo.write(0);  
    digitalWrite(LED_PIN, LOW);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("  AKSES DITOLAK ");
    lcd.setCursor(0, 1);
    lcd.print(" Kartu Salah!   ");
    
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  TEMPELKAN KARTU "); // catatan: pastikan perintah print biasa
  lcd.setCursor(0, 1);
  lcd.print("   UNTUK AKSES    ");
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}