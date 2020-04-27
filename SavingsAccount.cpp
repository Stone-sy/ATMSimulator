#include "SavingsAccount.h"

//存款
bool SavingsAccount::deposit(double money)
{
	if (money > 0.0)
	{
		m_Balance += money;
		return true;
	}
	else
		return false;
}

//取款
bool SavingsAccount::withdraw(double money)
{
	if (m_Balance > (money + 10))  //账上至少余10元钱
	{
		m_Balance -= money;
		return true;
	}
	else
		return false;
}