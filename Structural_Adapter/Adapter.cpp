

#include <stdio.h>
#include <conio.h>

class Account
{
public:
	virtual void info() = 0;
};

class SavingsAccount : public Account
{
	int accno;
public:
	SavingsAccount(int acc)
	{
		accno = acc;
	}

	void info()
	{
		printf("\n acc no [%d]",accno);
	}	
};

class SavingsAccountPremium : public Account, public SavingsAccount
{
public:
	SavingsAccountPremium(int acc):SavingsAccount(acc)
	{
	}

	void info()
	{
		printf("\n acc no 2");
	}
};
int main()
{
	SavingsAccountPremium* ob = new SavingsAccountPremium(10);
	ob->info();

}
