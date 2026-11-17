#include "robot-config.h"
#include "auton_red.h"

void autonRed(void)
{
    armMotor.setStopping(hold);
    clawMotor.setStopping(hold);
    armMotor.setTimeout(2, seconds);
    clawMotor.setTimeout(2, seconds);
    armMotor.setVelocity(100, percent);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.setTurnVelocity(40, percent);

    // Turns toggle to alliance color
    armMotor.spinFor(reverse, 900, degrees);
    Drivetrain.driveFor(forward, 250, mm);
    Drivetrain.driveFor(reverse, 850, mm);
    Drivetrain.setTimeout(1, seconds);
    Drivetrain.turnFor(right, 45, degrees);
    Drivetrain.setDriveVelocity(50, percent);
    Drivetrain.driveFor(forward, 450, mm);
    Drivetrain.setDriveVelocity(100, percent);
    Drivetrain.driveFor(reverse, 900, mm);

    Drivetrain.turnFor(right, 85, degrees);
    // Drives to the red goal
    Drivetrain.setDriveVelocity(75, percent);
    for (int i = 0; i < 5; i++)
    {
        Drivetrain.driveFor(forward, 280, mm);
    }
    Drivetrain.setTimeout(0.5, seconds);
    armMotor.spinFor(forward, 800, degrees);
    clawMotor.spinFor(reverse, 700, degrees);
}
