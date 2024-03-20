#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     4
int tourSwipe = 0;
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
Servo FINGERBOT_TOP;//create servo object to control a servo
Servo FINGERBOT_BOTTOM;


void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay();//cls

  FINGERBOT_TOP.attach(6);//attachs the servo on pin 9 to servo object
  FINGERBOT_BOTTOM.attach(9);

  FINGERBOT_TOP.write(0);//back to 0 degrees
  FINGERBOT_BOTTOM.write(0);


}
void loop()
{
  FINGERBOT_TOP.write(0); // Déplace FINGERBOT_TOP à 90 degrés
  delay(500); // Attend 1 seconde
  FINGERBOT_TOP.write(0); // Retourne FINGERBOT_TOP à 0 degrés
  delay(500); // Attend 1 seconde
  
  tourSwipe++;

  display.clearDisplay();//cls
  //  //Set the font size
  display.setTextSize(1);
  //  //Set the display location
  display.setCursor(0, 0);
  //  //String displayed
  display.print("Nb views :");
  display.setTextSize(2);
  display.setCursor(0, 40);
  display.print(tourSwipe);
  //  //Began to show
  display.display();

  FINGERBOT_TOP.write(30); // Déplace FINGERBOT_TOP à 90 degrés
  delay(1000); // Attend 1 seconde
  FINGERBOT_TOP.write(0); // Retourne FINGERBOT_TOP à 0 degrés
  delay(1000); // Attend 1 seconde

  FINGERBOT_BOTTOM.write(30); // Déplace FINGERBOT_BOTTOM à 90 degrés
  delay(1000); // Attend 1 seconde
  FINGERBOT_BOTTOM.write(0); // Retourne FINGERBOT_BOTTOM à 0 degrés
  delay(1000); // Attend 1 seconde
  

}
