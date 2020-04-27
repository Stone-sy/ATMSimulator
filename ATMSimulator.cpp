/*
	时间：2020/04/14
	姓名：石莹
	学号：2017301610284
	内容：*** 个人考核项目 ***

	ATM机仿真
	ATMSimulator

	包括：储蓄账户类     SavingsAccount
	      银行卡类       BankCard
		  银行代理类     BankAgent
		  ATM机类        ATM
	
	功能：  1 查询
			2 存款
			3 取款
			4 修改密码
			5 写入文件
			6 退出
*/


#include<iostream>
#include<time.h>
using namespace std;

#include "BankAgent.h"
#include"ATM.h"
int main()
{
	while (true)
	{
		ATM atm;
		int num = 0;
		string id, pwd;
		cout << "\n\n**************************************" << endl;
		cout << "             ATM取款机\n" << endl;
		cout << "    本取款机 24h 营业，欢迎您的使用！" << endl;
		cout << "**************************************" << endl;
		cout << "            请插入银行卡..." << endl << endl;
		cout << "      请输入银行卡卡号：";
		cin >> id;
		num = atm.findCard(id);
		while (num == -1)
		{
			cout << "      此卡号不存在，请重新输入。\n" << endl;
			cout << "      请输入银行卡卡号：";
			cin >> id;
			num = atm.findCard(id);
		}

		BankCard bc;
		BankAgent ba = atm.getBA();
		bc = atm.getCard(num);
		cout << "      请输入密码：";
		cin >> pwd;
		while (!ba.authenticate(bc, pwd))
		{
			cout << "      密码错误，请重新输入。" << endl;
			cout << "      请输入密码：";
			cin >> pwd;
		}
		cout << "      密码正确！" << endl;
		SavingsAccount curSA = ba.getBindedSA(bc);

		cout << "------------------------------------" << endl;
		cout << "*********** 操作菜单 ***********" << endl;
		cout << "1 查询" << endl;
		cout << "2 存款" << endl;
		cout << "3 取款" << endl;
		cout << "4 修改密码" << endl;
		cout << "5 写入文件" << endl;
		cout << "6 退出" << endl;


		int action = 0;
		double money;
		while (action!=6)
		{
			cout << "------------------------------------" << endl;
			cout << "      请选择您的服务：";
			cin >> action;
			if (action < 1 || action>6)
			{
				cout << "不存在此项服务，请您重新输入：" << endl;
				continue;
			}

			switch (action)
			{
			case 1:
			{
				cout << "      < 查询 >" << endl;
				cout << "\n      储户姓名：" << curSA.getName() << "\n      当前余额：" << curSA.getBalance() << endl;
				break;
			}
			case 2:
			{
				cout << "      < 存款 >" << endl;
				cout << "      请输入存款金额：";
				cin >> money;
				curSA.deposit(money);
				cout << "\n      存款" << money << "。" << endl;
				cout << "\n      当前余额：" << curSA.getBalance() << endl;
				break;
				atm.setATM(curSA, bc, ba, num);
			}
			case 3:
			{
				cout << "      < 取款 >" << endl;
				cout << "      请输入取款金额：";
				cin >> money;
				if (curSA.withdraw(money))
				{
					cout << "\n      取款" << money << "。" << endl;
					cout << "\n      当前余额：" << curSA.getBalance() << endl;
				}
				else
				{
					cout << "      余额不足！" << endl;
				}
				atm.setATM(curSA, bc, ba, num);
				break;
			}
			case 4:
			{
				cout << "      < 修改密码 >" << endl;
				string new_pwd, check_pwd;
				cout << "      请输入新的密码（限数字和字母）：";
				cin >> new_pwd;
				while (!ba.checkPWD(new_pwd))
				{
					cout << "      您输入的密码不合法，请重新输入！" << endl;
					cout << "      请输入新的密码（限数字和字母）：";
					cin >> new_pwd;
				}

				cout << "      请再次确认您的新密码：";
				cin >> check_pwd;
				while (check_pwd != new_pwd)
				{
					cout << "      您两次输入的密码不一致，请重新输入！\n" << endl;
					cout << "      请输入新的密码：";
					cin >> new_pwd;
					cout << "      请再次确认您的新密码：";
					cin >> check_pwd;
				}
				cout << "      修改成功！" << endl;
				ba.setCardPWD(bc, new_pwd);
				atm.setATM(curSA, bc, ba,num);
				break;
			}
			case 5:
			{
				cout << "      < 写入文件 >" << endl;
				atm.write2file();
				cout << "      本ATM取款机的银行卡信息已全部写入Bank.txt。" << endl;
				break;
			}
			default:
			{
				cout << "      < 退出 >" << endl;
				cout << "      三秒后跳转到初始界面..." << endl;
				time_t start, end;
				start = time(NULL);
				do {
					end = time(NULL);
				} while (difftime(end, start) < 3);
				system("cls");
				break;
			}
			}
		}
	}
	
	system("pause");
	return 0;

}
