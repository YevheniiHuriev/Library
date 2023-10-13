#pragma once
#include "PublicationException.h"
#include "Publication.h"
#include "Book.h"
#include "Magazine.h"
#include "Thesis.h"
#include <fstream>
#include <vector>

using std::vector;

class Reader
{
	string id;
	string name;
	vector<Publication*> publications;
	static int idCounter;
public:
	Reader();
	Reader(string name);

	void addPublication(Publication* obj);

	void takePublication(Publication* obj);

	Publication* returnPublication(string bookCode);

	string getId()const;
	string getName()const;
	int getAmountPublications()const;

	void showInfo()const;

	void savePublication(ofstream& file) const;
};

