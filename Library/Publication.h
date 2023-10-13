#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "PublicationException.h"
#include "Date.h" 

using namespace std;

class Publication
{
protected:
	string author;
	string title;
	string genre;
	string bookCode;
	string publishingHouse;
	Date receiptDate;
	int pagesNumber;
	double price;
	int copiesNumber;
public:
	Publication();
	Publication(string bookCode, string author, string title, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber);

	string getTitle()const;
	string getAuthor()const;
	string getGenre()const;
	string getBookCode()const;
	string getPublishingHouse()const;
	Date getReceiptDate()const;
	int getPagesNumber()const;
	double getPrice()const;
	int getCopiesNumber()const;

	void setTitle(string title);
	void setAuthor(string author);
	void setGenre(string genre);
	void setBookCode(string bookCode);
	void setPublishingHouse(string publishingHouse);
	void setReceiptDate(Date receiptDate);
	void setPagesNumber(int pagesNumber);
	void setPrice(double price);
	void setCopiesNumber(int copiesNumber);

	int IntExeption();
	double doubleExeption();

	virtual void description()const = 0;
	virtual string type()const = 0;
	virtual void edit() = 0;
	virtual void saveToTxt(ofstream& file)const = 0;
	virtual void loadFromTxt(ifstream& file) = 0;
};

