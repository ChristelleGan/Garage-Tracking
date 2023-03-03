#ifndef STACK_H
#define STACK_H
#include<string>
#include<iostream>
#include "Car.h"

using namespace std;

class Stack {
private:
	Car cars[10];
	int numOfCars = 0;
	int maxLength = 10;
public:
	Stack();
	int getNumOfCars();
	bool isFull(); // check if the stack is full
	bool isEmpty(); // check if the stack is empty
	void pushCar(Car car); //push a car without incrementing the number of moves, will be used for the first time arriving
	void pushCarWithMoves(Car car); // push a car with incrementing the number of moves, will be used for the cars moving between garage and street
	Car popCar(); // pop a car without incrementing the number of moves, will be used for the specified car leaving
	Car popCarWithMoves(); //pop a car with incrementing the number of moves, will be used for the cars moving between garage and street 
	bool searchCar(string carPlate); // search if a car in the stack
	Car getTopCar(); // get the top car in the stack
	void displayCars(); //display all the cars' plates in the stack
};

#endif
