#include <DHT.h>
#include <LiquidCrystal.h>

// Define the DHT pin and type
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LCD pins: (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 8);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("Reading DHT11...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor error!");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print(" %");

  delay(2000); // update every 2 seconds
}
