
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

class SingletonClass
{
	std::string m_name;
	static SingletonClass *s_instance;
	SingletonClass(std::string name)
	{
		m_name = name;
	}
public:
	static SingletonClass *get_instance()
	{
		if (!s_instance)
			s_instance = new SingletonClass("SingletonClass");
		return s_instance;
	}

	std::string sayHello()
	{
		return  "and my name is "+m_name ;
	}
};


// Allocating and initializing 
//The pointer is being allocated - not the object.
SingletonClass *SingletonClass::s_instance = 0;

int main()
{
	printf("Hi i am Main,  [%s]", SingletonClass::get_instance()->sayHello().c_str());
	_getche();
}