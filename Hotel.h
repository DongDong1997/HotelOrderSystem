#ifndef _Hotel
#define _Hotel

#include <iostream>
using namespace std;
class Hotel
{
private:
	int id;
	char name[50];
	char city[20];

	int bNum;
	int bPri;
	int hNum;
	int hPri;

public:
	void setData(int i, char* n, char* ct, int bn, int bp, int hn, int hp) {

		id = i;
		*name = *n;
		*city = *ct;
		hNum = hn;
		bPri = hp;
		hNum = hn;
		hPri = hp;

	}

	void setID(int i) {
		id = i;
	}
	int getID() {
		return id;
	}
	void setName(char* n) {
		*name = *n;
	}
	char* getName() {
		return name;
	}
	void setCity(char* ct) {
		*city = *ct;
	}
	char* getCity() {
		return city;
	}
	void sethPrice(int HPri) {
		hPri = HPri;
	}
	int gethPrice() {
		return hPri;
	}
	void sethNum(int HNum) {
		hNum = HNum;
	}
	int gethNum() {
		return hNum;
	}
	void setbPrice(int BPri) {
		bPri = BPri;
	}
	int getbPrice() {
		return bPri;
	}
	void setbNum(int BNum) {
		bNum = BNum;
	}
	int getbNum() {
		return bNum;
	}

};

#endif