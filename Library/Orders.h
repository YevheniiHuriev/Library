#pragma once
#include <map>
#include <fstream>
#include "Library.h"
#include "Reader.h"
#include "Date_time.h"
class Orders
{
	map<Date_time, Reader> readers;
public:
	void addReader(string name);

	void showInfo()const;
	void takePublication(Library obj, string id, string bookCode);
	void returnPublication(Library obj, string id, string bookCode);
	
	void showAllInfo();

	void showPublications(Library obj);

	void saveReader()const;
	void savePublications()const;
	void save()const;

	void loadReaders();
	void loadPublications();
	void load();

	int IntExeption();
};

