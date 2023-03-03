#include "Garage.h"

using namespace std;

void Garage::carArrival(Car car) {
	if (!lane1.searchCar(car.getPlate()) && !lane1.searchCar(car.getPlate())) {
		//first check if this car was NOT parked in lane1 or lane2, check in case any mis-information
		if (!this->lane1.isFull()) { // if lane1 is not full, park the new car here
			this->lane1.pushCar(car);
			cout << "A " << car.getPlate() << "\t\t" << car.getPlate() << " parks in lane1." << endl;
		}
		else if (!this->lane2.isFull()) { // if lane1 is full but lane2 is not full, park the new car here
			this->lane2.pushCar(car);
			cout << "A " << car.getPlate() << "\t\t" << car.getPlate() << " parks in lane2." << endl;
		}
		else { //if both lane1 and lane2 are full, tell the car to leave	
			cout << "Sorry the garage is full, please look for another parking place." << endl;
		}
	}
	else { // if this car was found in lane1 or lane2, error happens
		cout << "A " << car.getPlate() << "\t\t" << car.getPlate() << " Error... this car is in the garage, it cannot arrive again." << endl;
	}

}
bool Garage::searchLane(Stack lane, string carPlate) {//check if this stack contains the car
	if (lane.searchCar(carPlate))
		return true;
	else
		return false;
}

Car Garage::carMove(Stack& S1, Stack& S2, Stack& S3, string carPlate) { //suppose the car was in S1
	Car topCar = S1.getTopCar();
	int carsToMove = 0;
	while (topCar.getPlate() != carPlate) {// if not find the car, keep poping
		if (!S2.isFull()) { // push the popped car into S2 if S2 is not full
			S2.pushCarWithMoves(S1.popCarWithMoves());
		}
		else {//if S2 is full, push the popped car into S3
			S3.pushCarWithMoves(S1.popCarWithMoves());
		}
		topCar = S1.getTopCar();
		carsToMove++;
	}

	Car departedCar;
	if (topCar.getPlate() == carPlate) {//if the car was found, pop it
		departedCar = S1.popCar();
		cout << "D " << carPlate << "\t\t" << carPlate << " It was moved " << departedCar.getMoveCounter() << " times." << endl;
	}


	while (!S3.isEmpty()) { // pop all the cars in S3 and push them back to S1 until S3 empty
		S1.pushCarWithMoves(S3.popCarWithMoves());
		carsToMove--;
	}
	while (carsToMove > 0) { // pop the related cars and push them back to S1
		S1.pushCarWithMoves(S2.popCarWithMoves());
		carsToMove--;
	}

	return departedCar;
}

Car Garage::carDeparture(string carPlate) {
	if (this->searchLane(lane1, carPlate)) {//if the car was in lane1, pop it from lane1
		return this->carMove(lane1, lane2, street, carPlate);

	}
	else if (this->searchLane(lane2, carPlate)) {//if the car was in lane2, pop it from lane2
		return this->carMove(lane2, lane1, street, carPlate);
	}
	else { // if the car was not in lane1 or lane2
		cout << "D " << carPlate << "\t\t" << carPlate << " is not in the garage." << endl;
		return Car();
	}
}
void Garage::displayAll() { // display all the cars in the garage
	cout << "Lane1:" << endl;
	this->lane1.displayCars();
	cout << endl;
	cout << endl;

	cout << "Lane2:" << endl;
	this->lane2.displayCars();
	cout << endl;

}
