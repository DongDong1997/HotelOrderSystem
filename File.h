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
		Hotel temp;
		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel)))
		{
			count++;
		}
		f.close();
		return count;
	}

	int getAutoID()
	{
		int id = 1;		
		Hotel temp;
		fstream f(FileName, ios::in);
		
		while (f.read((char*)&temp, sizeof(Hotel)))
		{

		}			
		f.close();

		if (temp.getID() > 0) {
			id = temp.getID() + 1;
		}
		return id;
	}

	Hotel* getAllHotels()
	{
		Hotel* temp;
		temp = new Hotel[getHotelCount()];
		int i = 0;
		fstream f(FileName, ios::in);
		while (f.read((char*)(temp + i), sizeof(Hotel)))
		{
			i++;
		}
		f.close();

		return temp;
	}

	Hotel getHotelByID(int id)
	{
		Hotel temp;
		bool exist = false;

		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel)))
		{
			if (temp.getID() == id)
			{
				exist = true;
				break;
			}
		}
		f.close();
		if (!exist) {
			temp.setID(-1);
		}
		return temp;
	}

	Hotel getHotelByName(char* Name)
	{
		Hotel temp;
		bool exist = false;

		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel)))
		{
			if (temp.getName() == Name)
			{
				exist = true;
				break;
			}
		}
		f.close();
		if (!exist) {
			temp.setID(-1);
		}
		return temp;
	}

	Hotel getHotelByCity(char* city)
	{
		Hotel temp;
		bool exist = false;

		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel)))
		{
			if (temp.getCity() == city)
			{
				exist = true;
				break;
			}
		}
		f.close();
		if (!exist) {
			temp.setID(-1);
		}
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
		Hotel temp;
		int i = 0;
		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel))) {
			if (temp.getID() == obj.getID())
				break;
			else
				i++;
		}
		f.close();

		fstream f2(FileName, ios::in | ios::out);
		f2.seekp(i * sizeof(Hotel), ios::beg);
		f2.write((char*)&obj, sizeof(Hotel));
		f2.close();
	}

	void DeleteHotel(int id)
	{
		int i = 0;
		int count = getHotelCount();

		Hotel* obj;
		Hotel temp;
		obj = new Hotel[count];

		fstream f(FileName, ios::in);
		while (f.read((char*)&temp, sizeof(Hotel))) {
			if (temp.getID() == id)
			{

			}
			else
				i++;
		}
		f.close();

		fstream f2(FileName, ios::out);
		for (i = 0; i < count - 1; i++)
		{
			f2.write((char*)(obj + 1), sizeof(Hotel));
		}
		f2.close();

		delete obj;
	}
};

#endif