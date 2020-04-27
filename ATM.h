/*
	ATM类
1.准备数据
定义储蓄账户数组，保存若干账户数据。
定义银行卡数组，保存若干银行卡数据。
定义银行代理，把每张银行卡关联一个储蓄账户。
2.模拟ATM机提供24小时服务（无限循环）
 （1）提示插入银行卡
– 用户输入银行卡卡号和密码
 （2）卡号和密码验证通过后开始提供服务
– 显示操作菜单（查询、存款、取款、退出）
– 根据用户的选择执行对应的功能
– 用户选择“退出”则结束服务
 （3）吐出银行卡，进入下一轮循环


	时间：2020/04/14
	姓名：石莹
	学号：2017301610284
*/

#pragma once
#ifndef _ATM_H_
#define _ATM_H_

#include"SavingsAccount.h"
#include"BankAgent.h"
#include"BankCard.h"

#include<iostream>
#include<fstream>
using namespace std;

class ATM
{
private:
	SavingsAccount m_sa[20];
	BankCard m_bc[20];
	BankAgent m_ba;
	int m_number;     //ATM机中有number个账户。

public:
	ATM()
	{
		//读取文件
		ifstream file;
		file.open("Bank.txt",ios::in);
		string id, name, pwd;
		double money;
		int i = 0;
		cout << "（ATM 从 Bank.txt 中读取以下数据。）" << endl;
		cout << "（您可以选择任意一个账户，从而模拟您的操作。）\n" << endl;
		cout << " id, pwd  ,  name  ,money " << endl;
		while (file >> id >> pwd >> name >> money)
		{
			cout << id << "," << pwd << "," << name << "," << money << endl;
			m_sa[i] = SavingsAccount(name, money);
			m_bc[i] = BankCard(id);
			m_ba.bindSA2Card(m_sa[i], m_bc[i]);
			m_ba.setCardPWD(m_bc[i], pwd);
			i++;
		}
		m_number = i;
		file.close();
		/*
		//初始化，直接给ATM机赋n个账户和卡
		m_sa[0] = SavingsAccount("aaa", 1000);
		m_sa[1] = SavingsAccount("bbb", 2000);
		m_sa[2] = SavingsAccount("ccc", 3000);
		
		m_bc[0] = BankCard("123");
		m_bc[1] = BankCard("456");
		m_bc[2] = BankCard("789");

		m_ba.bindSA2Card(m_sa[0], m_bc[0]);
		m_ba.bindSA2Card(m_sa[1], m_bc[1]);
		m_ba.bindSA2Card(m_sa[2], m_bc[2]);

		m_ba.setCardPWD(m_bc[0], "111111");
		m_ba.setCardPWD(m_bc[1], "222222");
		m_ba.setCardPWD(m_bc[2], "666666");
		*/
	}

	BankAgent getBA()
	{
		return m_ba;
	}

	int findCard(string id)    //ATM机中是否有这个id号
	{
		int num = -1;
		
		for (int i = 0; i < m_number; i++)
		{
			if (id== m_bc[i].getID())
				num = i;
		}
		return num;
	}

	BankCard getCard(int num)   //根据num返回一张卡
	{
		return m_bc[num];
	}

	void write2file()
	{
		ofstream outfile;
		outfile.open("Bank.txt", ios::out);
		string id, pwd, name;
		double money;
		for (int i = 0;i<m_number; i++)
		{
			id = m_bc[i].getID();
			pwd = m_bc[i].getPWD();
			name = m_sa[i].getName();
			money = m_sa[i].getBalance();
			outfile << id << " " << pwd << " " << name << " " << money << " " << endl;
		}
		outfile.close();
	}

	void setATM(SavingsAccount &sa, BankCard &bc, BankAgent &ba,int num)
	{
		m_ba = ba;
		m_bc[num] = bc;
		m_sa[num] = sa;
		m_ba.bindSA2Card(m_sa[num], m_bc[num]);
	}

	void setCard(BankCard &card,string pwd,int num)
	{
		m_ba.setCardPWD(m_bc[num], pwd);
		m_ba.bindSA2Card(m_sa[num], m_bc[num]);
	}

	friend BankCard;
};



#endif // !_ATM_H_
