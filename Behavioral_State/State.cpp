
//
// State patterns abstract the ability for an object to change its behavior. 
//  STATE PATTERN [COMMON STATE]


#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////
//		CONTEXT
//////////////////////////////////////////////////////////////////////////

class Car
{

public:
	int gear;
	int accel;
	bool nitros;
	std::string name;

	Car(std::string s)
	{
		gear = 0;
		accel = 0;
		name = s;
		nitros = false;
	}
};

class ICarState
{
public:
	virtual void Acceleration(Car* op) = 0;
};

//////////////////////////////////////////////////////////////////////////
//		STATES IN THE CAR
//////////////////////////////////////////////////////////////////////////

class CruiseState : public ICarState
{
public: 
	 void Acceleration(Car* op)
	{
		op->gear = 5;
		op->accel = 60;
		op->nitros = false;
		printf(" Setting [%10s] to cruise mode for longer distance \n",op->name.c_str());
	}
};

class RacingState : public ICarState
{
public:
	void Acceleration(Car* op)
	{
		op->gear = 9;
		op->accel = 100;
		op->nitros = true;
		printf(" Setting [%10s] to racing mode for best speed \n", op->name.c_str());
	}
};

//////////////////////////////////////////////////////////////////////////

int main()
{
	printf("\n\n Setting mode to the car\n\n");	

	// CARS
	Car* audi = new Car("audi");
	Car* ferrari = new Car("ferrari");

	// MODES
	RacingState* race=new RacingState();
	CruiseState* cruise = new CruiseState();
	
	printf("\n ---- Setting both the car to race ----\n");
	// SETTING BOTH TO RACE MODE
	race->Acceleration(audi);
	race->Acceleration(ferrari);

	printf("\n  ---- Setting both the car to cruise  ----\n");
	// SETTING BOTH TO CRUISE MODE
	cruise->Acceleration(audi);
	cruise->Acceleration(ferrari);

	printf("\n  ---- Setting setting one of the car to race  ----\n");
	race->Acceleration(ferrari);

	_getche();
}