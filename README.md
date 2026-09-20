# ESP32 RFID Access Control System (PlatformIO)

Proyek sistem akses kontrol pintu otomatis menggunakan mikrokontroler **ESP32**, modul pembaca RFID **MFRC522**, **LCD I2C (16x2)**, **Motor Servo** sebagai penggerak palang pintu, **LED Indikator**, dan **Buzzer** sebagai pemberi suara peringatan. Proyek ini dikonfigurasi menggunakan framework **Arduino** melalui **PlatformIO** di VS Code.

---

## 🛠️ Daftar Komponen & Perangkat Keras
1. **ESP32 Dev Board**
2. **RFID MFRC522** (Modul Pembaca & Kartu/Tag)
3. **LCD 1602 dengan Modul I2C**
4. **Motor Servo** (SG90 / MG90S)
5. **LED Indikator + Resistor (220Ω / 1KΩ)**
6. **Buzzer**
7. **Breadboard & Kabel Jumper**

---

## 📌 Jalur Sambungan Pin & Breadboard (Wiring Diagram)

Berikut adalah rincian sambungan kabel antara komponen dan pin pada ESP32:

### 1. Modul RFID MFRC522 (Komunikasi SPI)
* **VCC / 3.3V** ➔ Jalur **3V3** ESP32 *(Catatan: Jangan hubungkan ke 5V agar modul tidak rusak)*
* **GND** ➔ Jalur **GND** ESP32
* **RST (Reset)** ➔ Pin **GPIO 4** ESP32
* **SDA (SS / NSS)** ➔ Pin **GPIO 5** ESP32
* **MOSI** ➔ Pin **GPIO 23** ESP32
* **MISO** ➔ Pin **GPIO 19** ESP32
* **SCK** ➔ Pin **GPIO 18** ESP32

### 2. LCD 16x2 dengan Modul I2C
* **GND** ➔ Jalur **GND** ESP32
* **VCC** ➔ Jalur **5V / VIN** ESP32
* **SDA** ➔ Pin **GPIO 21** ESP32
* **SCL** ➔ Pin **GPIO 22** ESP32

### 3. Periferal Lainnya
* **LED Indikator**: 
  * Kaki Panjang (Anoda) ➔ Melalui resistor ke Pin **GPIO 2** ESP32
  * Kaki Pendek (Katoda) ➔ Jalur **GND** ESP32
* **Buzzer**:
  * Kaki Positif (+) ➔ Pin **GPIO 3** ESP32
  * Kaki Negatif (-) ➔ Jalur **GND** ESP32
* **Motor Servo**:
  * Kabel Coklat/Hitam (GND) ➔ Jalur **GND** ESP32
  * Kabel Merah (VCC) ➔ Jalur **5V / VIN** ESP32
  * Kabel Oranye/Kuning (PWM/Signal) ➔ Pin **GPIO 1** ESP32

---

## 💻 Pustaka (Libraries) yang Digunakan
Konfigurasi library ini diatur otomatis di dalam file `platformio.ini`:
* `miguelbalboa/MFRC522` (Versi ^1.4.10)
* `marcoschwartz/LiquidCrystal_I2C` (Versi ^1.1.4)
* `madhephaestus/ESP32Servo` (Versi ^3.0.5)

---

## 🚀 Cara Menjalankan Proyek

1. **Clone Repository:**
   ```bash
   git clone [https://github.com/IsnaZ23/IoT-Projek.git](https://github.com/IsnaZ23/IoT-Projek.git)
