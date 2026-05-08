# Arduino MotoGP Racer List with IR Remote, LEDs, and LCD

Proyek Arduino ini menampilkan daftar tim dan pembalap MotoGP pada layar LCD I2C. Pengguna dapat menavigasi daftar menggunakan remote infrared, dan LED hijau/merah menyala sebagai umpan balik saat tombol berikut atau sebelumnya ditekan.

## Fitur

- Tampil daftar tim dan pembalap MotoGP pada LCD 16x2 I2C
- Navigasi menggunakan remote infrared
- Tombol `1` untuk maju ke item berikutnya
- Tombol `2` untuk kembali ke item sebelumnya
- LED hijau menyala saat maju, LED merah menyala saat mundur

## Perangkat Keras

- Arduino Uno
- Sensor/receiver IR di pin digital `2`
- LED hijau di pin digital `3`
- LED merah di pin digital `5`
- Modul LCD I2C 16x2 dengan alamat `0x27`
- Remote infrared yang kompatibel dengan library `IRremote`

> Sesuaikan pin LED dan alamat I2C jika konfigurasi hardware berbeda.

## Dependencies

Proyek ini menggunakan PlatformIO dengan library berikut:

- `marcoschwartz/LiquidCrystal_I2C@^1.1.4`
- `z3t0/IRremote@^4.7.1`

## Struktur Proyek

- `platformio.ini` - konfigurasi PlatformIO untuk board Arduino Uno
- `src/main.cpp` - kode utama proyek
- `include/` - folder header tambahan jika diperlukan
- `lib/` - folder library lokal jika diperlukan

## Instalasi dan Penggunaan

1. Buka proyek di PlatformIO.
2. Pastikan file `platformio.ini` sudah berisi lingkungan `uno`:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps =
    marcoschwartz/LiquidCrystal_I2C@^1.1.4
    z3t0/IRremote@^4.7.1
```

3. Sambungkan hardware sesuai pin di `src/main.cpp`.
4. Upload kode ke Arduino.
5. Arahkan remote IR ke receiver dan tekan `1` atau `2`.

## Penjelasan Kode

- `RECV_PIN` = `2` untuk receiver IR
- `LED_HIJAU` = `3` untuk LED maju
- `LED_MERAH` = `5` untuk LED mundur
- `CMD_NEXT` = `0x30` (tombol `1` pada remote)
- `CMD_PREV` = `0x18` (tombol `2` pada remote)

Saat tombol terdeteksi:

- Jika `CMD_NEXT`, indeks bertambah, tampilan LCD diperbarui, dan LED hijau berkedip
- Jika `CMD_PREV`, indeks berkurang, tampilan LCD diperbarui, dan LED merah berkedip

## Catatan

- Pastikan receiver IR mendapatkan daya dan terhubung dengan benar.
- Jika LCD tidak tampil, cek alamat I2C dan kontras kabel.
- Jika tombol remote tidak merespons, pastikan remote kompatibel dengan library `IRremote` dan gunakan tombol yang benar.

## Lisensi

Proyek ini dapat digunakan dan dimodifikasi secara bebas.
