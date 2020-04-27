#pragma once
#include "BankCard.h"

class BankAgent
{
public:
	//绑定银行卡和储蓄账户
	bool bindSA2Card(const SavingsAccount &sa, BankCard &card);

	//设置银行卡地授权密码
	bool setCardPWD(BankCard &card, string pwd);

	//验证密码
	bool authenticate(const BankCard &card, string pwd);
	
	//获取绑定的储蓄账户
	SavingsAccount getBindedSA(const BankCard &card);

	//检查密码是否符合要求
	bool checkPWD(const string pwd);

};