#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

class Date_time
{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	int seconds;

	bool isLeapYear()const; //Ïðîâåðêà íà âèñîêîñíûé ãîä
	int monthDays()const; //Êîëè÷åñòâî äíåé ïî ìåñÿöó

public:
	//---------ÊÎÍÑÒÐÓÊÒÎÐÛ è ÄÅÑÒÐÓÊÒÎÐ---------
	Date_time(); // Ïî óìîë÷àíèþ  - òåêóùàÿ äàòà
	Date_time(int year, int month, int day, int hour, int minutes, int seconds); //Ñ ïàðàìåòðàìè - çàäàííàÿ äàòà
	void show()const;

	//---------ÀÊÑÅÑÑÎÐÛ---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;
	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;

	bool valid()const; //Ïðîâåðêà äàòû íà êîððåêòíîñòü

	//--------- ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß ---------
	bool operator == (const Date_time& obj)const&;
	bool operator != (const Date_time& obj)const&;
	bool operator > (const Date_time& obj)const&;
	bool operator < (const Date_time& obj)const&;
	bool operator >= (const Date_time& obj)const&;
	bool operator <= (const Date_time& obj)const&;

	friend ostream& operator << (ostream& os, const Date_time& t);
	friend istream& operator >> (istream& is, Date_time& t);
};

