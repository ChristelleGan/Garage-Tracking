#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>

using namespace std;

class Car {
private:
	string plate;
	int moveCounter;
public:
	Car();
	void setPlate(string carPlate);
	string getPlate();
	int getMoveCounter();
	void incrementMoveCounter();
};
#endif