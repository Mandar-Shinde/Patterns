

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
		printf("\n SavingsAccount no [%d]", accno);
	}

	void info()
	{
		
	}	
};

class SavingsAccountPremium : public Account, public SavingsAccount
{
public:
	SavingsAccountPremium(int acc):SavingsAccount(acc)
	{
		printf("\n SavingsAccountPremium no [%d]", acc);
	}

	void info()
	{
		
	}
};
int main()
{
	SavingsAccountPremium* ob = new SavingsAccountPremium(10);
}
