#include "include.hpp"

std::vector<std::unique_ptr<double[]>> loadedAuton;

Motor frontLeft (4, false, AbstractMotor::gearset::green);
Motor frontRight (14, true, AbstractMotor::gearset::green);
Motor backLeft (15, false, AbstractMotor::gearset::green);
Motor backRight (5, true, AbstractMotor::gearset::green);

MotorGroup left ({frontLeft, backLeft});
MotorGroup right ({frontRight, backRight});

Controller controller(ControllerId::master);