#ifndef _Menu
#define _Menu

#include <iostream>

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