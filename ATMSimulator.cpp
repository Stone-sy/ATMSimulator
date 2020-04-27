/*
	ʱ�䣺2020/04/14
	������ʯӨ
	ѧ�ţ�2017301610284
	���ݣ�*** ���˿�����Ŀ ***

	ATM������
	ATMSimulator

	�����������˻���     SavingsAccount
	      ���п���       BankCard
		  ���д�����     BankAgent
		  ATM����        ATM
	
	���ܣ�  1 ��ѯ
			2 ���
			3 ȡ��
			4 �޸�����
			5 д���ļ�
			6 �˳�
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
		cout << "             ATMȡ���\n" << endl;
		cout << "    ��ȡ��� 24h Ӫҵ����ӭ����ʹ�ã�" << endl;
		cout << "**************************************" << endl;
		cout << "            ��������п�..." << endl << endl;
		cout << "      ���������п����ţ�";
		cin >> id;
		num = atm.findCard(id);
		while (num == -1)
		{
			cout << "      �˿��Ų����ڣ����������롣\n" << endl;
			cout << "      ���������п����ţ�";
			cin >> id;
			num = atm.findCard(id);
		}

		BankCard bc;
		BankAgent ba = atm.getBA();
		bc = atm.getCard(num);
		cout << "      ���������룺";
		cin >> pwd;
		while (!ba.authenticate(bc, pwd))
		{
			cout << "      ����������������롣" << endl;
			cout << "      ���������룺";
			cin >> pwd;
		}
		cout << "      ������ȷ��" << endl;
		SavingsAccount curSA = ba.getBindedSA(bc);

		cout << "------------------------------------" << endl;
		cout << "*********** �����˵� ***********" << endl;
		cout << "1 ��ѯ" << endl;
		cout << "2 ���" << endl;
		cout << "3 ȡ��" << endl;
		cout << "4 �޸�����" << endl;
		cout << "5 д���ļ�" << endl;
		cout << "6 �˳�" << endl;


		int action = 0;
		double money;
		while (action!=6)
		{
			cout << "------------------------------------" << endl;
			cout << "      ��ѡ�����ķ���";
			cin >> action;
			if (action < 1 || action>6)
			{
				cout << "�����ڴ�����������������룺" << endl;
				continue;
			}

			switch (action)
			{
			case 1:
			{
				cout << "      < ��ѯ >" << endl;
				cout << "\n      ����������" << curSA.getName() << "\n      ��ǰ��" << curSA.getBalance() << endl;
				break;
			}
			case 2:
			{
				cout << "      < ��� >" << endl;
				cout << "      ���������";
				cin >> money;
				curSA.deposit(money);
				cout << "\n      ���" << money << "��" << endl;
				cout << "\n      ��ǰ��" << curSA.getBalance() << endl;
				break;
				atm.setATM(curSA, bc, ba, num);
			}
			case 3:
			{
				cout << "      < ȡ�� >" << endl;
				cout << "      ������ȡ���";
				cin >> money;
				if (curSA.withdraw(money))
				{
					cout << "\n      ȡ��" << money << "��" << endl;
					cout << "\n      ��ǰ��" << curSA.getBalance() << endl;
				}
				else
				{
					cout << "      ���㣡" << endl;
				}
				atm.setATM(curSA, bc, ba, num);
				break;
			}
			case 4:
			{
				cout << "      < �޸����� >" << endl;
				string new_pwd, check_pwd;
				cout << "      �������µ����루�����ֺ���ĸ����";
				cin >> new_pwd;
				while (!ba.checkPWD(new_pwd))
				{
					cout << "      ����������벻�Ϸ������������룡" << endl;
					cout << "      �������µ����루�����ֺ���ĸ����";
					cin >> new_pwd;
				}

				cout << "      ���ٴ�ȷ�����������룺";
				cin >> check_pwd;
				while (check_pwd != new_pwd)
				{
					cout << "      ��������������벻һ�£����������룡\n" << endl;
					cout << "      �������µ����룺";
					cin >> new_pwd;
					cout << "      ���ٴ�ȷ�����������룺";
					cin >> check_pwd;
				}
				cout << "      �޸ĳɹ���" << endl;
				ba.setCardPWD(bc, new_pwd);
				atm.setATM(curSA, bc, ba,num);
				break;
			}
			case 5:
			{
				cout << "      < д���ļ� >" << endl;
				atm.write2file();
				cout << "      ��ATMȡ��������п���Ϣ��ȫ��д��Bank.txt��" << endl;
				break;
			}
			default:
			{
				cout << "      < �˳� >" << endl;
				cout << "      �������ת����ʼ����..." << endl;
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
