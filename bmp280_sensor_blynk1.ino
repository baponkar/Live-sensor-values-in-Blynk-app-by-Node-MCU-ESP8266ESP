/***************************************************************************
  This code is for BMP280 sensor data shown in Yours Android BLYNK application.This code has following functionality:
  1.Shown temperature in Blynk app over internet.
  2.Shown pressure in Blynk app over internet.
  3.Shown altitude from sea level(measuring from above air pressure) in blynk app over internet.
  4.Green led indicator for eastablished internet connection with esp8266 board.
  5. Red LED indicator for lost of internet connection with esp8266 board.
  6. Blue led control with blynk control over the internet.
  7.It is set a custom name to connect into internet
  8. Displaying the uptime of the device in the internet.
  9. Send notification into the android device for certain selected sensor values.
  10. Send notification into the selected email address for certain selected sensor values.
  Components : NODE MCU ESP8266 WIFI Board, BMP280 Sensor, red LED, green LED, BLUE LED,3pieces 1K resistor,jumping wires,
               Data Cable,Arduino IDE in computer or Smart phone.
  Libraries: AdafruitBMP280,Blynk,WidgetRTC,TimeLib,ESP8266 

  Wiring : Connect Blue LED into boards D0 Pin,connect red LED into boards D3 Pin,connect green LED into boards D4 Pin,
           + pin of BMP280 hooked up with 3.3 Volt of board,- pin of BMP280 hooked up with ground pin of esp8266 board.
           SCK or SCL pin of BMP280 hooked up with D1 pin of esp8266 board,SDA pin conncet to D2 pin of board.
           There is no connection for CSB and SD0.Then download Arduino IDE for yours OS and install the Blynk,Time ,WidgetRTC libraries and
           costract Arduino IDE for uploading code into esp8266.Now upload this code into esp8266 and make a Blynk app in android app called Blynk. 
  License : GNU v3.0
  Writer : Bapon Kar
  Date of Building : 01/02/2021
  Last updaate : 01/02/2021
  Contact : https://www.github.com/baponkar
 *****************************************************************************************************************************************************/


#define BLYNK_PRINT Serial
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_BMP280.h>
#include <TimeLib.h>
#include <WidgetRTC.h>

Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " 9PjpcgGHMNtFJKh-DIDZ2daetvas8qG-8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "PASSWORD";

BlynkTimer timer;
WidgetRTC rtc;

#define redLedPin 0// D3
#define greenLedPin 2// D4

void clockDisplay()
{
  String upTime = String(hour()) + " : " + minute() + " : " + second();
  String uptoDate = String(day()-1) + " : " + String(month()-1) + " : " + String(year()-1970);
  Serial.print("Up Time: ");
  Serial.print(" ");
  Serial.print(upTime);
  Serial.println();
  Serial.print("up to date Date:");
  Serial.print(" ");
  Serial.print(uptoDate);
  Serial.println();

  Blynk.virtualWrite(V8,upTime); //writing into virtual pin 8
  Blynk.virtualWrite(V9,uptoDate); //writing into virtual pin 9


}

BLYNK_CONNECTED(){
    rtc.begin();
  }


void mySensorEvent()
{
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  float  temp = temp_event.temperature;
  float pressure = pressure_event.pressure;
  float altitude = pressure/(13.6*9.80);
  
  Blynk.virtualWrite(V5,temp);
  Blynk.virtualWrite(V6,pressure);
  Blynk.virtualWrite(V7,altitude);

  if ( temp < 12)
  {
    Blynk.notify("It is a Extream Winter!");
    Blynk.email("Baponkar600@gmail.com","ESP8266 Sensor alert!","It is a Extream Winter!");
  }
  else if ( temp > 40)
  {
    Blynk.notify("It is a Extream hot!");
     Blynk.email("Baponkar@gmail.com","ESP8266 Sensor alert!","It is a Extream hot!");
  }
  
}


void setup() {

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println(F("BMP280 Sensor event test"));

  
  WiFi.hostname("BMP280 Device"); //setting custom device name
  
  Blynk.begin(auth, ssid, pass);
  
  timer.setInterval(1000L,mySensorEvent);
  timer.setInterval(1000L,clockDisplay);


  if (!bmp.begin(0x76)) {  //0x76 is the i2c address of esp8266 device .You can get this address by uploading i2c scanner program into esp8266.
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  bmp_temp->printSensorDetails();
}

void loop() {
  
  Blynk.run();
  timer.run();
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);

  if (Blynk.connected()){
    digitalWrite(greenLedPin,HIGH); //if board eastablish a internet connection
    digitalWrite(redLedPin,LOW);
    Serial.println("Have a valid internet connection");
  }
  else {
    digitalWrite(redLedPin,HIGH);  //if board lost internet connection
    digitalWrite(greenLedPin,LOW);
    Serial.println("Sorry! Have not a valid internet connection");
  }

  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure/(13.6*9.81));
  Serial.println(" m");
  
  Serial.println();
  delay(2000);
}
