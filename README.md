# TrafficLight4Arah Library 🚦

**TrafficLight4Arah** adalah *library* C++ berbasis *Object-Oriented Programming* (OOP) yang dirancang khusus untuk mempermudah pengendalian sistem Lampu Lalu Lintas 4 Arah (Simpang Empat) pada mikrokontroler (Arduino, ESP32, dll).

Dirancang dengan fokus pada efisiensi memori dan fleksibilitas, *library* ini memisahkan logika dasar pergantian lampu dari pengaturan waktu. Hal ini memungkinkan durasi lampu diatur secara dinamis langsung dari program utama (`main.cpp`).

---

## ✨ Fitur Utama
- **Pendekatan OOP Ringan:** Mengontrol 12 pin output (4 arah x 3 warna) hanya dengan satu inisialisasi objek.
- **Manajemen Memori Optimal:** Menggunakan arsitektur `struct` dan *array* dengan alokasi data 1-byte (`uint8_t`) untuk meminimalisir konsumsi RAM.
- **Waktu Transisi Dinamis:** Durasi lampu Hijau, Kuning, dan Jeda Transisi Merah tidak di-*hardcode* di dalam *library*, melainkan dapat diubah kapan saja.
- **Kontrol Jalur Spesifik:** Memiliki fungsionalitas untuk mengeksekusi siklus berurutan maupun memicu satu arah secara spesifik.

---

## 🔌 Skematik rangkaian
Hubungkan pin LED (melalui resistor) ke pin digital mikrokontroler. Pastikan semua pin *ground* (GND) dari komponen terhubung ke pin GND pada mikrokontroler.

| Arah Simpang | Pin Merah | Pin Kuning | Pin Hijau |
| :--- | :---: | :---: | :---: |
| **Arah 0 (Utara)** | `2` | `3` | `4` |
| **Arah 1 (Timur)** | `5` | `6` | `7` |
| **Arah 2 (Selatan)**| `8` | `9` | `10` |
| **Arah 3 (Barat)** | `11` | `12` | `13` |
*(Catatan: Nomor pin dan definisi arah di atas hanyalah contoh referensi).*

---

## 🚀 Instalasi (PlatformIO)

1. Buka proyek direktori PlatformIO Anda.
2. Masuk ke dalam folder `lib/`.
3. Buat folder baru dengan nama `TrafficLight4Arah`.
4. Masukkan file `trafficlight4Arah.h` dan `trafficlight4Arah.cpp` ke dalam folder tersebut.
5. Tambahkan `#include "trafficlight4Arah.h"` pada file program utama (`main.cpp`).

---

## 💻 Contoh Penggunaan 

```cpp
#include <Arduino.h>
#include "trafficlight4Arah.h"

// Inisialisasi Objek: Urutan pin (M1,K1,H1, M2,K2,H2, M3,K3,H3, M4,K4,H4)
TrafficLight4Arah simpang(2,3,4, 5,6,7, 8,9,10, 11,12,13);

void setup() {
  // 1. Atur durasi lampu dalam satuan milidetik (ms)
  simpang.setWaktuHijau(6000);   // 6 detik
  simpang.setWaktuKuning(1500);  // 1.5 detik
  simpang.setJedaAntar(1000);    // Jeda semua merah 1 detik sebelum pindah

  // 2. Wajib dipanggil untuk inisialisasi pin sebagai OUTPUT
  simpang.begin();
}

void loop() {
  // Menjalankan rotasi normal simpang 4 secara terus-menerus
  simpang.jalankanSiklus();
}
```
*** Dikembangkan oleh Kelompok Gaul