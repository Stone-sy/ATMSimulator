#pragma once
#include "BankCard.h"

class BankAgent
{
public:
	//�����п��ʹ����˻�
	bool bindSA2Card(const SavingsAccount &sa, BankCard &card);

	//�������п�����Ȩ����
	bool setCardPWD(BankCard &card, string pwd);

	//��֤����
	bool authenticate(const BankCard &card, string pwd);
	
	//��ȡ�󶨵Ĵ����˻�
	SavingsAccount getBindedSA(const BankCard &card);

	//��������Ƿ����Ҫ��
	bool checkPWD(const string pwd);

};