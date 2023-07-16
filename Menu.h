#ifndef _Menu
#define _Menu

#include <iostream>

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


	}
	void showModifMenu() {

	}
	void showDeleteMenu() {

	}
	void showQueryMenu() {

	}
	void showBrowseMenu() {

	}
};


#endif