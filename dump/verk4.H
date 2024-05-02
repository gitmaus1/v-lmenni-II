using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern motor_group ForkMotorGroup;
extern rotation Rotation4;
extern gps GPS8;
extern distance DistanceLeft;
extern distance DistanceRight;
extern optical Optical19;
extern bumper BumperA;

extern gyro GyroD;



extern motor LeftMotor;
extern motor RightMotor;



using signature = vision::signature;

// VEXcode devices
extern signature Vision5__BLUEBOX;
extern signature Vision5__REDBOX;
extern signature Vision5__GREENBOX;

extern vision Vision5;


extern motor ClawMotor;



extern motor ArmMotor;
extern motor ArmMotor2;








/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
