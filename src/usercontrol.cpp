#include "robot-config.h"
#include "usercontrol.h"

void usercontrol(void)
{
    armMotor.setStopping(hold);
    clawMotor.setStopping(hold);

    while (1)
    {
        int fwd = Controller1.Axis3.position(percent);
        int turn = Controller1.Axis1.position(percent);

        if ((fwd < 5) && (fwd > -5))
        {
            fwd = 0;
        }
        if ((turn < 5) && (turn > -5))
        {
            turn = 0;
        }

        leftMotor.spin(forward, (fwd + turn) * 0.127, volt);
        rightMotor.spin(forward, (fwd - turn) * 0.127, volt);

        // Arm
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

        // Claw
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
            clawMotor.stop(hold);
        }

        wait(10, msec);
    }
}