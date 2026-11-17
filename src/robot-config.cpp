#include "robot-config.h"

brain Brain;
controller Controller1 = controller(primary);
motor leftMotor = motor(PORT1, false);
motor rightMotor = motor(PORT5, true);
motor armMotor = motor(PORT8, false);
motor clawMotor = motor(PORT6, false);

drivetrain Drivetrain = drivetrain(
    leftMotor, rightMotor,
    259.34, // wheelTravel (mm): the original placeholder, never measured
    320,    // trackWidth (mm): the original placeholder
    130,    // wheelBase (mm): the original placeholder
    mm, 1.0);
