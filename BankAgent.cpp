/*
	BankAgent
	银行卡代理
*/

#include"BankAgent.h"

bool BankAgent::bindSA2Card(const SavingsAccount &sa, BankCard &card)
{
	if (!card.m_Empty)
	{
		return false;
	}
	card.m_SA = sa;
	card.m_Empty = false;
	return true;
}

bool BankAgent::setCardPWD(BankCard &card, string pwd)
{
	if (!checkPWD(pwd)) return false;
	
	card.m_PWD = pwd;
	return true;
}

bool BankAgent::authenticate(const BankCard &card, string pwd)
{
	return (card.m_PWD == pwd);
}

SavingsAccount BankAgent::getBindedSA(const BankCard &card)
{
	return card.m_SA;
}

bool BankAgent::checkPWD(const string pwd)
{
	int len = pwd.length();
	if (len<6||len==0) return false;

	bool valid = true;
	for (int i = 0; i < len; i++)
	{
		char c = pwd[i];
		if (!(c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9'))
		{
			valid = false;
			break;
		}
	}
	return valid;
}