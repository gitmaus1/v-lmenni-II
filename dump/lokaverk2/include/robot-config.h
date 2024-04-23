using namespace vex;

extern brain Brain;

// VEXcode devices
// extern smartdrive Drivetrain;
extern motor ClawMotor;
extern motor ArmMotor;

extern line LineTrackerB;
extern line LineTrackerE;
extern line LineTrackerF;
extern motor LeftMotor;
extern motor RightMotor;
extern light LightF;

extern sonar RangeFinderC;
extern motor ClawMotor;

extern drivetrain Drivetrain;

using signature = vision::signature;

// VEXcode devices
extern signature Vision5__BLUEBOX;

extern vision Vision5;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);