#include <Arduino.h>
#include "traficlight4Arah.h"


TrafficLight4Arah simpangTidar(
  2, 3, 4,    
  5, 6, 7,    
  8, 9, 10,   
  11, 12, 13  
);

void setup() {
  Serial.begin(9600);

  simpangTidar.setWaktuHijau(6000);   
  simpangTidar.setWaktuKuning(1500);  
  simpangTidar.setJedaAntar(1000);   

  simpangTidar.begin();
}

void loop() {
  simpangTidar.jalankanSiklus();
}