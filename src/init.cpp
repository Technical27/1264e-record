#include "include.hpp"

std::vector<std::unique_ptr<double[]>> loadedAuton;

Motor frontLeft (10, false, AbstractMotor::gearset::green);
Motor frontRight (20, true, AbstractMotor::gearset::green);
Motor backLeft (1, false, AbstractMotor::gearset::green);
Motor backRight (11, true, AbstractMotor::gearset::green);

MotorGroup left ({frontLeft, backLeft});
MotorGroup right ({frontRight, backRight});

Controller controller(ControllerId::master);