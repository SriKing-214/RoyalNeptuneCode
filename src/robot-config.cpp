#include "robot-config.h"

brain Brain;
controller Controller1 = controller(primary);
motor leftMotor = motor(PORT7, false);
motor rightMotor = motor(PORT5, true);
motor armMotor = motor(PORT8, false);
motor clawMotor = motor(PORT4, false);

drivetrain Drivetrain = drivetrain(
    leftMotor, rightMotor,
    259.34,
    320,
    130,
    mm, 1.0);