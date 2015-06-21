#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>

// Observer pattern - Subject provides interface for observers to register and unregister themselves with the subject.
// Multiple observers can subscribe for notifications.
// Subject publishes the notifications Observer receives and do a perticular job.

class Observer  // like Detective
{
public:
	virtual ~Observer(){}
	virtual void onNotify(int) = 0;
};


class Subject // like owner or Godfather
{
public:
	virtual ~Subject(){}
	virtual void subscribe(Observer *ob)
	{
		mObservers.push_back(ob);
	}
	virtual void unsubscribe(Observer *ob)
	{
		for (int i = 0; i < mObservers.size(); i++)
		{
			if ((long)mObservers[i] == (long)ob)
				mObservers.erase(mObservers.begin() + i);
		}
	}
	virtual void notify(int ev)
	{
		for (int i = 0; i < mObservers.size(); i++)
			(mObservers[i])->onNotify(ev);
	}
private:
	std::vector<Observer *> mObservers;
};


class Detective : public Observer
{
public:
	explicit Detective(const std::string &name) :_name(name){}

	void onNotify(int ev)
	{
		switch (ev)
		{
		case 0: printf("  %s was ordered to MAKE deal \n", _name.c_str());
			break;
		case 1: printf("  %s was ordered to END deal \n", _name.c_str());
			break;
		default:  printf("  %s have no orders \n", _name.c_str());
			break;
		}
	}
private:
	std::string _name;
};

class Godfather : public Subject
{
public:
	enum Event{ EVENT_MAKE_DEAL, EVENT_END_DEAL };
};


int main()
{
	Detective velma("velma");
	Detective sherlock("sherlock");

	Godfather michael;

	// velma ans sherlock will make a deal for godfather
	michael.subscribe(&velma);
	michael.subscribe(&sherlock);
	michael.notify(Godfather::Event::EVENT_MAKE_DEAL);

	printf("\n\n   ... After some time..\n\n");

	// tell sherlock to end a deal
	printf("  velma continued..\n");
	michael.unsubscribe(&velma);
	michael.notify(Godfather::Event::EVENT_END_DEAL);

	_getche();
}