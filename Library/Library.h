#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PublicationException.h"
#include "Date.h" 
#include "Publication.h"
#include "Book.h"
#include "Magazine.h"
#include "Thesis.h"

using namespace std;

class Library
{
protected:
	vector <Publication*>lib;
public:

	void show();

	void addReturned(Publication* obj);
	void addPublication(Publication* obj);
	void addExPub(string bookCode, int copNum);

	void delBookByBookCode(string bookCode);
	void delPublication(string bookCode);

	void findBookBy—riteria();

	void editByBookCode(string bookCode);

	void savePublications();
	void loadPublications();

	void sortByType();
	void sortByDate();

	void showBook()const;
	void showMagazine()const;
	void showThesis()const;

	int IntExeption();
	double doubleExeption();

	Publication* searchPublicationByBookCode(string bookCode) ;

};

bool cmpByType(const Publication* left, const Publication* right);
bool cmpByRecDate(const Publication* left, const Publication* right);
