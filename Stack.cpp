#include "Stack.h"

using namespace std;

Stack::Stack() {};
int Stack::getNumOfCars() {
	return this->numOfCars;
}

bool Stack::isFull() { // check if the stack is full
	return this->numOfCars >= this->maxLength;
}
bool Stack::isEmpty() { // check if the stack is empty
	return this->numOfCars == 0;
}
void Stack::pushCar(Car car) {
	//push a car without incrementing the number of moves, will be used for the first time arriving
	this->cars[numOfCars] = car;
	numOfCars++;
}

void Stack::pushCarWithMoves(Car car) {
	// push a car with incrementing the number of moves, will be used for the cars moving between garage and street
	this->cars[numOfCars] = car;
	numOfCars++;
	car.incrementMoveCounter();
}
Car Stack::popCar() {
	// pop a car without incrementing the number of moves, will be used for the specified car leaving
	Car carToPop = this->cars[numOfCars - 1];
	numOfCars--;
	return carToPop;
}
Car Stack::popCarWithMoves() {
	//pop a car with incrementing the number of moves, will be used for the cars moving between garage and street
	Car carToPop = this->cars[numOfCars - 1];
	numOfCars--;
	carToPop.incrementMoveCounter();
	return carToPop;
}
bool Stack::searchCar(string carPlate) { // search if a car in the stack
	for (int i = 0; i < this->getNumOfCars(); i++) {
		if (carPlate == this->cars[i].getPlate()) {
			return true;
		}
	}
	return false;
}
Car Stack::getTopCar() { // get the top car in the stack
	return this->cars[this->getNumOfCars() - 1];
}

void Stack::displayCars() { //display all the cars' plates in the stack
	for (int i = 0; i < this->getNumOfCars(); i++) {
		cout << "(" << i + 1 << ")" << cars[i].getPlate() << " ";
	}
}
