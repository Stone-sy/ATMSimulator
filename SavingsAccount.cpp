#include "SavingsAccount.h"

//���
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

//ȡ��
bool SavingsAccount::withdraw(double money)
{
	if (m_Balance > (money + 10))  //����������10ԪǮ
	{
		m_Balance -= money;
		return true;
	}
	else
		return false;
}