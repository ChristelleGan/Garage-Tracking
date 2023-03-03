#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Garage.h"
#include "Stack.h"
#include "Car.h"

using namespace std;

int main() {
	Car car;
	Garage garage;
	string carPlate;

	ifstream infile; //read from the file
	//infile.open("/Users/ganxi/Documents/CSI/CSC326/Lab3/ParkingGarage.txt");
	infile.open("TextFile1.txt");

	if (!infile) {
		cout << " Error...unable to open the file." << endl;
	}

	string line;
	char status;
	while (getline(infile, line))
	{
		status = line[0];

		carPlate = line.substr(2, 7); // get the plate number by substring the file liens
		car.setPlate(carPlate); // set the plate to a car

		if (status == 'A' || status == 'a') {
			garage.carArrival(car);
		}
		else if (status == 'D' || status == 'd') {
			Car departedCar = garage.carDeparture(carPlate);
		}
		else {
			cout << line << "\t\t" << "Invalid car status..." << endl;
		}

		
	}
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	garage.displayAll();

	return 0;
}
