# Showing Live sensor values in Blynk app by Node MCU ESP8266ESP
----------------------------------------------------------------
* <p style='color:green'> You can monitor yours room weather from anywhere of world and also able to control a LED from anywhare.</p>

- [x] Functionaliity: 

This code is for BMP280 sensor data shown in Yours Android BLYNK application.This code has following functionality:
1. Shown temperature in Blynk app over internet.
2. Shown pressure in Blynk app over internet.
3. Shown altitude from sea level(measuring from above air pressure) in blynk app over internet.
4. Green led indicator for eastablished internet connection with esp8266 board.
5. Red LED indicator for lost of internet connection with esp8266 board.
6. Blue led control with blynk control over the internet.
7. It is set a custom name to connect into internet
8. Displaying the uptime of the device in the internet.
9. Send notification into android device for certain selected sensor value range.
10. Send notification into selected mail address for certain selected sensor value ranges.

* Approximate cost - INR 500 to INR 600

- [x] Components : NODE MCU [ESP8266](https://www.amazon.in/Generic-Nodemcu-Esp8266-Internet-Development/dp/B07262H53W/ref=sr_1_2?crid=16Y11YOAA3V5E&dchild=1&keywords=node+mcu+esp8622+wifi+module&qid=1612175224&sprefix=node+mcu+%2Caps%2C1296&sr=8-2) WIFI Board, [BMP280](https://www.amazon.in/Robodo-Pressure-Precision-Arduino-Replace/dp/B07DDJ3MFX/ref=sxts_sxwds-bia-wc-nc-drs1_0?cv_ct_cx=bmp280&dchild=1&keywords=bmp280&pd_rd_i=B07DDJ3MFX&pd_rd_r=19937854-3b3a-4dfb-b9df-4c3f81f110c2&pd_rd_w=yqRu9&pd_rd_wg=jB2AE&pf_rd_p=4856a1b6-75e2-4f99-bb59-edf3db6a4f74&pf_rd_r=3CS7Y0AZKHQX4S7KKHGH&psc=1&qid=1612175284&sr=1-1-606822b7-04c2-4c74-a611-acbe80e94641) Sensor, red [LED](https://www.amazon.in/INDIAS-HEART-Assorted-Electronic-Components/dp/B07RZPYS1G/ref=sr_1_1?dchild=1&keywords=assorted+led&qid=1612175348&sr=8-1), green LED, BLUE LED,3pieces 1K [resistor](https://www.amazon.in/Electrobot-EBRTH02-Value-Resistor-Pack/dp/B0716CR5JL/ref=sr_1_1?dchild=1&keywords=resistor+pack&qid=1612175427&sr=8-1),[jumping wires](https://www.amazon.in/ApTechDeals-Jumper-Female-breadboard-jumper/dp/B074J9CPV3/ref=sr_1_4?crid=ZTXUN3JZF8S0&dchild=1&keywords=jumper+wires&qid=1612175495&sprefix=jumper+%2Caps%2C411&sr=8-4),
                  Data Cable,[Arduino IDE](https://www.arduino.cc/en/Main.Software) in computer or Smart phone.
                  
- [x] Wiring : Connect Blue LED into boards D0 Pin,connect red LED into boards D3 Pin,connect green LED into boards D4 Pin,
              + pin of BMP280 hooked up with 3.3 Volt of board,- pin of BMP280 hooked up with ground pin of esp8266 board.
              SCK or SCL pin of BMP280 hooked up with D1 pin of esp8266 board,SDA pin conncet to D2 pin of board.
              There is no connection for CSB and SD0.Then download Arduino IDE for yours OS and install the [Blynk,Time ,WidgetRTC libraries](https://www.arduino.cc/en/guide/libraries) and
              costract Arduino IDE for uploading code into esp8266.If don't know how do you ready yours Arduino IDE for esp8266 then read [this](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/#:~:text=%20To%20install%20the%20ESP8266%20board%20in%20your,be%20installed%20after%20a%20few%20seconds.%20More).Now upload this code into esp8266 and make a [Blynk](https://blynk.io/) app in android app called Blynk.If  don't know How do you make Blynk app then read [this](https://docs.blynk.cc/#:~:text=%20Getting%20Started%20With%20The%20Blynk%20App%20,hardware%20to%20your%20smartphone.%20Every%20new...%20More) .
              
 * Blynk Application interface :
 
 ![Screenshot of blynk app in android device](blynk_app%5B1%5D.jpg)
