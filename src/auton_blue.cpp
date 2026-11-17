#include "robot-config.h"
#include "auton_blue.h"
#include "toggle.h"

// ---------- BLUE: TUNE THESE (all first guesses) ----------
static const int PUSH_CYCLES = 3;           // push-and-return cycles on the toggle
static const double BACKOFF_IN = 10;        // back away from the toggle
static const double TURN_TO_GOAL_DEG = 115; // left turn toward the goal
static const double TO_GOAL_IN = 20;
static const double DRIVE_SPEED = 60; // % speed for normal driving
static const double ARM_LIFT_DEG = 150;
static const double GOAL_NUDGE_IN = 6;
static const double CLAW_OPEN_DEG = 90;
// ----------------------------------------------------------

void autonBlue(void)
{
    armMotor.setStopping(hold);
    clawMotor.setStopping(hold);
    armMotor.setTimeout(2, seconds);
    clawMotor.setTimeout(2, seconds);

    // 1. Flex starts right next to the toggle: feel for it, push it, repeat
    flipToggle(PUSH_CYCLES);

    // 2. Go to the nearest blue goal
    Drivetrain.setDriveVelocity(DRIVE_SPEED, percent);
    Drivetrain.setTimeout(3, seconds);
    Drivetrain.driveFor(reverse, BACKOFF_IN, inches);
    Drivetrain.turnFor(left, TURN_TO_GOAL_DEG, degrees); // swap to right if it turns away from the goal
    Drivetrain.driveFor(forward, TO_GOAL_IN, inches);

    // 3. Stack the preload on the goal
    armMotor.spinFor(forward, ARM_LIFT_DEG, degrees);
    Drivetrain.driveFor(forward, GOAL_NUDGE_IN, inches);
    clawMotor.spinFor(reverse, CLAW_OPEN_DEG, degrees);
    Drivetrain.driveFor(reverse, GOAL_NUDGE_IN, inches);
    armMotor.spinFor(reverse, ARM_LIFT_DEG, degrees);

    Drivetrain.stop();
}