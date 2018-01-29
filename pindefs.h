////////////////////////////////////////////////////////////////////////////////
// misc pindefs
////////////////////////////////////////////////////////////////////////////////

#ifndef pindefs_h
  #define pindefs_h

  //these are the ST7920 128x64 pin assignments on the RAMPS 1.4 board
  #define LCD_CLOCK 23
  #define LCD_DATA  17
  #define LCD_CS    16

  //beeper
  #define BEEP  37

  //stop
  #define STOP  41

  //knob
  #define BTN_EN1 33
  #define BTN_EN2 31
  #define BTN_ENC 35

  //stepper pins

  //called X -- my C1
  #define C1_ENABLE 38
  #define C1_STEP   A0
  #define C1_DIR    A1
  #define C1_INDEX  D3 //X-min endstop

  //called Y -- my L1
  #define L1_ENABLE A2
  #define L1_STEP   A6
  #define L1_DIR    A7
  #define L1_INDEX  2  //X-max endstop -- zero on inductor

  //called Z -- my C2
  #define C2_ENABLE A8
  #define C2_STEP   46
  #define C2_DIR    48
  #define C2_INDEX  14  //Y-min endstop


  // Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
  #define MOTOR_STEPS 200
  #define RPM 60

  // Since microstepping is set externally, make sure this matches the selected mode
  // If it doesn't, the motor will move at a different RPM than chosen
  // 1=full step, 2=half step etc.
  #define MICROSTEPS 1



  
  


#endif
