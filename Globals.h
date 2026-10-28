#pragma once                 // prevents multiple inclusions during compilation
#include <Arduino.h>
#include <MCUFRIEND_kbv.h>  //MEGA
#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Globals.h>

extern String strVersion;

extern const int redPin;
extern const int greenPin;
extern const int bluePin;


//For Display
extern MCUFRIEND_kbv tft;  //MEGA

extern byte byteFadeOnOff;  //0=No Fade, 1=Fade
extern int intPattern;
extern String strPatternDescription;
extern int intNumberOfPatterns;
extern int intCurrentColor;
extern byte byteStartOver;

extern int intFadePerStep;                 // brightness change per step (1-255)
extern int intStepInterval;   // ms between steps
extern int intRedPinTargetValue; 
extern int intGreenPinTargetValue;
extern int intBluePinTargetValue;
extern int intRedPinCurrentValue; 
extern int intGreenPinCurrentValue;
extern int intBluePinCurrentValue;

extern int intTouchZ;
extern int intTouchX;
extern int intTouchY; 
const int XP = 8, YP = A3, XM = A2, YM = 9; //ID=0x9341  A1=Digital pin 55 on MEGA, A2=Digital pin 56 on MEGA, A3=Digital pin 57 on MEGA, A4=Digital pin 58 on MEGA
#define MINPRESSURE 200
#define MAXPRESSURE 1000


//Global Functions
void CyclePrimaryColors();
void DisplayWhite();
void DisplayRed();
void DisplayGreen();
void DisplayBlue();
void DisplayOrange();
void CycleRedWhiteBlue();
void CycleRedGreen();
void UpdateDisplay(int BackgroundColor);
void UpdateLEDs();
void DisplayButtons();
void GetPoint();
void ToggleFade();
void TogglePattern();
