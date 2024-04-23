#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
light LightF = light(Brain.ThreeWirePort.G);
motor LeftDriveSmart = motor(PORT4, ratio18_1, false);
motor RightDriveSmart = motor(PORT10, ratio18_1, true);
motor LeftMotor = motor(PORT4, ratio18_1, false);
motor RightMotor = motor(PORT10, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
sonar RangeFinderC = sonar(Brain.ThreeWirePort.C);

// VEXcode generated functions

bumper bumperA = bumper(Brain.ThreeWirePort.A);


// A global instance of brain used for printing to the V5 Brain screen

/////////////////////////////////////////////////////////////////////////////////////
signature Vision5__BLUEBOX =
    signature(1, 1489, 2551, 2020, 3881, 6323, 5102, 2.5, 0);

vision Vision5 =
    vision(PORT2, 50, Vision5__BLUEBOX);
/////////////////////////////////////////////////////////////////////////////////////
// bumper A (takin)





gyro TurnGyroSmart = gyro(Brain.ThreeWirePort.H);




motor ClawMotor = motor(PORT9, ratio18_1, false);
motor ArmMotor = motor(PORT8, ratio18_1, false);
//motor LeftMotor = motor(PORT4, ratio18_1, false);
//motor RightMotor = motor(PORT10, ratio18_1, true);
/////////////////////////////////////////////////////////////////////////////////////
line LineTrackerB = line(Brain.ThreeWirePort.B);
line LineTrackerE = line(Brain.ThreeWirePort.E);
line LineTrackerF = line(Brain.ThreeWirePort.F);
// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
  
}