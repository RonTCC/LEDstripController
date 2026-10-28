#include <Arduino.h>
#include <EEPROM.h>
#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Globals.h>

String strVersion = "2026Nov28";

const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;


//Global variables
byte byteFadeOnOff = 0;  //0=No Fade, 1=Fade
int intPattern = 0;
int intNumberOfPatterns = 9;
int intCurrentColor = 0;  //0=Black, 1= White, 2=Red, 3=Green, 4=Blue, 5=Orange
String strPatternDescription;
byte byteStartOver = 0;

int intFadePerStep = 5;                  // brightness change per step (1-255)
int intStepInterval = 30;   // ms between steps
int intRedPinTargetValue = 255; 
int intGreenPinTargetValue = 255;
int intBluePinTargetValue = 255;
int intRedPinCurrentValue; 
int intGreenPinCurrentValue;
int intBluePinCurrentValue;

//For Display
MCUFRIEND_kbv tft;  //MEGA
int intTouchZ;
int intTouchX;
int intTouchY; 
//const int XP = 8, YP = A3, XM = A2, YM = 9; //ID=0x9341  A1=Digital pin 55 on MEGA, A2=Digital pin 56 on MEGA, A3=Digital pin 57 on MEGA, A4=Digital pin 58 on MEGA
#define MINPRESSURE 200
#define MAXPRESSURE 1000



void setup() {
  //****SERIAL COMMUNICATION SETUP******************************************
  // Open serial communications and wait for port to open:
  Serial.begin(115200);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(redPin, intRedPinTargetValue);
  analogWrite(greenPin, intGreenPinTargetValue);
  analogWrite(bluePin, intBluePinTargetValue);
  intRedPinCurrentValue = intRedPinTargetValue;
  intBluePinCurrentValue = intBluePinTargetValue;
  intGreenPinCurrentValue = intGreenPinCurrentValue;

    //For TFT
      tft.reset();
      uint16_t identifier = tft.readID();
      if (identifier == 0x9325) {
          identifier = 0x9325;
      } else if (identifier == 0x9328) {
          identifier = 0x9328;
      } else if (identifier == 0x4535) {
          identifier = 0x4535;
      } else if (identifier == 0x7575) {
          identifier = 0x7575;
      } else if (identifier == 0x9341) {
          identifier = 0x9341;
      } else if (identifier == 0x8357) {
          identifier = 0x8357;
      } else if (identifier == 0x0101) {
          identifier = 0x9325;
      } else if (identifier == 0x1111) {
        identifier = 0x9328;
      }
      else {
        identifier = 0x9486;
      }
      tft.begin(identifier);
      tft.setRotation(1); //Use 1 or 3 for landscape and 2 or 4 for portrait
      delay(200);

      //For touch
        pinMode(13, OUTPUT);
    //End TFT

  //Verify EEPROMs
    if ((EEPROM[0] != 0) & (EEPROM[0] != 1)) {EEPROM[0] = 0;}  //If Fade EEPROM does not have a valid value, set it to 0
    Serial.print("EEPROM[0] (Fade) is set to: "); Serial.println(EEPROM[0]);
    if ((EEPROM[1] > intNumberOfPatterns) || (EEPROM[1] < 1)) {EEPROM[1] = 1;}  //If Pattern EEPROM does not have a valid value, set it to 1
    Serial.print("EEPROM[1] (Pattern) is set to: "); Serial.println(EEPROM[1]);
  //Read pattern and fade from EEPROMs
    byteFadeOnOff = EEPROM[0];
    intPattern = EEPROM[1]; 
}



void loop() {
  Serial.println("New Loop");
  Serial.print("Fade is set to: "); Serial.println(byteFadeOnOff);
  Serial.print("Pattern is set to: "); Serial.println(intPattern);


  switch (intPattern) {
    case 1:
      Serial.println("Constant White pattern.");
      strPatternDescription = "Constant White (1)";
      DisplayWhite();  //White
      break;
    case 2:
      Serial.println("Constant Red pattern.");
      strPatternDescription = "Constant Red (2)";
      DisplayRed();  //Red
      break;
    case 3:
      Serial.println("Constant Green pattern.");
      strPatternDescription = "Constant Green (3)";
      DisplayGreen();  //Green
      break;
    case 4: 
      Serial.println("Constant Blue pattern.");
      strPatternDescription = "Constant Blue (4)";
      DisplayBlue();  //Blue
      break;
    case 5:
      Serial.println("Cycle Red White Blue pattern.");
      strPatternDescription = "Cycle Red White Blue (5)";
      CycleRedWhiteBlue();  //Red White Blue
      break;
    case 6:
      Serial.println("Cycle Red Green pattern.");
      strPatternDescription = "Cycle Red Green (6)";
      CycleRedGreen();  //Red Green
      break;
    case 7:
      Serial.println("Cycle Red Green Blue pattern.");
      strPatternDescription = "Cycle Red Green Blue (7)";
      CyclePrimaryColors();  //Red Green Blue
      break;
    case 8:
      Serial.println("Constant Orange pattern.");
      strPatternDescription = "Constant Orange (8)";
      DisplayOrange();  //Orange
      break;      
    case 9:
      Serial.println("LEDs OFF.");
      strPatternDescription = "LEDs OFF (9)";
      DisplayOFF();  //Off
      break;  
    default:
      Serial.println("Constant White pattern.");
      strPatternDescription = "Constant White (1)";
      DisplayWhite();  //White
      break;
  }

  


}




