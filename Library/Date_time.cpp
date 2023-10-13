#include "Date_time.h"

bool Date_time::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0 || year % 100 == 0 && year % 400 == 0);
}
int Date_time::monthDays() const
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31; break;
	case 4: case 6: case 9: case 11: return 30; break;
	case 2: return isLeapYear() ? 29 : 28; break;
	}
	return 0;
}

Date_time::Date_time()
{
	tm* obj = new tm;
	time_t sec = time(NULL);
	localtime_s(obj, &sec);

	this->year = obj->tm_year + 1900;
	this->month = obj->tm_mon + 1;
	this->day = obj->tm_mday;
	this->seconds = obj->tm_sec;
	this->minutes = obj->tm_min;
	this->hour = obj->tm_hour;

	delete obj;
}
Date_time::Date_time(int year, int month, int day, int hour, int minutes, int seconds)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
}

void Date_time::show() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << " "
		<< hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
}


void Date_time::setYear(int year)
{
	this->year = year;
}
int Date_time::getYear() const
{
	return year;
}
void Date_time::setMonth(int month)
{
	if (month > 0 && month <= 12)
	{
		this->month = month;
	}
}
int Date_time::getMonth() const
{
	return month;
}
void Date_time::setDay(int day)
{
	if (day > 0 && day <= monthDays())
	{
		this->day = day;
	}
}
int Date_time::getDay() const
{
	return day;
}
void Date_time::setHour(int hour)
{
	if (hour >= 0 && hour < 24)
	{
		this->hour = hour;
	}
}
int Date_time::getHour() const
{
	return hour;
}
void Date_time::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes <= 59)
	{
		this->minutes = minutes;
	}
}
int Date_time::getMinutes() const
{
	return minutes;
}
void Date_time::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds <= 59)
	{
		this->seconds = seconds;
	}
}
int Date_time::getSeconds() const
{
	return seconds;
}

bool Date_time::valid() const
{
	if (day > 0 && day <= monthDays() && month >= 1 && month <= 12 && hour >= 0 && hour < 24 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) return true;
	else
	{
		return false;
	}
}

bool Date_time::operator==(const Date_time& obj) const&
{
	return (this->day == obj.day && this->month == obj.month && this->year == obj.year && this->seconds == obj.seconds && this->minutes == obj.minutes && this->hour == obj.hour);
}
bool Date_time::operator!=(const Date_time& obj) const&
{
	return !(*this == obj);
}
bool Date_time::operator>(const Date_time& obj) const&
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
	else if (this->hour > obj.hour)
	{
		return true;
	}
	else if (this->hour == obj.hour && this->minutes > obj.minutes)
	{
		return true;
	}
	else if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds)
	{
		return true;
	}
	return false;
}
bool Date_time::operator<(const Date_time& obj) const&
{
	return !(*this > obj) && !(*this == obj);
}
bool Date_time::operator>=(const Date_time& obj) const&
{
	return (*this > obj) || (*this == obj);
}
bool Date_time::operator<=(const Date_time& obj) const&
{
	return (*this < obj) || (*this == obj);
}

ostream& operator<<(ostream& os, const Date_time& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year << " | " << t.hour / 10 << t.hour % 10 << ":"
		<< t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10
		<< t.seconds % 10;
	return os;
}
istream& operator>>(istream& is, Date_time& t)
{
	do
	{
		cout << "dd mm yyyy hh mm ss: ";
		is >> t.day >> t.month >> t.year >> t.hour >> t.minutes >> t.seconds;
	} while (!t.valid());
	return is;
}
