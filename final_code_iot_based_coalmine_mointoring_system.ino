#define BLYNK_TEMPLATE_ID "TMPL3OzhnsMrz"
#define BLYNK_TEMPLATE_NAME "COAL MINE MOINTERING SYSTEM"
#define BLYNK_AUTH_TOKEN "3r5ggvbF0odvP9iJPp4edSb4jd7e_pF4"

#define BLYNK_PRINT Serial
#include <WiFi.h>
//#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>


char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "MY HOME";  // type your wifi name
char pass[] = "EDUCATION*";  // type your wifi password

BlynkTimer timer;

#define MQ2 35 // connect MQ2 sensor to ESP32 ADC pin 14
int LED = 13; 
int buzzer= 23  ;
#define DHTPIN 27 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11 
 #define LCD_COLS 16       // Number of columns in LCD
#define LCD_ROWS 2        // Number of rows in LCD
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS); // Initialize I2C LCD


void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  float mq2_value = analogRead(MQ2);

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V1, t);
    Blynk.virtualWrite(V2, h);
    Blynk.virtualWrite(V3, mq2_value);
    Serial.print("smoke  :");
    Serial.print(mq2_value);
    if(mq2_value > 700)     // Change the Trashold value
  { digitalWrite (LED, HIGH) ; /*LED set HIGH if Gas detected */
    digitalWrite (buzzer, HIGH);
    delay(1000);
    digitalWrite (buzzer, LOW);

    //Blynk.logEvent("test@gmail.com", "gas sensor", "Gas Detected!");
    Blynk.logEvent("gas_sensor");
  }
    Serial.print("    Temperature : ");
    Serial.print( t);
    Serial.print("    Humidity : ");
    Serial.println(h);
    lcd.clear();                               // Clear LCD display
    lcd.setCursor(0, 0);                       // Set cursor to first column of first row
    lcd.print("Temp: ");                        // Print "Temp: " on LCD
    lcd.print(t);                    // Print temperature value on LCD
    lcd.print(" C");                            // Print " C" on LCD
    lcd.setCursor(0, 1);                       // Set cursor to first column of second row
    lcd.print("Humidity: ");                    // Print "Humidity: " on LCD
    lcd.print(h);                       // Print humidity value on LCD
    lcd.print(" %"); 

  
}
void setup()
{   
  
  Serial.begin(115200);
  
  pinMode(MQ2, INPUT);
  pinMode(LED, OUTPUT);  /*LED set as Output*/
  pinMode(buzzer, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  lcd.begin();    // Initialize I2C LCD
  lcd.backlight(); // Turn on LCD backlight
  timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }