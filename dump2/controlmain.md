
```C++

#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;

motor LeftMotor = motor(PORT1, ratio18_1, false);
motor RightMotor = motor(PORT2, ratio18_1, true);
motor ArmMotor = motor(PORT3, ratio18_1, false);
motor ArmMotor2 = motor(PORT4, ratio18_1, true);
motor ClawMotor = motor(PORT5, ratio18_1, false);
controller Controller1 = controller(primary);

// Begin project code

void controller_L1_Pressed(){
        ArmMotor.spin(reverse);
      ArmMotor2.spin(reverse);
  while (Controller1.ButtonL1.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_L2_Pressed(){
        ArmMotor.spin(forward);
      ArmMotor2.spin(forward);
  while (Controller1.ButtonL2.pressing()) {
    wait(5, msec);
  }
  ArmMotor.stop();
}

void controller_R1_Pressed(){
   ClawMotor.stop();
  ClawMotor.spin(reverse);
  while (Controller1.ButtonR1.pressing()) {
    wait(5, msec);
  }
  
}

void controller_R2_Pressed(){
   ClawMotor.stop();
  ClawMotor.spin(forward);
  while (Controller1.ButtonR2.pressing()) {
    wait(5, msec);
  }

}

int main() {

  // Create Controller callback events - 15 msec delay to ensure events get registered
  Controller1.ButtonL1.pressed(controller_L1_Pressed);
  Controller1.ButtonL2.pressed(controller_L2_Pressed);
  Controller1.ButtonR1.pressed(controller_R1_Pressed);
  Controller1.ButtonR2.pressed(controller_R2_Pressed);
  wait(15,msec);

  // Configure Arm and Claw motor hold settings and velocity
  ArmMotor.setStopping(hold);
  ClawMotor.setStopping(hold);
  ArmMotor.setVelocity(75, percent);
  ClawMotor.setVelocity(70, percent);

  // Main Controller loop to set motors to controller axis postiions
  while(true){
    LeftMotor.setVelocity(Controller1.Axis3.position(), percent);
    RightMotor.setVelocity(Controller1.Axis2.position(), percent);
    LeftMotor.spin(forward);
    RightMotor.spin(forward);
    wait(5, msec);
  }
}
```
