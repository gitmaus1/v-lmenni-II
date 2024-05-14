```C++
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




int ifsothenso = 0;

int colllor = 0; // 1 = blu, red 2, green 3

int runonce = 0;


event checkBlue = event();
event checkRed = event();

// bumper A (takin)


int vega;
int vegastop = 260;





const int CENTER_FOV =158;
const int OFFSET_X = 50;




void hasBlueCallback() {
  colllor = 1;
    controller1.Screen.clearScreen();
    controller1.Screen.print("Blue");
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
          controller1.Screen.clearScreen();
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
      wait(0.1, sec);
      vega= Vision5.largestObject.width;

      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(5, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-5, deg);
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







void hasRedCallback() {
  colllor = 1;
    controller1.Screen.clearScreen();
    controller1.Screen.print("Red");
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
          controller1.Screen.clearScreen();
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
      wait(0.1, sec);
      vega= Vision5.largestObject.width;

      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(5, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-5, deg);
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
















void hasBlueCallback() {
  colllor = 1;
    controller1.Screen.clearScreen();
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
          controller1.Screen.clearScreen();
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
      wait(0.1, sec);
      vega= Vision5.largestObject.width;

      }
     //ef vegaleingd ofnálact
    else {
      //beigur í át að kubinum
         if(Vision5.largestObject.centerX > CENTER_FOV + OFFSET_X){
          Drivetrain.turnFor(5, deg);
          vega= Vision5.largestObject.width;
        }
        else if (Vision5.largestObject.centerX < CENTER_FOV - OFFSET_X) {
          Drivetrain.turnFor(-5, deg);
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





















void driveToPositionX(double x) {

  // Reorient the robot before driving along the X-axis
  if (GPS8.xPosition(mm) < x) {


    referenceAngle = 90;
  }
  else {



    referenceAngle = 270;
  }



    GPS8.calibrate();
   waitUntil(!GPS8.isCalibrating());

       controller1.Screen.clearScreen();
    controller1.Screen.print("turn");

  Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
  

  
    controller1.Screen.clearScreen();
    
    controller1.Screen.print("forward");
  Drivetrain.drive(forward);

float pos1=GPS8.yPosition(mm);

  // Keep driving until the GPS position for the X-axis is within 20mm of the target X position
  while (!(GPS8.xPosition(mm) - x > -50 && GPS8.xPosition(mm) - x < 50)) {

        if ((GPS8.yPosition(mm) > (pos1 -50) && GPS8.yPosition(mm)  < (pos1+50))){

      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      wait(0.1, seconds);
      Drivetrain.drive(forward);}
      
      
      
  }

  // This will allow the drivetrain to stop in time, preventing the robot from overshooting the target
  Drivetrain.stop();
  
}

void driveToPositionY(double y) {

  // Reorient the robot before driving along the Y-axis
  if (GPS8.yPosition(mm) < y) {

    referenceAngle = 0;
  }
  else {

    referenceAngle = 180;
  }
  // Using an absolute reference angle along with the GPS heading,
  // we can turn the robot to face the correct direction before driving along the Y-axis
  Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
  Drivetrain.drive(forward);


int sad = 1;
  float pos2=GPS8.xPosition(mm);
  while (!(GPS8.yPosition(mm) - y > -50 && GPS8.yPosition(mm) - y < 50)) {



          if ((GPS8.xPosition(mm) > (pos2 -50) && GPS8.xPosition(mm)  < (pos2+50))){
      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      wait(0.1, seconds);
      Drivetrain.drive(forward);}


    
  }

  // This will allow the drivetrain to stop in time, preventing the robot from overshooting the target
  Drivetrain.stop();
  LeftMotor.stop();
  RightMotor.stop();
}

void printPosition() {
  // Print GPS position values to the V5 Brain

  Brain.Screen.print("X: %.2f", GPS8.xPosition(mm));
  Brain.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  Brain.Screen.newLine();
}

int main() {

for (size_t i = 0; i < 3; i++)
{
 




  // Calibrate the GPS before starting
  GPS8.calibrate();
 // while (GPS8.isCalibrating()) { task::sleep(50); }
      GyroD.calibrate();
  waitUntil(!GyroD.isCalibrating());

  






  vexcodeInit();
 

    controller1.Screen.clearScreen();
    controller1.Screen.print("3");


    
  while (!(ifsothenso==3 )) {

       Drivetrain.setTurnVelocity(10, percent);
      Drivetrain.turn(left);
    checkBlue.broadcastAndWait();
    checkBlue(hasBlueCallback);

    checkRed.broadcastAndWait();
    checkRed(hasRedCallback);

    
    controller1.Screen.clearScreen();
    controller1.Screen.print("done");
    //myTaskCallback2();
    
  }
  
  double x=0;
  double y=0;
// 1 = blu, red 2, green 3
if (colllor == 1)
{
   x=-1,2;
   y=1,2;
}
else if (colllor == 2)
{
   x=-1,5;
   y=0;
}
else if (colllor == 3)
{
   x=1,5;
   y=0;
}




    printPosition();

    controller1.Screen.clearScreen();
    controller1.Screen.print("driveToPositionX");
  // Drive the robot to the specified X and Y position
  driveToPositionX(x);
    controller1.Screen.clearScreen();
    controller1.Screen.print("driveToPositionY");
  driveToPositionY(y);

  // Print the ending position of the robot
  printPosition();


}


```C++
}