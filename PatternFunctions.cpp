#include <Arduino.h>
#include <Globals.h>
#include <TouchScreen.h>
#include <Globals.h>
#include <EEPROM.h>



void DisplayWhite() {
  // White
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 1;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 255;
  intBluePinTargetValue = 255;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 1 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void DisplayRed() {
  // Red
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 2;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 2 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void DisplayGreen() {
  // Green
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 3;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 255;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 3 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void DisplayBlue() {
  // Blue
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 4;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 255;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 4 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void DisplayOrange() {
  // Orange
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 5;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 165;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 8 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void DisplayOFF() {
  // LEDs OFF
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 0;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 9 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void CycleRedWhiteBlue() {  //Delay between colors is determined inside the GetPoint function
  // Red
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 2;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 5 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();

  // White
  byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 1;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 255;
  intBluePinTargetValue = 255;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 5 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();

  // Blue
  byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 4;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 255;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 5 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void CycleRedGreen() {  //Delay between colors is determined inside the GetPoint function
  // Red
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 2;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 6 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();

  // Green
  byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 3;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 255;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 6 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void CyclePrimaryColors() {  //Delay between colors is determined inside the GetPoint function
  // Red
  byte byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 2;
  intRedPinTargetValue = 255;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 7 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();

  // Green
  byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 3;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 255;
  intBluePinTargetValue = 0;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 7 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();

  // Blue
  byteCurrentFade = byteFadeOnOff;
  intCurrentColor = 4;
  intRedPinTargetValue = 0;
  intGreenPinTargetValue = 0;
  intBluePinTargetValue = 255;
  UpdateDisplay(intCurrentColor);
  GetPoint();  //Determine if FADE or PATTERN needs to change
  ToggleFade();  //Determine if FADE needs to be toggled
  TogglePattern();  //Determine if PATTERN needs to be toggled
  if (intPattern != 7 || byteCurrentFade != byteFadeOnOff) {return;}  //If either FADE or PATTERN has changed, avoid delay experienced when fading LEDs
  UpdateLEDs();
}


void UpdateDisplay(int BackgroundColor) {
  //Write Fade and Pattern to display
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.setTextColor(TFT_BLACK);
    switch (BackgroundColor)
    {
    case 0:  //Black
      tft.fillScreen(TFT_BLACK);
      tft.setTextColor(TFT_WHITE);
      tft.print(strPatternDescription);
      break;
    case 1:  //White
      tft.fillScreen(TFT_WHITE);
      tft.print(strPatternDescription);
      break;
    case 2:  //Red
      tft.fillScreen(TFT_RED);
      tft.print(strPatternDescription);
      break;
    case 3:  //Green
      tft.fillScreen(TFT_GREEN);
      tft.print(strPatternDescription);
      break;
    case 4:  //Blue
      tft.fillScreen(TFT_BLUE);
      tft.print(strPatternDescription);
      break;
    case 5:  //Orange
      tft.fillScreen(TFT_ORANGE);
      tft.print(strPatternDescription);
      break;
    default:
      tft.fillScreen(TFT_BLACK);
      tft.print(strPatternDescription);
      break;
    }
    DisplayButtons();
    tft.setTextColor(TFT_BLACK);
    if (BackgroundColor == 0) {tft.setTextColor(TFT_WHITE);}
    tft.setTextSize(2);
    tft.setCursor(10, 215);
    tft.print("Version: "); tft.print(strVersion);
}


void UpdateLEDs() {
  intFadePerStep = 255;     // brightness change per step (1-255):  The higher the number, the faster the change.
  intStepInterval = 0;   // ms between steps
  if (byteFadeOnOff) {
    intFadePerStep = 1;
    intStepInterval = 10;
  }

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(0, 115);
  tft.println(" One moment please.");
  tft.print(" Updating the LED strip.");

  for (int i = 0; i < ((255 / intFadePerStep) + 1); i++) {
    //Update Red
    if (intRedPinTargetValue == intRedPinCurrentValue) {
      //do nothing
      Serial.print("RED pin already at target value: "); Serial.println(intRedPinTargetValue);
    }
    else if (intRedPinTargetValue >= intRedPinCurrentValue) {  //Increase RED
      intRedPinCurrentValue = intRedPinCurrentValue + intFadePerStep;
      if (intRedPinCurrentValue > 255) {intRedPinCurrentValue = 255;}
      analogWrite(redPin, intRedPinCurrentValue);
      Serial.print("RED pin set to: "); Serial.println(intRedPinCurrentValue);
    }
    else {  //Reduce RED
      intRedPinCurrentValue = intRedPinCurrentValue - intFadePerStep;
      if (intRedPinCurrentValue < 0) {intRedPinCurrentValue = 0;}
      analogWrite(redPin, intRedPinCurrentValue);
      Serial.print("RED pin set to: "); Serial.println(intRedPinCurrentValue);
    }
    //Update Green
    if (intGreenPinTargetValue == intGreenPinCurrentValue) {
      //do nothing
      Serial.print("GREEN pin already at target value: "); Serial.println(intGreenPinTargetValue);
    }
    else if (intGreenPinTargetValue >= intGreenPinCurrentValue) {  //Increase GREEN
      intGreenPinCurrentValue = intGreenPinCurrentValue + intFadePerStep;
      if (intGreenPinCurrentValue > 255) {intGreenPinCurrentValue = 255;}
      analogWrite(greenPin, intGreenPinCurrentValue);
      Serial.print("GREEN pin set to: "); Serial.println(intGreenPinCurrentValue);
    }
    else {  //Reduce GREEN
      intGreenPinCurrentValue = intGreenPinCurrentValue - intFadePerStep;
      if (intGreenPinCurrentValue < 0) {intGreenPinCurrentValue = 0;}
      analogWrite(greenPin, intGreenPinCurrentValue);
      Serial.print("GREEN pin set to: "); Serial.println(intGreenPinCurrentValue);
    }
    //Update Blue
    if (intBluePinTargetValue == intBluePinCurrentValue) {
      //do nothing
      Serial.print("BLUE pin already at target value: "); Serial.println(intBluePinTargetValue);
    }
    else if (intBluePinTargetValue >= intBluePinCurrentValue) {  //Increase BLUE
      intBluePinCurrentValue = intBluePinCurrentValue + intFadePerStep;
      if (intBluePinCurrentValue > 255) {intBluePinCurrentValue = 255;}
      analogWrite(bluePin, intBluePinCurrentValue);
      Serial.print("BLUE pin set to: "); Serial.println(intBluePinCurrentValue);
    }
    else {  //Reduce BLUE
      intBluePinCurrentValue = intBluePinCurrentValue - intFadePerStep;
      if (intBluePinCurrentValue < 0) {intBluePinCurrentValue = 0;}
      analogWrite(bluePin, intBluePinCurrentValue);
      Serial.print("BLUE pin set to: "); Serial.println(intBluePinCurrentValue);
    }
    delay(intStepInterval);
  }
}


void ToggleFade() {
  if ((intTouchZ > MINPRESSURE) && (intTouchY > 150) && (intTouchY < 425) && (intTouchX > 350)  & (intTouchX < 700)) {
    Serial.println("Toggle FADE touched.");
    if (byteFadeOnOff == 0) { 
      byteFadeOnOff = 1;
      EEPROM[0] = 1;
      //return;
    }
    else {
      byteFadeOnOff = 0;
      EEPROM[0] = 0;
      //return;
    }
  }
}


void TogglePattern() {
  if ((intTouchZ > MINPRESSURE) && (intTouchX > 350) && (intTouchX < 7000) && (intTouchY > 580)  & (intTouchY < 850)) {
    Serial.println("Toggle PATTERN touched.");
    switch (intPattern)
    {
    case 1:
      intPattern = 2;
      EEPROM[1] = 2;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant Red (2)";
      break;
    case 2:
      intPattern = 3;
      EEPROM[1] = 3;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant Green (3)";
      break;
    case 3:
      intPattern = 4;
      EEPROM[1] = 4;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant Blue (4)";
      break;
    case 4: 
      intPattern = 5;
      EEPROM[1] = 5;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Cycle Red White Blue (5)";
      break;
    case 5:
      intPattern = 6;
      EEPROM[1] = 6;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Cycle Red Green (6)";
      break;
    case 6:
      intPattern = 7;
      EEPROM[1] = 7;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Cycle Red Green Blue (7)";
      break;
    case 7:
      intPattern = 8;
      EEPROM[1] = 8;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant Orange (8)";
      break;
    case 8:
      intPattern = 9;  //LEDs OFF
      EEPROM[1] = 9;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "LEDs OFF (9)";
      break;
    case 9:
      intPattern = 1;  //start over
      EEPROM[1] = 1;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant White (1)";
      break;
    default:
      intPattern = 1;
      EEPROM[1] = 1;
      Serial.print("Pattern set to: "); Serial.println(intPattern);
      strPatternDescription = "Constant White (1)";
      break;
    }
  }
}