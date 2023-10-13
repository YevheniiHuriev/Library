#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	bool isLeapYear()const; //�������� �� ���������� ���
	int monthDays()const; //���������� ���� �� ������

public:

	//---------������������ � ����������---------
	Date(); // �� ���������  - ������� ����
	Date(int year, int month, int day); //� ����������� - �������� ����
	void showDate()const;

	//---------���������---------
	void setYear(int year);
	int getYear()const;
	void setMonth(int month);
	int getMonth()const;
	void setDay(int day);
	int getDay()const;

	void nextDate(); //��������� ����
	void prevDate(); //���������� ����

	bool valid()const; //�������� ���� �� ������������

	//--------- ��������� ��������� ---------
	bool operator == (const Date& obj)const&;
	bool operator != (const Date& obj)const&;
	bool operator > (const Date& obj)const&;
	bool operator < (const Date& obj)const&;
	bool operator >= (const Date& obj)const&;
	bool operator <= (const Date& obj)const&;

	//--------- ��������� ���������� ---------	
	Date& operator += (int days); //�������� days ���� � ����
	Date& operator -= (int days); //������� days ���� �� ����
	Date& operator += (float months); //�������� months ������� � ����
	Date& operator -= (float months); //������� months ������� �� ����
	Date& operator += (long years); //�������� years ��� � ����
	Date& operator -= (long years); //������� years ��� �� ����
	
	//--------- �������������� ��������� ---------
	Date operator + (int days)const&;
	Date operator - (int days)const&;
	Date operator + (float months)const&; //�������� months ������� � ����
	Date operator - (float months)const&; //������� months ������� �� ����
	Date operator + (long years)const&; //�������� years ��� � ����
	Date operator - (long years)const&; //������� years ��� �� ����

	int operator - (const Date& obj)const&; //���������� ���� ����� ������

	// ------------------------------

	Date& operator -- ();
	Date operator -- (int);
	Date& operator ++ ();
	Date operator ++ (int);

	friend Date operator + (int n, const Date& a);
	friend Date operator - (int n, const Date& a);

	friend ostream& operator << (ostream& os, const Date& t);
	friend istream& operator >> (istream& is, Date& t);

	
};
