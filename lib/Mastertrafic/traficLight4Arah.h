#ifndef TRAFFICLIGHT4ARAH_H
#define TRAFFICLIGHT4ARAH_H
#include <Arduino.h>

struct PinLampu {
  uint8_t merah;
  uint8_t kuning;
  uint8_t hijau;
};

class TrafficLight4Arah {
  public:
    TrafficLight4Arah(
      uint8_t m1, uint8_t k1, uint8_t h1, // Arah 0 (misal: Utara)
      uint8_t m2, uint8_t k2, uint8_t h2, // Arah 1 (misal: Timur)
      uint8_t m3, uint8_t k3, uint8_t h3, // Arah 2 (misal: Selatan)
      uint8_t m4, uint8_t k4, uint8_t h4  // Arah 3 (misal: Barat)
    );

    void begin();
    void jalankanSiklus();
    void jalankanJalur(uint8_t arah);
    void setSemuaMerah();

    void setWaktuHijau(unsigned long ms);
    void setWaktuKuning(unsigned long ms);
    void setJedaAntar(unsigned long ms);

    unsigned long getWaktuHijau() const;
    unsigned long getWaktuKuning() const;
    unsigned long getJedaAntar() const;

  private:
    PinLampu _lampu[4];          
    unsigned long _waktuHijau;  
    unsigned long _waktuKuning;  
    unsigned long _jedaAntar;    

    void _setLampu(uint8_t arah, bool merah, bool kuning, bool hijau);
};

#endif