#include "traficlight4Arah.h"

TrafficLight4Arah::TrafficLight4Arah(
  uint8_t m1, uint8_t k1, uint8_t h1,
  uint8_t m2, uint8_t k2, uint8_t h2,
  uint8_t m3, uint8_t k3, uint8_t h3,
  uint8_t m4, uint8_t k4, uint8_t h4
) {
  _lampu[0] = {m1, k1, h1};
  _lampu[1] = {m2, k2, h2};
  _lampu[2] = {m3, k3, h3};
  _lampu[3] = {m4, k4, h4};

  _waktuHijau = 3000;
  _waktuKuning = 1000;
  _jedaAntar = 1000;
}

void TrafficLight4Arah::begin() {
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(_lampu[i].merah, OUTPUT);
    pinMode(_lampu[i].kuning, OUTPUT);
    pinMode(_lampu[i].hijau, OUTPUT);
  }
  setSemuaMerah(); 
}

void TrafficLight4Arah::_setLampu(uint8_t arah, bool merah, bool kuning, bool hijau) {
  digitalWrite(_lampu[arah].merah, merah ? HIGH : LOW);
  digitalWrite(_lampu[arah].kuning, kuning ? HIGH : LOW);
  digitalWrite(_lampu[arah].hijau, hijau ? HIGH : LOW);
}

void TrafficLight4Arah::setSemuaMerah() {
  for (uint8_t i = 0; i < 4; i++) {
    _setLampu(i, true, false, false); 
  }
}

void TrafficLight4Arah::jalankanJalur(uint8_t arah) {
  if (arah > 3) return; 

  _setLampu(arah, false, false, true);
  delay(_waktuHijau);

  _setLampu(arah, false, true, false);
  delay(_waktuKuning);

  _setLampu(arah, true, false, false);
  delay(_jedaAntar);
}

void TrafficLight4Arah::jalankanSiklus() {
  for (uint8_t i = 0; i < 4; i++) {
    jalankanJalur(i);
  }
}

void TrafficLight4Arah::setWaktuHijau(unsigned long ms) { _waktuHijau = ms; }
void TrafficLight4Arah::setWaktuKuning(unsigned long ms) { _waktuKuning = ms; }
void TrafficLight4Arah::setJedaAntar(unsigned long ms) { _jedaAntar = ms; }

unsigned long TrafficLight4Arah::getWaktuHijau() const { return _waktuHijau; }
unsigned long TrafficLight4Arah::getWaktuKuning() const { return _waktuKuning; }
unsigned long TrafficLight4Arah::getJedaAntar() const { return _jedaAntar; }