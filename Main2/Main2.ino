#include <PMS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PMS_RX 16
#define PMS_TX 17

PMS pms(Serial1);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, PMS_RX, PMS_TX);
  lcd.init();
  lcd.backlight();
  lcd.print("PMS7003 Data");
}

void loop() {
  PMS::DATA data;
  if (pms.read(data)) {
    lcd.setCursor(0, 1);
    lcd.print("PM2.5: ");
    lcd.print(data.PM_SP_UG_2_5);
    lcd.print(" ug/m3  ");
  }
  delay(30000);
}
