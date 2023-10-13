#include "Date.h"

bool Date::isLeapYear() const
{
	return (year%4==0 && year%100 != 0 || year%100 == 0 && year%400 == 0);
}
int Date::monthDays() const
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31; break;
	case 4: case 6: case 9: case 11: return 30; break;
	case 2: return isLeapYear() ? 29 : 28; break;
	}
	return 0;
}

void Date::nextDate()
{
	if (day == 31 && month == 12)
	{
		day = 1;
		month = 1;
		year++;
	}
	else if (day == monthDays())
	{
		day = 1;
		month++;
	}
	else
	{
		day++;
	}
}
void Date::prevDate()
{
	if (day == 1 && month == 1)
	{
		day = 31;
		month = 12;
		year--;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	tm* obj = new tm;
	time_t sec = time(NULL);
	localtime_s(obj, &sec);

	this->year = obj->tm_year + 1900;
	this->month = obj->tm_mon + 1;
	this->day = obj->tm_mday;

	delete obj;
}
Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::showDate() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
}

void Date::setYear(int year)
{
	this->year = year;
}
int Date::getYear() const
{
	return year;
}
void Date::setMonth(int month)
{
	if (month > 0 && month <=12)
	{
		this->month = month;
	}
}
int Date::getMonth() const
{
	return month;
}
void Date::setDay(int day)
{
	if (day > 0 && day <= monthDays())
	{
		this->day = day;
	}
}
int Date::getDay() const
{
	return day;
}

bool Date::valid() const
{
	return (day > 0 && day <= monthDays() && month >= 1 && month <= 12);
}

bool Date::operator==(const Date& obj) const&
{
	return (this->day == obj.day && this->month == obj.month && this-> year == obj.year);
}
bool Date::operator!=(const Date& obj) const&
{
	//return (this->day != obj.day && this->month != obj.month && this->year != obj.year);
	return !(*this == obj);
}
bool Date::operator>(const Date& obj) const&
{
	if (this->year > obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month > obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)
	{
		return true;
	}
	return false;
}
bool Date::operator<(const Date& obj) const&
{
	/*if (this->year < obj.year)
	{
		return true;
	}
	else if (this->year == obj.year && this->month < obj.month)
	{
		return true;
	}
	else if (this->year == obj.year && this->month == obj.month && this->day < obj.day)
	{
		return true;
	}
	return false;*/
	return !(*this > obj) && !(*this == obj);
}
bool Date::operator>=(const Date& obj) const&
{
	return (*this > obj) || (*this == obj);
}
bool Date::operator<=(const Date& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Date& Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->nextDate();
	}
	return *this;
}
Date& Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->prevDate();
	}
	return *this;
}
Date& Date::operator+=(float months)
{
	month += months;
	if (month > 12)
	{
		year += (month - 1) / 12;
		month %= 12;
		if (month == 0)
		{
			month = 12;
		}
	}
	return *this;
}
Date& Date::operator-=(float months)
{
	month -= months;
	if (month <= 0)
	{
		year -= abs(month / 12) + 1;
		month = 12 - abs(month % 12);
		if (month == 0)
		{
			month = 12;
		}
	}
	return *this;
}
Date& Date::operator+=(long years)
{
	year += years;
	return *this;
}
Date& Date::operator-=(long years)
{
	year -= years;
	return *this;
}

Date Date::operator+(int days) const&
{
	Date tmp = *this;
	tmp += days;
	return tmp;
}
Date Date::operator-(int days) const&
{
	Date tmp = *this;
	tmp -= days;
	return tmp;
}
Date Date::operator+(float months) const&
{
	Date tmp = *this;
	tmp += months;
	return tmp;
}
Date Date::operator-(float months) const&
{
	Date tmp = *this;
	tmp -= months;
	return tmp;
}
Date Date::operator+(long years) const&
{
	Date tmp = *this;
	tmp += years;
	return tmp;
}
Date Date::operator-(long years) const&
{
	Date tmp = *this;
	tmp -= years;
	return tmp;
}

int Date::operator-(const Date& obj) const&
{
	int counter = 0;
	Date tmp = *this;
	if (tmp > obj)
	{
		while (tmp != obj)
		{
			tmp -= 1;
			counter++;
		}
	}
	else
	{
		while (tmp != obj)
		{
			tmp += 1;
			counter++;
		}
	}
	return counter;
}

Date& Date::operator--()
{
	this->prevDate();
	return*this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	this->prevDate();
	return tmp;
}
Date& Date::operator++()
{
	this->nextDate();
	return* this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

Date operator+(int n, const Date& a)
{
	return a + n;
}
Date operator-(int n, const Date& a)
{
	return a - n;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}
istream& operator>>(istream& is, Date& t)
{
	do
	{
		cout << "dd mm yyyy: ";
		is >> t.day >> t.month >> t.year;
	} while (!t.valid());
	return is;
}
