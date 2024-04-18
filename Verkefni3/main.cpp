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

void driveToPositionX(double x) {

  // Reorient the robot before driving along the X-axis
  if (GPS8.xPosition(mm) < x) {


    referenceAngle = 90;
  }
  else {



    referenceAngle = 270;
  }
  // Using an absolute reference angle along with the GPS heading,
  // we can turn the robot to face the correct direction before driving along the X-axis

/*
while (true)
{
  Brain.Screen.print( GPS8.heading());
    Brain.Screen.print("X: %.2f", GPS8.xPosition(mm));
  Brain.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  Brain.Screen.newLine();

controller1.Screen.print( GPS8.heading());
      controller1.Screen.print("X: %.2f", GPS8.xPosition(mm));
  controller1.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  controller1.Screen.newLine();
}*/


    GPS8.calibrate();
   waitUntil(!GPS8.isCalibrating());

  Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
  

  
    controller1.Screen.clearScreen();
    
    controller1.Screen.print("forward");
  Drivetrain.drive(forward);

float pos1=GPS8.yPosition(mm);

  // Keep driving until the GPS position for the X-axis is within 20mm of the target X position
  while (!(GPS8.xPosition(mm) - x > -50 && GPS8.xPosition(mm) - x < 50)) {

        if ((GPS8.yPosition(mm) > (pos1 -50) && GPS8.yPosition(mm)  < (pos1+50))){
      //Drivetrain.setTurnVelocity(5, percent);
      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      //Drivetrain.stop();
      wait(0.1, seconds);
      //Drivetrain.setTurnVelocity(10, percent);
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

/*
controller1.Screen.clearScreen();
 controller1.Screen.newLine();
      controller1.Screen.print("end game");
  controller1.Screen.newLine();
*/
  // Keep driving until the GPS position for the Y-axis is within 20mm of the target Y position
int sad = 1;
  float pos2=GPS8.xPosition(mm);
  while (!(GPS8.yPosition(mm) - y > -50 && GPS8.yPosition(mm) - y < 50)) {


//if ((GPS8.yPosition(mm) > (pos2 -50) && GPS8.yPosition(mm)  < (pos2+50))){

          if ((GPS8.xPosition(mm) > (pos2 -50) && GPS8.xPosition(mm)  < (pos2+50))){
      //Drivetrain.setTurnVelocity(5, percent);
      Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      //Drivetrain.stop();
      wait(0.1, seconds);
      //Drivetrain.setTurnVelocity(10, percent);
      Drivetrain.drive(forward);}
  /*
  if (sad==1)
  {
          Drivetrain.turnFor(right, (referenceAngle - GPS8.heading()), degrees, true);
      //Drivetrain.stop();
      
      //Drivetrain.setTurnVelocity(10, percent);
      Drivetrain.drive(forward);
      sad = 2;
  }
  else
  
      Drivetrain.turnFor(left, (referenceAngle - GPS8.heading()), degrees, true);
      //Drivetrain.stop();
      
      //Drivetrain.setTurnVelocity(10, percent);
      Drivetrain.drive(forward);
      sad = 1;
}

*/

    
  }

  // This will allow the drivetrain to stop in time, preventing the robot from overshooting the target
  Drivetrain.stop();
  //LeftMotor.stop();
  //RightMotor.stop();
}

void printPosition() {
  // Print GPS position values to the V5 Brain

  Brain.Screen.print("X: %.2f", GPS8.xPosition(mm));
  Brain.Screen.print("  Y: %.2f", GPS8.yPosition(mm));
  Brain.Screen.newLine();
}

int main() {
  // Calibrate the GPS before starting
  GPS8.calibrate();
 // while (GPS8.isCalibrating()) { task::sleep(50); }
      GyroD.calibrate();
  waitUntil(!GyroD.isCalibrating());

  Drivetrain.setTurnVelocity(10, percent);
  
  // Print the starting position of the robot
  
  printPosition();

  // Drive the robot to the specified X and Y position
  driveToPositionX(0);
  driveToPositionY(0);

  // Print the ending position of the robot
  printPosition();
}
