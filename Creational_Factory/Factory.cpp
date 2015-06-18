
//Singleton pattern is a design pattern that restricts the instantiation of a class to one object
// + introduces global state into an application
// + Single object
// 
// - some consider it an anti - pattern
// - Memory relesead after program exit

#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>

class Product
{
	std::string name;
public:
	Product(){};
	Product(std::string arg){ name = arg; }
	virtual void Job()=0;
};

class Element : public Product
{
public:
	Element(){}
	Element(std::string name) :Product(name)
	{
	}

	void Job()
	{
		printf(" Job of product 1  \n");
	}
};


class Production
{
public:
	Production() : _warehouse(0)
	{ 
		printf(" Production Started  \n");
	}
	
	void MakeProduct(char *name)
	{
		printf(" Making Product [%s] \n", name);		
		_totalProducts[_warehouse] = Element(name);
		_warehouse++;
	}

	int GetTotalProducts()
	{
		return _warehouse;
	}

private:
	int _warehouse;

	Element _totalProducts[10];
};

class Factory : public Production
{
public:
	Production* ProductionLine1;
	Factory()
	{
		ProductionLine1 = new Production();
	}
	void Produce(char* pname)
	{
		printf(" New Product to be created: [%s] \n", pname);
		ProductionLine1 ->MakeProduct(pname);
	}

	int TotalProduced()
	{		
		return ProductionLine1->GetTotalProducts();
	}

	
};

int main()
{
	Factory google;
	google.Produce(" Google Glass ");
	google.Produce(" Android ");

	printf("Total Products By Google: [%d]", google.TotalProduced());
	_getche();
}