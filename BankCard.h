/*
	BankCard
	���п�
*/

#pragma once
#ifndef _BANKCARD_
#define _BANKCARD_

#include<string>
#include "SavingsAccount.h"

using std::string;

class BankAgent;
class BankCard
{
private:
	string m_ID;
	string m_PWD;
	bool m_Empty;   //��һ�ſտ���δ�󶨴����˻�
	SavingsAccount m_SA;

public:
	BankCard() {};
	BankCard(string id);

	string getID() const { return m_ID; }
	string getPWD() const { return m_PWD; }
	friend BankAgent;
};

#endif