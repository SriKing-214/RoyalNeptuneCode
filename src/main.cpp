#include "vex.h"
#include "robot-config.h"
#include "auton.h"
#include "usercontrol.h"

using namespace vex;

// Only ONE competition object, and it lives here
competition Competition;

void pre_auton(void)
{
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.setTurnVelocity(40, percent);
  Drivetrain.setStopping(brake);
  Drivetrain.setTimeout(3, seconds);
}

int main()
{
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true)
  {
    wait(10, msec);
  }
}