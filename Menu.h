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
		cout << "   【旅馆信息备案系统】   " << endl;
		cout << "------------------------" << endl;
	}
	void showMainMenu() {
		cout << " 1. 增加  " << endl;
		cout << " 2. 修改  " << endl;
		cout << " 3. 删除  " << endl;
		cout << " 4. 查询  " << endl;
		cout << " 5. 浏览  " << endl;
		cout << " 0. 退出  " << endl;


	}
	void showFooterMenu() {
		cout << "-------------------------" << endl;
		cout << "请选择操作：";
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
		cout << " 旅馆编号 : " << id << endl;
		cout << " 旅馆名称 : ";
		cin >> name;
		cout << " 城市名称 : ";
		cin >> city;
		cout << " 标准间数量 : ";
		cin >> bNum;
		cout << " 标准间价格 : ";
		cin >> bPri;
		cout << " 豪华间数量 : ";
		cin >> hNum;
		cout << " 豪华间价格 : ";
		cin >> hPri;

		char ch;
		cout << " 你是否保存数据(y/n)?:";
		cin >> ch;
		if (toupper(ch) == 'Y') {
			Hotel temp;
			temp.setData(id, name, city, bNum, bPri, hNum, hPri);
			file.AddHotel(temp);
			cout << " 数据添加成功 " << endl;
		}



	}
	void showModifMenu() {
		File file;
		Hotel temp;

		int id;
		char ch;
		cout << "输入旅馆编号: ";
		cin >> id;
		temp = file.getHotelByID(id);
		if (temp.getID() > 0)
		{
			cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
			cout << "标准间数量" << "\t" << "标准间价格" << endl;
			temp.showHotel();

			cout << "是否确认修改信息(y/n)?";
			cin >> ch;


			char city[20];
			char name[50];
			int bNum;
			int bPri;
			int hNum;
			int hPri;

			if (toupper(ch) == 'Y')
			{

				cout << " 旅馆名称 : ";
				cin >> name;
				cout << " 城市名称 : ";
				cin >> city;
				cout << " 标准间数量 : ";
				cin >> bNum;
				cout << " 标准间价格 : ";
				cin >> bPri;
				cout << " 豪华间数量 : ";
				cin >> hNum;
				cout << " 豪华间价格 : ";
				cin >> hPri;

				cout << " 你是否保存数据(y/n)?:";
				cin >> ch;
				if (toupper(ch) == 'Y') {
					temp.setData(id, name, city, bNum, bPri, hNum, hPri);
					file.AddHotel(temp);
					cout << " 数据添加成功 " << endl;
				}
			}
		}
		else
		{
			cout << "输入的编号不存在" << endl;
		}

	}
	void showDeleteMenu() {

		File file;
		Hotel temp;

		int id;
		char ch;
		cout << "输入旅馆编号: ";
		cin >> id;
		temp = file.getHotelByID(id);

		if (temp.getID() > 0)
		{
			cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
			cout << "标准间数量" << "\t" << "标准间价格" << endl;
			temp.showHotel();

			cout << "是否确认删除信息(y/n)?";
			cin >> ch;

			if (toupper(ch) == 'Y')
			{
				file.DeleteHotel(id);
				cout << "数据修改成功" << endl;
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
			cout << " 1. 增加  " << endl;
			cout << " 2. 修改  " << endl;
			cout << " 3. 删除  " << endl;
			cout << " 4. 查询  " << endl;
			cout << "         1. 按编号  " << endl;
			cout << "         2. 按名称  " << endl;
			cout << "         3. 按城市  " << endl;
			cout << "         0. 返回  " << endl;
			cout << " 5. 浏览  " << endl;
			cout << " 0. 退出  " << endl;

			showFooterMenu();

			cin >> ch;

			switch (ch)
			{
			case '0':
				return ;
			case '1':
				cout << "输入旅馆编号: ";
				cin >> id;
				temp = file.getHotelByID(id);

				if (temp.getID() > 0)
				{
					cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
					cout << "标准间数量" << "\t" << "标准间价格" << endl;
					temp.showHotel();
				}
				break;
			case '2':
				cout << "输入旅馆名称: ";
				cin >> Name;
				temp = file.getHotelByName(Name);

				if (temp.getID() > 0)
				{
					cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
					cout << "标准间数量" << "\t" << "标准间价格" << endl;
					temp.showHotel();
				}
				break;
			case '3':
				cout << "输入城市名称: ";
				cin >> City;
				temp = file.getHotelByName(Name);

				if (temp.getID() > 0)
				{
					cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
					cout << "标准间数量" << "\t" << "标准间价格" << endl;
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
			cout << "编号" << "\t" << "旅馆名称" << "\t" << "城市" << "\t" << "豪华间数量" << "\t" << "豪华间价格" << "\t";
			cout << "标准间数量" << "\t" << "标准间价格" << endl;
			for (int i = 0; i < count; i++)
			{
				(all + i)->showHotel();
			}
		}
		else
		{
			cout << "无旅馆信息浏览" << endl;
		}
	}
};


#endif