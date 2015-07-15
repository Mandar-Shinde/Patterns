
// Command Pattern

#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class CarCommands
{
public:
	virtual void execute()=0;
};


// Car know only 3 commands
class ToyCar
{
public:
	void Forward()
	{
		printf("\n   >>> \n");
	}
	void Stop()
	{
		printf("\n  ||||  \n");
	}
	void Backward()
	{
		printf("\n <<< \n");
	}
};

//
class CommandForward : public CarCommands
{
	ToyCar *_tc;
public:
	CommandForward(ToyCar *tc) :_tc(tc){}
	void execute()
	{
		printf("\n send Forward command\n");
		_tc->Forward();
	}	
};

class CommandStop : public CarCommands
{
	ToyCar *_tc;
public:
	CommandStop(ToyCar *tc) :_tc(tc){}
	void execute()
	{
		printf("\n send Stop command\n");
		_tc->Stop();
	}
};

class CommandBackward : public CarCommands
{
	ToyCar *_tc;
public:
	CommandBackward(ToyCar *tc) :_tc(tc){}
	void execute()
	{
		printf("\n send Backward command\n");
		_tc->Backward();
	}
};


class Remote
{
	CarCommands *_cmd;
public:
	void Execute(CarCommands* cmd)
	{
		_cmd = cmd;
		_cmd->execute();
	}	
};

int main()
{
	ToyCar* tc = new ToyCar;

	CommandForward* fwd = new CommandForward(tc);
	CommandBackward* bkw = new CommandBackward(tc);
	CommandStop *stp = new CommandStop(tc);

	Remote* remote = new Remote;

	remote->Execute(fwd);
	remote->Execute(fwd);
	remote->Execute(bkw);
	remote->Execute(stp);

	delete tc;

	getche();
	return 0;
}