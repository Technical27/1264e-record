#include "include.hpp"

std::atomic_bool rec (true);

void record (void*) {
	int start = pros::millis();
	std::unique_ptr<double[]> doubles;
	while (rec) {
		doubles = std::make_unique<double[]>(4);

		doubles[1] = frontRight.getActualVelocity();
		doubles[2] = frontLeft.getActualVelocity();
		doubles[3] = backRight.getActualVelocity();
		doubles[4] = backLeft.getActualVelocity();

		loadedAuton.push_back(std::move(doubles));

		pros::Task::delay(250);

		if (start + 15000 < pros::millis()) rec = false;
	}
}

void opcontrol() {
	while (!controller.getDigital(ControllerDigital::A)) pros::Task::delay(10);
	controller.rumble(".");
	pros::Task recordTask (record);
	while (rec) {
		left.moveVoltage(controller.getAnalog(ControllerAnalog::leftY) * 12000);
  	right.moveVoltage(controller.getAnalog(ControllerAnalog::rightY) * 12000);
	}
	saveAuton("/usd/auton");
	controller.rumble(".");
}