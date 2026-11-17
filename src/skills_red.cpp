#include "robot-config.h"
#include "skills_red.h"
#include "toggle.h"

// ---------- SKILLS RED: TUNE THESE (first guesses) ----------
static const int PUSH_CYCLES = 3;          // push-and-return cycles on the toggle
static const double BACKOFF_IN = 10;       // back away from the toggle
static const double TURN_TO_MID_DEG = 120; // turn toward the middle square
static const double TO_MIDDLE_IN = 60;     // drive until Flex is partly inside the Midfield
static const double DRIVE_SPEED = 60;      // % speed for the trip to the middle
// --------------------------------------------------------------

void skillsRed(void)
{
    // 1. Flex starts right next to the toggle: feel for it, push it, repeat
    flipToggle(PUSH_CYCLES);

    // 2. Drive to the middle
    Drivetrain.setDriveVelocity(DRIVE_SPEED, percent);
    Drivetrain.setTimeout(5, seconds); // long drive needs more time

    Drivetrain.driveFor(reverse, BACKOFF_IN, inches);
    Drivetrain.turnFor(right, TURN_TO_MID_DEG, degrees); // swap to left if it turns away from the middle
    Drivetrain.driveFor(forward, TO_MIDDLE_IN, inches);

    Drivetrain.stop();
}