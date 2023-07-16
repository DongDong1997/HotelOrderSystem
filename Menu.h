#ifndef _Menu
#define _Menu

#include <iostream>
#include <string>
#include "File.h"
#include "Hotel.h"

using namespace std;
class Menu
{
public:
	void showHeaderMenu() {
		cout << "   ���ù���Ϣ����ϵͳ��   " << endl;
		cout << "------------------------" << endl;
	}
	void showMainMenu() {
		cout << " 1. ����  " << endl;
		cout << " 2. �޸�  " << endl;
		cout << " 3. ɾ��  " << endl;
		cout << " 4. ��ѯ  " << endl;
		cout << " 5. ���  " << endl;
		cout << " 0. �˳�  " << endl;


	}
	void showFooterMenu() {
		cout << "-------------------------" << endl;
		cout << "��ѡ�������";
	}
	void showAddMenu() {
		int id;
		char city[20];
		char name[50];
		int bNum;
		int bPri;
		int hNum;
		int hPri;

		File file;
		id = file.getAutoID();
		cout << " �ùݱ�� : " << id << endl;
		cout << " �ù����� : ";
		cin >> name;
		cout << " �������� : ";
		cin >> city;
		cout << " ��׼������ : ";
		cin >> bNum;
		cout << " ��׼��۸� : ";
		cin >> bPri;
		cout << " ���������� : ";
		cin >> hNum;
		cout << " ������۸� : ";
		cin >> hPri;

		char ch;
		cout << " ���Ƿ񱣴�����(y/n)?:";
		cin >> ch;
		if (toupper(ch) == 'Y') {
			Hotel temp;
			temp.setData(id, name, city, bNum, bPri, hNum, hPri);
			file.AddHotel(temp);
			cout << " ������ӳɹ� " << endl;
		}



	}
	void showModifMenu() {
		File file;
		Hotel temp;

		int id;
		char ch;
		cout << "�����ùݱ��: ";
		cin >> id;
		temp = file.getHotelByID(id);
		if (temp.getID() > 0)
		{
			cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
			cout << "��׼������" << "\t" << "��׼��۸�" << endl;
			temp.showHotel();

			cout << "�Ƿ�ȷ���޸���Ϣ(y/n)?";
			cin >> ch;


			char city[20];
			char name[50];
			int bNum;
			int bPri;
			int hNum;
			int hPri;

			if (toupper(ch) == 'Y')
			{

				cout << " �ù����� : ";
				cin >> name;
				cout << " �������� : ";
				cin >> city;
				cout << " ��׼������ : ";
				cin >> bNum;
				cout << " ��׼��۸� : ";
				cin >> bPri;
				cout << " ���������� : ";
				cin >> hNum;
				cout << " ������۸� : ";
				cin >> hPri;

				cout << " ���Ƿ񱣴�����(y/n)?:";
				cin >> ch;
				if (toupper(ch) == 'Y') {
					temp.setData(id, name, city, bNum, bPri, hNum, hPri);
					file.AddHotel(temp);
					cout << " ������ӳɹ� " << endl;
				}
			}
		}
		else
		{
			cout << "����ı�Ų�����" << endl;
		}

	}
	void showDeleteMenu() {

		File file;
		Hotel temp;

		int id;
		char ch;
		cout << "�����ùݱ��: ";
		cin >> id;
		temp = file.getHotelByID(id);

		if (temp.getID() > 0)
		{
			cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
			cout << "��׼������" << "\t" << "��׼��۸�" << endl;
			temp.showHotel();

			cout << "�Ƿ�ȷ��ɾ����Ϣ(y/n)?";
			cin >> ch;

			if (toupper(ch) == 'Y')
			{
				file.DeleteHotel(id);
				cout << "�����޸ĳɹ�" << endl;
			}
		}
	}

	void showQueryMenu() {

		char ch;
		int id;
		char Name[50];
		char City[20];

		File file;
		Hotel temp;

		do
		{   
			showHeaderMenu();
			cout << " 1. ����  " << endl;
			cout << " 2. �޸�  " << endl;
			cout << " 3. ɾ��  " << endl;
			cout << " 4. ��ѯ  " << endl;
			cout << "         1. �����  " << endl;
			cout << "         2. ������  " << endl;
			cout << "         3. ������  " << endl;
			cout << "         0. ����  " << endl;
			cout << " 5. ���  " << endl;
			cout << " 0. �˳�  " << endl;

			showFooterMenu();

			cin >> ch;

			switch (ch)
			{
			case '0':
				return ;
			case '1':
				cout << "�����ùݱ��: ";
				cin >> id;
				temp = file.getHotelByID(id);

				if (temp.getID() > 0)
				{
					cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
					cout << "��׼������" << "\t" << "��׼��۸�" << endl;
					temp.showHotel();
				}
				break;
			case '2':
				cout << "�����ù�����: ";
				cin >> Name;
				temp = file.getHotelByName(Name);

				if (temp.getID() > 0)
				{
					cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
					cout << "��׼������" << "\t" << "��׼��۸�" << endl;
					temp.showHotel();
				}
				break;
			case '3':
				cout << "�����������: ";
				cin >> City;
				temp = file.getHotelByName(Name);

				if (temp.getID() > 0)
				{
					cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
					cout << "��׼������" << "\t" << "��׼��۸�" << endl;
					temp.showHotel();
				}
				break;
			}
		} while (1);
		
		system("pause");

	}
	void showBrowseMenu() {
		File file;
		Hotel* all;

		int count = file.getHotelCount();

		if (count > 0)
		{
			all = file.getAllHotels();
			cout << "���" << "\t" << "�ù�����" << "\t" << "����" << "\t" << "����������" << "\t" << "������۸�" << "\t";
			cout << "��׼������" << "\t" << "��׼��۸�" << endl;
			for (int i = 0; i < count; i++)
			{
				(all + i)->showHotel();
			}
		}
		else
		{
			cout << "���ù���Ϣ���" << endl;
		}
	}
};


#endif