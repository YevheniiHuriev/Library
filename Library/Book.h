#pragma once
#include "Publication.h"
class Book : public Publication
{
protected:
	int tome;
public:
	Book();
	Book(string bookCode, string title, string author, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber, int tome);

	int getTome()const;

	void setTome(int tome);

	virtual void description()const override;
	virtual string type()const override;
	virtual void edit()override;
	virtual void saveToTxt(ofstream& file)const override;
	virtual void loadFromTxt(ifstream& file) override;

};

