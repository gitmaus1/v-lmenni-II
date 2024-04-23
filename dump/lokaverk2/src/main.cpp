/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Oct 01 2019                                           */
/*    Description:  Detecting Distances                                       */
/*                  This program will use the Range Finder to stop a robot    */
/*                  300 mm away from a wall.                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// RangeFinderC         sonar         C, D            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// bumper A (takin)
extern bumper bumperA;
extern light LightF;

controller Controller1 = controller(primary);
event checkBlue = event();
// bumper A (takin)


int vega;
int vegastop = 260;

const int CENTER_FOV =158;
const int OFFSET_X = 50;





int ifsothenso = 0;



int runonce = 0;




void hasBlueCallback() {
  

 //   while (ifsothenso == 1)
//  {
  Vision5.takeSnapshot(Vision5__BLUEBOX);
  if (Vision5.objectCount > 0) {

  if (runonce== 0){

    runonce = 1;
    ClawMotor.spin(forward);
    wait(1, sec);
    ifsothenso = 1;
}}
while (ifsothenso == 1){

  Vision5.takeSnapshot(Vision5__BLUEBOX);
  if (Vision5.objectCount > 0) {

  if (runonce== 0){

    runonce = 1;
    ClawMotor.spin(forward);
    wait(1, sec);
    ifsothenso = 1;
}


    Vision5.takeSnapshot(Vision5__BLUEBOX);

    vega= Vision5.largestObject.width;
    

        //ef vegaleingd off stut
    if(vega > vegastop){
      Drivetrain.drive(forward);
      ClawMotor.spin(reverse);
      wait(1, sec);
      ifsothenso = 3;
      Drivetrain.drive(reverse);
      wait(0.5, sec);
      ClawMotor.spin(reverse);
      ArmMotor.spin(forward);
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
//}













// taki b stopar robo
void controller_B_Pressed(){

int end = 1;
  while(end == 1) 
   {
    
    Drivetrain.stop();
    ArmMotor.stop();
    ClawMotor.stop();

//Brain.Screen.print("%.2f", RangeFinderC.distance(mm));
    exit;
   }
}



float dis1;
float dis2;
float dis3;
int ErAðGeeifast = 0;
int ckeka = 0; 

int threshold;

int myTaskCallback() {


  
  
  int count = 0;
  while (true)
  {
    dis2 = dis1 / 60;
    if (ErAðGeeifast == 1){
    dis3 = count * dis2 ;}
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("sekontur %d time", count);
    Brain.Screen.print(" rpm ||");
    Brain.Screen.print(dis1);
    Brain.Screen.print(" rps ||");
    Brain.Screen.print(dis2);
    Brain.Screen.print(" M ||");
    Brain.Screen.print(dis3);
    ///Brain.Screen.clearScreen();
    
    count++;
    wait(1, sec);
  
  // bumberin
  bumperA.pressed(controller_B_Pressed);
  // taki b
  Controller1.ButtonB.pressed(controller_B_Pressed);


    while (LightF.brightness() > 0 && LightF.brightness() < 60) {
      
      Drivetrain.stop();
      bumperA.pressed(controller_B_Pressed);
      Controller1.ButtonB.pressed(controller_B_Pressed);
    } 
  }
  
  return 0;
  
}




int myTaskCallback2() {

        
    if (ifsothenso == 0)
  {
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Wait 1 second before driving forward.
  wait(1, seconds);
  while (RangeFinderC.distance(mm) > 500 && LightF.brightness() >= 60 && ifsothenso == 0) {

    Drivetrain.drive(forward);
    ErAðGeeifast = 1;

if (ckeka==0 && ifsothenso == 0){
  wait(1, seconds);
    dis1 = Drivetrain.velocity(rpm);
    
    ckeka=1;
        Brain.Screen.setCursor(2, 1);
    Brain.Screen.print(dis1);
    

    }
  }
  ErAðGeeifast = 0;
/*
  if (LightF.brightness() > 0 && LightF.brightness() < 60) {
      
      Drivetrain.stop();
    } */
  if (RangeFinderC.distance(mm) < 500 && LightF.brightness() >= 60 && ifsothenso == 0)
  {
    Drivetrain.turnFor(right, 95, degrees);
  }

      
  }
  
  return 0;
}
//int hasBlueCallback() {
 // myTask.stop();
 // myTask2.stop();
 // return 0;
//}

int myTaskCallback3() {




  Drivetrain.turnFor(right, 150, degrees);

   vexcodeInit();
  threshold = 30;

  int OFFLINE = 0;

      LeftMotor.setVelocity(10, percent);
    RightMotor.setVelocity(10, percent);
      RightMotor.spin(forward);
    LeftMotor.spin(forward);
  while (true) {
    Brain.Screen.setCursor(2, 1);
    



    LeftMotor.setVelocity(10, percent);
    RightMotor.setVelocity(10, percent);

    // ef í miðju
    if (LineTrackerB.reflectivity() > threshold ) {
      Brain.Screen.clearScreen();
         Brain.Screen.print("að leita að línu");
          
    } 
    // ef hægrimegin
    else if (LineTrackerE.reflectivity() > threshold) {
      Brain.Screen.clearScreen();
    Brain.Screen.print("hægrimegin");
      RightMotor.setVelocity(10, percent);
      RightMotor.spin(forward);
      LeftMotor.stop();
      wait(20, msec);
      OFFLINE = 1;
    } 
    // ef vinstrimegin
      else if (LineTrackerF.reflectivity() > threshold) {
        Brain.Screen.clearScreen();
        Brain.Screen.print("vinstrimegin");
      LeftMotor.setVelocity(10, percent);
      LeftMotor.spin(forward);
      RightMotor.stop();
      wait(20, msec);
      OFFLINE = 2;
    } 

    // ef einginn
    else
    {
      Brain.Screen.clearScreen();
      Brain.Screen.print("að leita að línu");

      if (OFFLINE == 0)
      {
        LeftMotor.setVelocity(10, percent);
    RightMotor.setVelocity(10, percent);
          LeftMotor.spin(forward);
          RightMotor.spin(forward);
      }
      
      // ef síðast hægrimegin
      else if (OFFLINE == 1)
      {
      RightMotor.setVelocity(20, percent);
      RightMotor.spin(forward);
      LeftMotor.stop();
      }
      // ef síðast vinstrimegin
      else if (OFFLINE == 2)
      {
      LeftMotor.setVelocity(20, percent);
      LeftMotor.spin(forward);
      RightMotor.stop();
      wait(20, msec);
      }
      
      
    }
    
    wait(5, msec);
  }
  }
  







int main() {
  ClawMotor.spin(reverse);
  wait(1, sec);
  ClawMotor.setStopping(hold);


  task myTask = task(myTaskCallback);
  //task myTask2 = task(myTaskCallback2);

  
  vexcodeInit();
 
  while (!(ifsothenso==3)) {
    
    checkBlue.broadcastAndWait();
    checkBlue(hasBlueCallback);
    
    myTaskCallback2();
    
  }
  while (ifsothenso==3) {
    
    myTaskCallback3();
  }


//checkBlue(hasBlueCallback);
//myTask.stop();
//myTask2.stop();
    
    }


  



