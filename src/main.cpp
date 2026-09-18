/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Sriha                                                     */
/*    Created:      9/17/2026, 1:01:02 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
brain Brain;
controller Controller1 = controller(primary);
motor leftMotor = motor(PORT1, false);
motor rightMotor = motor(PORT10, true);
motor armMotor = motor(PORT8, false);
motor clawMotor = motor(PORT3, false);

drivetrain Drivetrain = drivetrain(
    leftMotor, rightMotor,
    259.34,
    320,
    130,
    mm, 1.0);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.setTurnVelocity(40, percent);
  Drivetrain.setStopping(brake);
  Drivetrain.setTimeout(3, seconds);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void)
{
  // Set the stopping mode for the arm and claw motors to hold
  armMotor.setStopping(hold);
  clawMotor.setStopping(hold);
  // User control code here, inside the loop
  while (1)
  {
    int fwd = Controller1.Axis3.position(percent);
    int turn = Controller1.Axis1.position(percent);

    if ((fwd < 5) && (fwd > -5))
    {
      fwd = 0;
    } // deadband: ignores stick drift

    if ((turn < 5) && (turn > -5))
    {
      turn = 0;
    } // deadband: ignores stick drift

    leftMotor.spin(forward, fwd + turn, percent);
    rightMotor.spin(forward, fwd - turn, percent);

    // Arm control
    if (Controller1.ButtonL1.pressing())
    {
      armMotor.spin(forward, 50, percent);
    }
    else if (Controller1.ButtonL2.pressing())
    {
      armMotor.spin(reverse, 50, percent);
    }
    else
    {
      armMotor.stop(hold);
    }
    // Control the claw motor based on button presses
    if (Controller1.ButtonR1.pressing())
    {
      clawMotor.spin(forward, 50, percent);
    }
    else if (Controller1.ButtonR2.pressing())
    {
      clawMotor.spin(reverse, 50, percent);
    }
    else
    {
      clawMotor.stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
