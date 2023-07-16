#ifndef _File
#define _File

#include <fstream>

#include "Hotel.h"

#define FileName "hotal.dat"

class File
{
public :
	int getHotelCount()
	{
		int count = 0;
		return count;
	}
	int getAutoID()
	{
		int id = 1;		
		Hotel temp;
		fstream f(FileName, ios::in);
		if (f.is_open()) {
			while (f.read((char*)&temp, sizeof(Hotel)))
			{

			}			
			f.close();

			if (temp.getID() > 0) {
				id = temp.getID() + 1;
			}
		}
		else {
			cout << "文件打开错误" << endl;
		}
		return id;
	}
	Hotel* getAllHotels()
	{
		Hotel* temp;
		return temp;
	}
	Hotel getHotelByID(int id)
	{
		Hotel temp;
		return temp;
	}
	Hotel getHotelByName(int id)
	{
		Hotel temp;
		return temp;
	}
	Hotel getHotelByCity(int id)
	{
		Hotel temp;
		return temp;
	}

	void AddHotel(Hotel &obj)
	{
		fstream f(FileName, ios::out | ios::app);
		f.write((char*)&obj, sizeof(Hotel));
		f.close();

	}
	void UpdateHotel(Hotel& obj)
	{

	}
	void DeleteHotel(int id)
	{

	}
};

#endif