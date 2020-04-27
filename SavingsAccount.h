#pragma once
/*
	
	class SavingsAccount
	银行储蓄账户
	姓名：石莹
	学号：2017301610284
	时间：2020/04/07

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
	
	//存款
	bool deposit(double money);
	//取款
	bool withdraw(double money);

	friend BankAgent;
};

#endif