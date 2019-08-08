#include "include.hpp"

std::atomic_bool rec (true);

void record (void*) {
	std::unique_ptr<double[]> doubles;
	while (rec) {
		doubles = std::make_unique<double[]>(4);

		doubles[0] = frontRight.getActualVelocity();
		doubles[1] = frontLeft.getActualVelocity();
		doubles[2] = backRight.getActualVelocity();
		doubles[3] = backLeft.getActualVelocity();

		loadedAuton.push_back(std::move(doubles));

		pros::Task::delay(20);
	}
	saveAuton("/usd/auton");
	controller.rumble(".");
}

void opcontrol() {
	while (!controller.getDigital(ControllerDigital::A)) pros::Task::delay(10);
	controller.rumble(".");
	pros::Task recordTask (record);
	while (true) {
		if (controller.getDigital(ControllerDigital::B)) break;
		left.moveVoltage(controller.getAnalog(ControllerAnalog::leftY) * 12000);
  	right.moveVoltage(controller.getAnalog(ControllerAnalog::rightY) * 12000);
	}
	rec = false;
	left.moveVoltage(0);
	right.moveVoltage(0);
	while (true) pros::Task::delay(10);
}