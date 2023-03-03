#include "Car.h"

using namespace std;

Car::Car() {
	this->plate = "null";
	moveCounter = 0;
};
void Car::setPlate(string carPlate) {
	this->plate = carPlate;
}
string Car::getPlate() {
	return this->plate;
}
int Car::getMoveCounter() {
	return this->moveCounter;
}
void Car::incrementMoveCounter() {
	this->moveCounter++;
}

