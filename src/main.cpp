/*----------------------------------------------------------------------------------*/
/*                                                                                  */
/*    Module:             main.cpp                                                  */
/*    Author:             VEX                                                       */
/*    Created:            Wed Jun 09 2021                                           */
/*    Description:        Drive to Location (Unknown Starting Position)             */
/*                        This example will show how to use a GPS Sensor to         */
/*                        navigate a V5 Moby Hero Bot to a specified position       */
/*                        by driving along the X-axis then the Y-axis               */
/*                                                                                  */
/*    Starting Position:  Any                                                       */
/*                                                                                  */
/*----------------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 3        
// ForkMotorGroup       motor_group   2, 9            
// Rotation4            rotation      4               
// GPS8                 gps           8               
// DistanceLeft         distance      12              
// DistanceRight        distance      20              
// Optical19            optical       19              
// BumperA              bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int referenceAngle;

controller controller1;



controller Controller1 = controller(primary);

int controler_on_of = 0;

int ifsothenso = 0;

int colllor = 0; // 1 = blu, red 2, green 3

int runonce = 0;


event checkBlue = event();
event checkRed = event();
event checkGreen = event();



// bumper A (takin)


int vega;
int vegastop = 100;





const int CENTER_FOV =160;
const int OFFSET_X = 50;






void hasGreenCallback() {
  if (controler_on_of == 0)
{

    controller1.Screen.print(colllor);
  Vision5.takeSnapshot(Vision5__GREENBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}}
while (ifsothenso == 1){
  Vision5.takeSnapshot(Vision5__GREENBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}
    Vision5.takeSnapshot(Vision5__GREENBOX);
    vega= Vision5.largestObject.width;
        //ef vegaleingd off stut
    if(vega > vegastop){
       Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.drive(forward);
      ClawMotor.spin(reverse);
      wait(1, sec);
      ifsothenso = 3;
      wait(0.5, sec);
      ClawMotor.spin(forward);
      ArmMotor.spin(reverse);
      ArmMotor2.spin(reverse);
      wait(2, sec);
      ArmMotor.stop();
      ArmMotor2.stop();
      vega= Vision5.largestObject.width;

  // 1 = blu, red 2, green 3

  colllor = 3;
      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(4, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-4, deg);
          vega= Vision5.largestObject.width;
        }
        else{
        Drivetrain.drive(forward);
    }
        vega= Vision5.largestObject.width;
      }
  } 
  }
}
}






void hasRedCallback() {
  if (controler_on_of == 0)
{

    controller1.Screen.print(colllor);
  Vision5.takeSnapshot(Vision5__REDBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}}
while (ifsothenso == 1){
  Vision5.takeSnapshot(Vision5__REDBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}
    Vision5.takeSnapshot(Vision5__REDBOX);
    vega= Vision5.largestObject.width;
        //ef vegaleingd off stut
    if(vega > vegastop){
       Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.drive(forward);
      ClawMotor.spin(reverse);
      wait(1, sec);
      ifsothenso = 3;
      wait(0.5, sec);
      ClawMotor.spin(forward);
      ArmMotor.spin(reverse);
      ArmMotor2.spin(reverse);
      wait(2, sec);
      ArmMotor.stop();
      ArmMotor2.stop();
      vega= Vision5.largestObject.width;
        // 1 = blu, red 2, green 3
  colllor = 2;

      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(4, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-4, deg);
          vega= Vision5.largestObject.width;
        }
        else{
        Drivetrain.drive(forward);
    }
        vega= Vision5.largestObject.width;
      }
  } 
  }
}
}
















void hasBlueCallback() {
  if (controler_on_of == 0)
{

    controller1.Screen.print("Blue");
  Vision5.takeSnapshot(Vision5__BLUEBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}}
while (ifsothenso == 1){
  Vision5.takeSnapshot(Vision5__BLUEBOX);
  if (Vision5.objectCount > 0) {
  if (runonce== 0){
    runonce = 1;
    ClawMotor.spin(reverse);
    wait(1, sec);
    ifsothenso = 1;
}
    Vision5.takeSnapshot(Vision5__BLUEBOX);
    vega= Vision5.largestObject.width;
        //ef vegaleingd off stut
    if(vega > vegastop){
    controller1.Screen.print("ef vegaleingd off stut(done)");
       Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.drive(forward);
      ClawMotor.spin(reverse);
      wait(1, sec);
      ifsothenso = 3;
      wait(0.5, sec);


      
      ClawMotor.spin(forward);
      ArmMotor.spin(reverse);
      ArmMotor2.spin(reverse);
      wait(2, sec);
      ArmMotor.stop();
      ArmMotor2.stop();
      vega= Vision5.largestObject.width;
  // 1 = blu, red 2, green 3
  colllor = 1;
      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(4, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-4, deg);
          vega= Vision5.largestObject.width;
        }
        else{
        Drivetrain.drive(forward);
    }
        vega= Vision5.largestObject.width;
      }
  } 
  }
}
}





















void driveToPositionX(double x) {
  if (controler_on_of == 0)
{
  // Reorient the robot before driving along the X-axis
  if (GPS8.xPosition(mm) < x) {


    referenceAngle = 90;
  }
  else {



    referenceAngle = 270;
  }



    GPS8.calibrate();
   waitUntil(!GPS8.isCalibrating());

    controller1.Screen.print(colllor);

  Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
  

  
    
    controller1.Screen.print(colllor);
  Drivetrain.drive(forward);

float pos1=GPS8.yPosition(mm);

  // Keep driving until the GPS position for the X-axis is within 20mm of the target X position
  while (!(GPS8.xPosition(mm) - x > -50 && GPS8.xPosition(mm) - x < 50)) {

        if ((GPS8.yPosition(mm) > (pos1 -50) && GPS8.yPosition(mm)  < (pos1+50))){
    controller1.Screen.print(colllor);
      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      wait(0.1, seconds);
      Drivetrain.drive(forward);}
      
      
      
  }

  // This will allow the drivetrain to stop in time, preventing the robot from overshooting the target
  Drivetrain.stop();
}
}

void driveToPositionY(double y) {
if (controler_on_of == 0)
{
  // Reorient the robot before driving along the Y-axis
  if (GPS8.yPosition(mm) < y) {

    referenceAngle = 0;
  }
  else {

    referenceAngle = 180;
  }
  // Using an absolute reference angle along with the GPS heading,
  // we can turn the robot to face the correct direction before driving along the Y-axis
    controller1.Screen.print(colllor);
  Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
  Drivetrain.drive(forward);


int sad = 1;
  float pos2=GPS8.xPosition(mm);
  while (!(GPS8.yPosition(mm) - y > -50 && GPS8.yPosition(mm) - y < 50)) {



          if ((GPS8.xPosition(mm) > (pos2 -50) && GPS8.xPosition(mm)  < (pos2+50))){
    controller1.Screen.print(colllor);
      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      wait(0.1, seconds);
      Drivetrain.drive(forward);}


    
  }

  // This will allow the drivetrain to stop in time, preventing the robot from overshooting the target
  Drivetrain.stop();
  LeftMotor.stop();
  RightMotor.stop();

        ArmMotor.spin(forward);
        ArmMotor2.spin(forward);
        wait(5, seconds);

        ArmMotor.stop();
        ArmMotor2.stop();
  ClawMotor.spin(reverse);
  wait(1.5, seconds);
  ClawMotor.stop();
}
}




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


void controller_B_Pressed(){
  while (true)
  {
  
   // Create Controller callback events - 15 msec delay to ensure events get registered
  Controller1.ButtonL1.pressed(controller_L1_Pressed);
  Controller1.ButtonL2.pressed(controller_L2_Pressed);
  Controller1.ButtonR1.pressed(controller_R1_Pressed);
  Controller1.ButtonR2.pressed(controller_R2_Pressed);
  wait(15,msec);

  // Configure Arm and Claw motor hold settings and velocity
  ArmMotor.setStopping(hold);
  ClawMotor.setStopping(hold);
  ArmMotor.setVelocity(90, percent);
  ClawMotor.setVelocity(70, percent);

  // Main Controller loop to set motors to controller axis postiions
  while(true){
    LeftMotor.setVelocity(Controller1.Axis3.position(), percent);
    RightMotor.setVelocity(Controller1.Axis2.position(), percent);
    LeftMotor.spin(forward);
    RightMotor.spin(forward);
    wait(5, msec);
  }
  /* code */
  }

}


int myTaskCallback() {
while (true)
{
 
  Controller1.ButtonB.pressed(controller_B_Pressed);

    Controller1.ButtonL1.pressed(controller_L1_Pressed);
  Controller1.ButtonL2.pressed(controller_L2_Pressed);
  Controller1.ButtonR1.pressed(controller_R1_Pressed);
  Controller1.ButtonR2.pressed(controller_R2_Pressed);
}


}


int main() {
  task myTask = task(myTaskCallback);
  



ifsothenso = 0;

colllor = 0; 

runonce = 0;

 

  // Calibrate the GPS before starting
  GPS8.calibrate();
      GyroD.calibrate();
  waitUntil(!GyroD.isCalibrating());



  vexcodeInit();
 




    
  while (!(ifsothenso==3 && controler_on_of == 0)) {

       Drivetrain.setTurnVelocity(10, percent);
      Drivetrain.turn(left);
    checkBlue.broadcastAndWait();
    checkBlue(hasBlueCallback);

    checkRed.broadcastAndWait();
    checkRed(hasRedCallback);

    checkGreen.broadcastAndWait();
    checkGreen(hasGreenCallback);

    
    controller1.Screen.clearScreen();
    controller1.Screen.print(colllor);
    //myTaskCallback2();
    
  }

         Drivetrain.setTurnVelocity(50, percent);

  
  double x=0;
  double y=0;
// 1 = blu, red 2, green 3
if (colllor == 1)
{
  //(-1,2;1,2) 5%
   x=-800;
   y=800;
}
if (colllor == 2)
{
  //(-1,5;0) 5%
   x=-1100;
   y=0;
}
if (colllor == 3)
{
  //(1,5;0) 5%
   x=1100;
   y=0;
}


    controller1.Screen.clearScreen();
    controller1.Screen.print(colllor);
  // Drive the robot to the specified X and Y position
  driveToPositionX(x);
    controller1.Screen.clearScreen();
    controller1.Screen.print(colllor);
  driveToPositionY(y);



}




