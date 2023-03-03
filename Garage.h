#ifndef GARAGE_H
#define GARAGE_H
#include <iostream>
#include "Stack.h"

using namespace std;

class Garage {
private:
	Stack lane1;
	Stack lane2;
	Stack street;
public:
	Garage() {};
	void carArrival(Car car); // for the car arriving the garage, park it inside if it matches the condition
	bool searchLane(Stack lane, string carPlate); // search the exact lane which has the specified car 
	
	// suppose the dapartured car was located in S1, move the related cars and pop the specified car
	Car carMove(Stack& S1, Stack& S2, Stack& S3, string carPlate);

	Car carDeparture(string carPlate); // pop a car which should departure in any stack
	void displayAll(); // display all the cars in the garage

};

#endif