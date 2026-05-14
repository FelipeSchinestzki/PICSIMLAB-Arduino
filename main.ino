#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_HX711.h>

#include "NTC.h"
#include "Encoder.h"
#include "HC_SR04.h"

// ===== LCDs =====
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);
LiquidCrystal_I2C lcd3(0x25, 16, 2);



// ===== Pinos =====
#define DT 3
#define SCK 2
#define TRIG 9
#define ECHO 10
#define NTCpin A0
#define ENC_A 4
#define ENC_B 5

// ===== Sensores =====
Adafruit_BMP085 bmp;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
Adafruit_HX711 hx711(DT, SCK);

// ===== HX711 =====
long RAW_zero = 463392;
float ganhoHX = 0.0004386;



// ===== Setup =====
void setup() {
  Wire.begin();

  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();
  lcd3.init(); lcd3.backlight();


  bmp.begin();
  accel.begin();
  hx711.begin();
  
  HC_SR04_init(TRIG, ECHO);

  encoder_init(ENC_A, ENC_B);
  
}

// ===== Loop =====
void loop() {

  // ===== ADXL345 =====
  sensors_event_t event;
  accel.getEvent(&event);

  float gravityAcceleration = 9.80665;
  
  float accX = event.acceleration.x / gravityAcceleration;
  float accY = event.acceleration.y / gravityAcceleration;
  float accZ = event.acceleration.z / gravityAcceleration;

  // ===== BMP180 =====
  float temp = bmp.readTemperature();
  float pressao = bmp.readPressure() / 100.0; // hPa

  // ===== NTC =====
  const float R_FIXED = 10000.0;   // 10k resistor
  const float R0 = 10000.0;        // NTC 10k @25C
  const float BETA = 3600.0;
  const float T0 = 298.15;         // 25C in Kelvin
  float ntcTemp = NTC(NTCpin,BETA, R0, R_FIXED, T0, 5);
  
  

  // ===== Distância =====
  float distancia = HC_SR04(TRIG, ECHO);

  // ===== HX711 =====
  long raw = hx711.readChannelBlocking(CHAN_B_GAIN_32);
  float peso = (raw - RAW_zero) * ganhoHX;

  // ===== Encoder =====
  long encoderPos = encoder(ENC_A,ENC_B);

  // ===== LCD 1 =====
  lcd1.clear();
  
  lcd1.setCursor(0,0);
  lcd1.print(accX,2);
  lcd1.print(" ");
  lcd1.print(accY,2);
  lcd1.print(" ");
  lcd1.print(accZ,2);
  lcd1.print("   ");

  lcd1.setCursor(0,1);
  lcd1.print("T:");
  lcd1.print(temp,1);
  lcd1.print(" P:");
  lcd1.print(pressao,0);
  lcd1.print("   ");

  // ===== LCD 2 =====
  lcd2.clear();
  
  lcd2.setCursor(0,0);
  lcd2.print("NTC:");
  lcd2.print(ntcTemp,1);
  lcd2.print("C  ");

  lcd2.setCursor(0,1);
  lcd2.print("Dist:");
  lcd2.print(distancia,1);
  lcd2.print("cm ");

  // ===== LCD 3 =====
  lcd3.clear();
  
  lcd3.setCursor(0,0);
  lcd3.print("Peso:");
  lcd3.print(peso,1);
  lcd3.print("kg ");

  lcd3.setCursor(0,1);
  lcd3.print("Enc:");
  lcd3.print(encoderPos);
  lcd3.print("   ");

  delay(500);
}
