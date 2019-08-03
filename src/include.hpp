#include "main.h"
#include <memory>
#include <vector>
#include <stdio.h>

extern std::vector<std::unique_ptr<double[]>> loadedAuton;

extern Motor frontLeft;
extern Motor frontRight;
extern Motor backLeft;
extern Motor backRight;

extern MotorGroup left;
extern MotorGroup right;

extern Controller controller;

void saveAuton (const char* filename);