#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 8
LiquidCrystal lcd(12,11,5,4,3,2);
#define DHTTYPE DNT11
DHT dht(DHTPIN,DHTTYPE);

void setup(){
  float h=dht.readHumidity();
  float t=dht.readTrmperature();
  t=t*9/5+32;
  if(isnan(t)||isnan(h)){
    lcd.setCursor(0.0);
    lcd.print("Failed to read from DHT");
  }else{
    lcd.clear();
    lcd.setCursor(0.0);
    lcd.print("Humidity:)";
    lcd.print(h);
    lcd.print("%)";
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.print("f");
    }
}
