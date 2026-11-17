#include "vex.h"
#include "robot-config.h"
#include "auton_blue.h"
#include "auton_red.h"
#include "skills_blue.h"
#include "skills_red.h"
#include "usercontrol.h"
using namespace vex;

competition Competition;

void pre_auton(void)
{
  Drivetrain.setDriveVelocity(40, percent);
  Drivetrain.setTurnVelocity(30, percent);
  Drivetrain.setStopping(brake);
  Drivetrain.setTimeout(3, seconds);
}

int main()
{
  // PICK ONE: autonBlue, autonRed, matchauton
  Competition.autonomous(autonRed);
  Competition.drivercontrol(usercontrol);
  while (true)
  {
    wait(20, msec);
  }
}