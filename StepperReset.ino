
////////////////////////////////////////////////////////////////////////////////
// StepperReset
//   Reset the stepper motors to the zero indexes
////////////////////////////////////////////////////////////////////////////////



void stepper_reset_to_zero() {
  Serial.println("stepper reset start");
  stepperC1.enable();
  stepperC1.rotate(360);
  stepperC1.disable();
  delay(1000);
  stepperL1.enable();
  stepperL1.rotate(360);
  stepperL1.disable();
  delay(1000);
  stepperC2.enable();
  stepperC2.rotate(360);
  stepperC2.disable();
  Serial.println("stepper reset finish");
}

