#pragma once
#include "Publication.h"
#include "PublicationException.h"

class Magazine : public Publication
{
protected:
	int edition;
public:
	Magazine();
	Magazine(string bookCode, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber, int edition);
	
	int getEdition()const;
	void setEdition(int edition);

	virtual void description()const override;
	virtual string type()const override;
	virtual void edit()override;
	virtual void saveToTxt(ofstream& file)const override;
	virtual void loadFromTxt(ifstream& file) override;
};

