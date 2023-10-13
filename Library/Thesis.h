#pragma once
#include "Publication.h"
class Thesis : public Publication
{
public:
	Thesis();
	Thesis(string bookCode, string title, string author, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber);


	virtual void description()const override;
	virtual string type()const override;
	virtual void edit()override;
	virtual void saveToTxt(ofstream& file)const override;
	virtual void loadFromTxt(ifstream& file) override;
};

