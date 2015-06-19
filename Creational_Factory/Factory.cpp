
//Factory Method - Define an interface for creating an object, but let subclasses decide which class to instantiate.
// + Client create an object from abstract class. But the subclass decides which class to instantiate. 
// + client delegate the decision of choosing the concrete class to create the object to one of the subclasses.
// 
// - We should specify the exact type of the object at compile time, so that the compiler can allocate memory for that specific type.
// If we are constructing derived object, the compiler calls the base class constructor first, and the derived class hasn't been initialized yet.
// This is the reason why we cannot call virtual methods from the constructor.

#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>

class Product
{
public:
	virtual void Info() = 0;
};

enum GoogleFactory{ YOUTUBE = 0, GMAIL, GLASS };

class Youtube : public Product
{
public:
	void Info()
	{
		printf(" Product Info : Youtube \n");
	}
};

class Gmail : public Product
{
public:
	void Info()
	{
		printf(" Product Info : Gmail  \n");
	}
};

class GoogleGlass : public Product
{
public:
	void Info()
	{
		printf(" Product Info : Google Glass  \n");
	}
};


class Factory
{
public:
	Factory() :_warehouse(0){}
	Product* MakeProduct(int id)
	{
		switch (id)
		{
		case YOUTUBE:
			_warehouse++;
			return new Youtube();
			break;
		case GMAIL:
			_warehouse++;
			return new Gmail();
			break;
		case GLASS:
			_warehouse++;
			return new GoogleGlass();
			break;
		default:
			break;
		}
	}

	int GetTotalProducts()
	{
		return _warehouse;
	}

private:
	int _warehouse;
};


int main()
{
	Factory *google = new Factory;
	Product *prod;

	prod = google->MakeProduct(YOUTUBE);
	prod->Info();
	prod = google->MakeProduct(GMAIL);
	prod->Info();
	prod = google->MakeProduct(GLASS);
	prod->Info();
	prod = google->MakeProduct(GMAIL);
	prod->Info();


	printf("\n\n Total Products By Google: [%d]", google->GetTotalProducts());
	_getche();
}