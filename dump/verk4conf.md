```C++
#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;


motor LeftMotor = motor(PORT1, ratio18_1, false);
motor RightMotor = motor(PORT2, ratio18_1, true);
// VEXcode device constructors
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
//inertial DrivetrainInertial = inertial(PORT3);




gyro GyroD = gyro(Brain.ThreeWirePort.A);

gps GPS8 = gps(PORT6, 0, 0, mm, 180);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, GPS8, 267, 280, 277, mm, 1);





signature Vision5__BLUEBOX = signature (1, 539, 1401, 970, 5877, 9939, 7908, 2.5, 0);
signature Vision5__REDBOX = signature (2, 7835, 9061, 8448, -1805, -1269, -1537, 2.5, 0);
signature Vision5__GREENBOX = signature (3, -6931, -4891, -5911, -3841, -1959, -2900, 2.5, 0);

vision Vision5 = vision (PORT7, 50, Vision5__BLUEBOX, Vision5__REDBOX, Vision5__GREENBOX);







// VEXcode generated functions
motor ClawMotor = motor(PORT5, ratio18_1, false);



motor ArmMotor = motor(PORT3, ratio18_1, false);
motor ArmMotor2 = motor(PORT4, ratio18_1, true);


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);

  //DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
    GyroD.calibrate();
  waitUntil(!GyroD.isCalibrating());
  // wait for the Inertial calibration process to finish
 // while (DrivetrainInertial.isCalibrating()) {
 //   wait(25, msec);
 // }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}
```
