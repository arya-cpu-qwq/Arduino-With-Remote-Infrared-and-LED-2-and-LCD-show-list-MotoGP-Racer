# Arduino MotoGP Rider List with IR Remote, LEDs, and LCD

Proyek ini menampilkan daftar tim dan pembalap MotoGP pada layar LCD I2C, dikontrol menggunakan remote infra merah.

## Fitur

- Memindahkan daftar pembalap dengan remote IR
- Menampilkan tim dan nama pembalap di LCD 16x2 I2C
- Menyalakan LED hijau untuk tombol "Next" dan LED merah untuk tombol "Previous"
- Menggunakan Arduino Uno sebagai kontrol utama

## Komponen yang digunakan

- Arduino Uno
- Receiver IR pada pin digital 2
- LCD 16x2 dengan modul I2C (alamat 0x27)
- LED hijau pada pin 3
- LED merah pada pin 5
- Resistor 220Ω untuk setiap LED
- Remote infra merah yang kompatibel dengan library IRremote

## Wiring / Koneksi

- IR Receiver: pin data ke `D2`
- LED hijau: ke `D3` lewat resistor ke GND
- LED merah: ke `D5` lewat resistor ke GND
- LCD I2C: `SDA` ke `A4`, `SCL` ke `A5`, `VCC` ke `5V`, `GND` ke `GND`

> Catatan: susunan pin pada kit Wokwi atau papan lain dapat berbeda, sesuaikan dengan koneksi fisik Anda.

## Library dan dependensi

Project menggunakan PlatformIO dengan dependensi berikut pada `platformio.ini`:

- `marcoschwartz/LiquidCrystal_I2C@^1.1.4`
- `z3t0/IRremote@^4.7.1`

## Cara menggunakan

1. Upload program ke Arduino Uno menggunakan PlatformIO.
2. Pastikan LCD menampilkan pesan awal:
   - Baris 1: `Daftar MotoGP`
   - Baris 2: `Tekan 1 atau 2`
3. Tekan tombol `1` pada remote untuk maju ke entri berikutnya.
4. Tekan tombol `2` pada remote untuk kembali ke entri sebelumnya.

## Kode utama

File utama berada di `src/main.cpp`.

- `CMD_NEXT` menggunakan nilai kode IR `0x30` untuk tombol `1`
- `CMD_PREV` menggunakan nilai kode IR `0x18` untuk tombol `2`
- Data tim dan nama pembalap disimpan dalam array `String`

## Pengembangan

- Tambahkan data pembalap baru pada array `tim[]` dan `pembalap[]`.
- Ubah alamat LCD I2C jika modul Anda tidak menggunakan `0x27`.
- Sesuaikan pin LED atau pin IR receiver jika menggunakan papan lain.

## Lisensi

Proyek ini bersifat bebas untuk digunakan dan dimodifikasi.
