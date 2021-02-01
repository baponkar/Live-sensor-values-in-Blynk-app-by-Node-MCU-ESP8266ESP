# Live sensor values in Blynk app by Node MCU ESP8266ESP
-----------------------------------------------------------

 This code is for BMP280 sensor data shown in Yours Android BLYNK application.This code has following functionality:
1. Shown temperature in Blynk app over internet.
2.Shown pressure in Blynk app over internet.
3.Shown altitude from sea level(measuring from above air pressure) in blynk app over internet.
4.Green led indicator for eastablished internet connection with esp8266 board.
5. Red LED indicator for lost of internet connection with esp8266 board.
6. Blue led control with blynk control over the internet.
7.It is set a custom name to connect into internet
8. Displaying the uptime of the device in the internet.
Components : NODE MCU ESP8266 WIFI Board, BMP280 Sensor, red LED, green LED, BLUE LED,3pieces 1K resistor,jumping wires,
               Data Cable,Arduino IDE in computer or Smart phone.
Wiring : Connect Blue LED into boards D0 Pin,connect red LED into boards D3 Pin,connect green LED into boards D4 Pin,
         + pin of BMP280 hooked up with 3.3 Volt of board,- pin of BMP280 hooked up with ground pin of esp8266 board.
         SCK or SCL pin of BMP280 hooked up with D1 pin of esp8266 board,SDA pin conncet to D2 pin of board.
         There is no connection for CSB and SD0.Then download Arduino IDE for yours OS and install the Blynk,Time ,WidgetRTC libraries and
         costract Arduino IDE for uploading code into esp8266.Now upload this code into esp8266 and make a Blynk app in android app called Blynk.
