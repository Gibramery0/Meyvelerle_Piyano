#include <CapacitiveSensor.h>

// Dokunma sensörleri için pin tanımlamaları
CapacitiveSensor sensor1 = CapacitiveSensor(2, 4); // 2-4 arası direnç bağlanacak
CapacitiveSensor sensor2 = CapacitiveSensor(2, 5);
CapacitiveSensor sensor3 = CapacitiveSensor(2, 6);
CapacitiveSensor sensor4 = CapacitiveSensor(2, 7);
CapacitiveSensor sensor5 = CapacitiveSensor(2, 8);
CapacitiveSensor sensor6 = CapacitiveSensor(2, 9);
CapacitiveSensor sensor7 = CapacitiveSensor(2, 10);
CapacitiveSensor sensor8 = CapacitiveSensor(2, 11);
CapacitiveSensor sensor9 = CapacitiveSensor(2, 12);
CapacitiveSensor sensor10 = CapacitiveSensor(2, 13);

const int buzzerPin = 3; // Buzzer bağlanan pin

// Notalar (frekans değerleri)
int notalar[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659};

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (dokunmaAlgılandı(sensor1)) çalNota(0);
  if (dokunmaAlgılandı(sensor2)) çalNota(1);
  if (dokunmaAlgılandı(sensor3)) çalNota(2);
  if (dokunmaAlgılandı(sensor4)) çalNota(3);
  if (dokunmaAlgılandı(sensor5)) çalNota(4);
  if (dokunmaAlgılandı(sensor6)) çalNota(5);
  if (dokunmaAlgılandı(sensor7)) çalNota(6);
  if (dokunmaAlgılandı(sensor8)) çalNota(7);
  if (dokunmaAlgılandı(sensor9)) çalNota(8);
  if (dokunmaAlgılandı(sensor10)) çalNota(9);
}

// Dokunmayı algılayan fonksiyon
bool dokunmaAlgılandı(CapacitiveSensor &sensor) {
  long değer = sensor.capacitiveSensor(30); // Ölçüm yap
  Serial.println(değer); // Seri monitörde değeri gör
  return değer > 1000; // 1000 değerinden büyükse dokunma var
}

// Nota çalma fonksiyonu
void çalNota(int notaIndex) {
  tone(buzzerPin, notalar[notaIndex], 500); // 500ms süreyle çal
  delay(500); // Çalma süresi kadar bekle
  noTone(buzzerPin); // Buzzer'ı kapat
}
