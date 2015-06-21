
//Prototype allows you to avoid expensive initialization routines when you construct objects that are very similar.
//The goal is to minimize the amount of work needed in creating new objects when the initialization routines are expensive.


#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>


class CPU
{
public:
	virtual ~CPU(){}
	virtual CPU* Clone()=0;
};

class INTEL_i3: public CPU
{
public:
	INTEL_i3(int ver,std::string name):_ver(ver),_name(name)
	{
		printf(" Creating i3 CPU \n");
	}

	virtual CPU* Clone()
	{
		printf("Clone-> ");
		return new INTEL_i3(3,"Clarkdale");		
	}
private:
	int _ver;
	std::string _name;
};

class INTEL_i5: public CPU
{
public:
	INTEL_i5(int ver,std::string name):_ver(ver),_name(name)
	{
		printf(" Creating i5 CPU \n");
	}

	virtual CPU* Clone()
	{
		printf("Clone-> ");
		return new INTEL_i5(5,"Lynnfield");
	}
private:
	int _ver;
	std::string _name;
};

class INTEL_i7: public CPU
{
public:
	INTEL_i7(int ver,std::string name):_ver(ver),_name(name)
	{
		printf(" Creating i7 CPU\n");	
	}

	virtual CPU* Clone()
	{
		printf("Clone-> ");
		return new INTEL_i7(7,"Bloomfield");
	}
private:
	int _ver;
	std::string _name;
};


class Prototype
{
public:
	Prototype(CPU* prototype): _prototype(prototype)
	{}

	CPU* MakePrototype()
	{
		return _prototype->Clone();
	}

private:
	CPU* _prototype;
};


int main()
{
	INTEL_i3* i3 = new INTEL_i3(3,"Clarkdale");
	INTEL_i5* i5 = new INTEL_i5(5,"Lynnfield");
	INTEL_i7* i7 = new INTEL_i7(7,"Bloomfield");
	Prototype* intel3 = new Prototype(i3);
	Prototype* intel5 = new Prototype(i5);
	Prototype* intel7 = new Prototype(i7);

	CPU* test1 = intel3->MakePrototype();
	CPU* test2 = intel5->MakePrototype();
	CPU* test3 = intel7->MakePrototype();
	CPU* test4 = intel3->MakePrototype();
	CPU* test5 = intel5->MakePrototype();

	getche();
}