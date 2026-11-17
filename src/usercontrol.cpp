#include "robot-config.h"
#include "usercontrol.h"
#include "auton_blue.h"
#include "auton_red.h"
#include "skills_blue.h"
#include "skills_red.h"

// Driver speed cap: 1.0 = full speed. Raise it as you get comfortable.
const double DRIVE_SCALE = 1;

void usercontrol(void)
{
    while (true)
    {
        armMotor.setStopping(hold);
        clawMotor.setStopping(hold);

        // ---- Driving (arcade, in volts) ----
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

        leftMotor.spin(forward, (fwd + turn) * 0.12 * DRIVE_SCALE, volt);
        rightMotor.spin(forward, (fwd - turn) * 0.12 * DRIVE_SCALE, volt);

        // ---- Arm: L1 up, L2 down ----
        if (Controller1.ButtonL1.pressing())
        {
            armMotor.spin(forward, 75, percent);
        }
        else if (Controller1.ButtonL2.pressing())
        {
            armMotor.spin(reverse, 75, percent);
        }
        else
        {
            armMotor.stop(hold);
        }

        // ---- Claw: R1 close, R2 open ----
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