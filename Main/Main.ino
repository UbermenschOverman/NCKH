#include <PMS.h>
#include <Wire.h>

#define PMS_RX 16
#define PMS_TX 17

PMS pms(Serial1);

void setup() {
Serial.begin(9600);
Serial1.begin(9600, SERIAL_8N1, PMS_RX, PMS_TX);
}

void loop() {
PMS::DATA data;
if (pms.read(data)) {
Serial.print("PM2.5: ");
Serial.print(data.PM_SP_UG_2_5);
Serial.println(" ug/m3");
}
delay(100);
}
