#pragma once
/*
	
	class SavingsAccount
	���д����˻�
	������ʯӨ
	ѧ�ţ�2017301610284
	ʱ�䣺2020/04/07

*/
#ifndef _SAVINGSACCOUNT_
#define _SAVINGSACCOUNT_

#include<string>
using std::string;

class BankAgent;
class SavingsAccount
{
private:
	string m_Name;
	double m_Balance;

public:
	SavingsAccount(string name = "none", double balance = 0.0) :m_Name(name), m_Balance(balance) {}

	string getName() const { return m_Name; }
	double getBalance() const { return m_Balance; }
	
	//���
	bool deposit(double money);
	//ȡ��
	bool withdraw(double money);

	friend BankAgent;
};

#endif