//Yash Jungade
//Designed with the help of official examples of MLX Sensor.
//This is touchless body temprature detector.

#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  mlx.begin();
  Serial.begin(9600);
  Serial.println("Thermal Screener");
  lcd.begin(16,2);
  lcd.print("Thermal Screener");
}
void loop() {
    Serial.print("Temperature : ");Serial.print(mlx.readObjectTempC());Serial.println(" C");
    lcd.print("Thermal Screener");
    delay(1000);
    lcd.clear();
    lcd.print("Temp : ");lcd.print(mlx.readObjectTempC());lcd.print(" C");
    lcd.setCursor(0,1);
    if(mlx.readObjectTempC()<=38){
      lcd.print("Safe");
    }
    else{
      lcd.print("UnSafe");
    }
    delay(5000);
    lcd.clear();
}
