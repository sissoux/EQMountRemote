#pragma once

#define Ser SERIAL_INTERFACE
#define __ARM_Teensy3_4__

// Check for Teensy 3.2 or Teensy4.0 or ESP32
#if defined(__MK20DX256__) || defined(__IMXRT1052__) || defined(__IMXRT1062__)
  #define __ARM_Teensy3_4__
#elif !defined(ESP32)
  #error "Unsupported processor!  Use ESP32, Teensy3.2, or Teensy4.0"
#endif

// Default pin state; true for active LOW, false if active HIGH
#define B_PIN_UP_0 true
#define B_PIN_UP_1 true
#define B_PIN_UP_2 true
#define B_PIN_UP_3 true
#define B_PIN_UP_4 true
#define B_PIN_UP_5 true
#define B_PIN_UP_6 true

// The hand controller buttons, etc.
#ifdef  __ARM_Teensy3_4__
  #ifdef __GENERIC__
    #define B_PIN0 21   // Shift
    #define B_PIN1 15   // N
    #define B_PIN2 16   // S
    #define B_PIN3 17   // E
    #define B_PIN4 20   // W
    #define B_PIN5 22   // F
    #define B_PIN6 23   // f

    #define ST4RAw 2    // ST4 (OnStep) RA- West,  send data to OnStep
    #define ST4DEs 3    // ST4 (OnStep) DE- South, clock input to ISR
    #define ST4DEn 4    // ST4 (OnStep) DE+ North, recv data from OnStep
    #define ST4RAe 5    // ST4 (OnStep) RA+ East,  always 25 Hz square wave on this pin

    #if ST4_INTERFACE == ON
      #define ST4AuxRAw 6 // ST4 (Aux) RA- West
      #define ST4AuxDEs 7 // ST4 (Aux) DE- South
      #define ST4AuxDEn 8 // ST4 (Aux) DE+ North
      #define ST4AuxRAe 9 // ST4 (Aux) RA+ East
    #endif

    #define UTILITY_LIGHT_PIN  10    // Pin10 used as PWM output to drive utility lamp LED

    #define DISPLAY_RESET_PIN  14    // Pin14 used to reset some displays, i.e. the SSD1309
  #endif

  #ifdef __MYBOARD__
    #define B_PIN0 3   // Shift
    #define B_PIN1 4   // N
    #define B_PIN2 2   // S
    #define B_PIN3 1   // E
    #define B_PIN4 5   // W
    #define B_PIN5 6   // F
    #define B_PIN6 0   // f

    #define ST4RAw 12    // ST4 (OnStep) RA- West,  send data to OnStep
    #define ST4DEs 13    // ST4 (OnStep) DE- South, clock input to ISR
    #define ST4DEn 11    // ST4 (OnStep) DE+ North, recv data from OnStep
    #define ST4RAe 10    // ST4 (OnStep) RA+ East,  always 25 Hz square wave on this pin

    #define UTILITY_LIGHT_PIN  9    // Pin10 used as PWM output to drive utility lamp LED

    #define DISPLAY_RESET_PIN  14    // Pin14 used to reset some displays, i.e. the SSD1309
  #endif

#endif

#ifdef ESP32
  // workaround for ESP32 crashing on EEPROM commit
  #define DISABLE_EEPROM_COMMIT_ON

  #define B_PIN0 33   // Shift
  #define B_PIN1 25   // N
  #define B_PIN2 32   // S
  #define B_PIN3 36   // E
  #define B_PIN4 34   // W
  #define B_PIN5 39   // F
  #define B_PIN6 35   // f

  #define ST4RAw 23   // ST4 (OnStep) RA- West,  send data to OnStep
  #define ST4DEs 14   // ST4 (OnStep) DE- South, clock input to ISR
  #define ST4DEn 27   // ST4 (OnStep) DE+ North, recv data from OnStep
  #define ST4RAe 26   // ST4 (OnStep) RA+ East,  always 12.5 Hz square wave on this pin

  #if ST4_INTERFACE == ON
    #define ST4AuxRAw 19 // ST4 (Aux) RA- West
    #define ST4AuxDEs 18 // ST4 (Aux) DE- South
    #define ST4AuxDEn 17 // ST4 (Aux) DE+ North
    #define ST4AuxRAe 5  // ST4 (Aux) RA+ East
  #endif

  #define UTILITY_LIGHT_PIN  13    // GPIO13 used as PWM output to drive utility lamp LED

  #define DISPLAY_RESET_PIN  16    // GPIO16 used to reset some displays, i.e. the SSD1309
#endif

#include "St4SerialSlave.h"
#include "St4Aux.h"
