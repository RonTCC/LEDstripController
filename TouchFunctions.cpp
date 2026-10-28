#include <Arduino.h>
#include <Globals.h>
#include <EEPROM.h>
#include <TouchScreen.h>
#include <Globals.h>

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void DisplayButtons() {
  int intCursorX;
  int intCursorY;

  //Display buttons
  //FADE Button
  tft.fillRect(10, 50, 140, 150, TFT_BLACK);  //FADE button: X1, Y1, X2, Y2
  intCursorX = 50;
  intCursorY = 75;
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(intCursorX, intCursorY);
  tft.println("Turn");
  tft.setCursor(intCursorX, intCursorY + 30);
  tft.println("Fade");
  tft.setCursor(intCursorX, intCursorY + 75);
  tft.setTextSize(4);
  if (EEPROM[0] == 0) {
    tft.print("ON"); }
  else {tft.print("OFF"); }
  

  //PATTERN Button
  tft.fillRect(170, 50, 140, 150, TFT_BLACK);  //PATTERN button: X1, Y1, X2, Y2
  intCursorX = 200;
  intCursorY = 80;
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(intCursorX, intCursorY);
  tft.println("Goto");
  tft.setCursor(intCursorX, intCursorY + 30);
  tft.println("Next");
  tft.setCursor(intCursorX - 22, intCursorY + 60);
  tft.print("Pattern");
}



void GetPoint() {
  //For touch
  //TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
  TSPoint tpoint = ts.getPoint();  //Refreshes the "tpoint" variable with "no touch" values.
  intTouchZ = tpoint.z;
  intTouchX = tpoint.x;
  intTouchY = tpoint.y; 
  //int XP, XM, YP, YM;
  //TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
  //TSPoint tpoint;
  digitalWrite(13, HIGH);
  int intGetPointLoopCounter = 0;
    //Loop for a while to get touch (if any)
    // 10,000 loops equates to about 6 seconds and 30,000 is about 30 seconds
  while (intGetPointLoopCounter < 6000 && tpoint.z < MINPRESSURE) {  //This also sets approx delay between sensor readings.  30,000 ends up being about 25 seconds
      tpoint = ts.getPoint();
      intGetPointLoopCounter = intGetPointLoopCounter + 1;
  }
  intTouchZ = tpoint.z;
  intTouchX = tpoint.x;
  intTouchY = tpoint.y;  
  pinMode(XM, OUTPUT);  //This is necessary because the TouchScreen library leaves the analog pins in INPUT mode after you call getPoint() method.  If you add the pinMode() lines after every getPoint() call, the TFT LCD will be happy. e.g.
  pinMode(YP, OUTPUT);
  digitalWrite(XM, HIGH);
  digitalWrite(YP, HIGH);

  Serial.print(F("Exiting GetPoint() Y, X, Z values = ")); Serial.print(intTouchX); Serial.print(F(", ")); Serial.print(intTouchY); Serial.print(F(", ")); Serial.println(intTouchZ);
  digitalWrite(13, LOW);
}