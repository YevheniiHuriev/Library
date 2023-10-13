#include "Orders.h"

void Orders::addReader(string name)
{
	if (name.length() < 3)
	{
		throw new NameException;
	}
	readers[Date_time()] = Reader(name);
}

void Orders::takePublication(Library obj, string id, string bookCode)
{
	Date_time  orderTime;

	for (auto it : readers)
	{
		if (it.second.getId() == id)
		{
			orderTime = it.first;
		}
	}

	auto reader = readers.find(orderTime);
	if (reader == readers.end())
	{
		cout << "\t ------------------- \n";
		cout << "\t| Reader not found! |\n";
		cout << "\t ------------------- \n";
	}
	else
	{
		try
		{
			reader->second.takePublication(obj.searchPublicationByBookCode(bookCode));
			obj.delPublication(bookCode);
			cout << "\t ---------- \n";
			cout << "\t| Success! |\n";
			cout << "\t ---------- \n";
		}
		catch (PublicationException* err) { cout << err->Message() << endl; }
	}
}
void Orders::returnPublication(Library obj, string id, string bookCode)
{
	Date_time  orderTime;

	for (auto it : readers)
	{
		if (it.second.getId() == id)
		{
			orderTime = it.first;
		}
	}

	auto reader = readers.find(orderTime);
	if (reader == readers.end())
	{
		cout << "\t ------------------- \n";
		cout << "\t| Reader not found! |\n";
		cout << "\t ------------------- \n";
	}
	else
	{
		try
		{
			obj.addReturned((Publication*)reader->second.returnPublication(bookCode));
			cout << "\t ---------- \n";
			cout << "\t| Success! |\n";
			cout << "\t ---------- \n";
			if (reader->second.getAmountPublications() == 0)
			{
				readers.erase(reader);
			}
		}
		catch (const char* Message) {
			cout << Message << endl;
		}
	}
}

void Orders::showInfo() const
{
	cout << "\n\t  ---------------------------------------- \n";
	for (auto it : readers)
	{

		cout << "\t|| Reader code: " << it.second.getId() << " | " << "Name : " << setw(15) << it.second.getName() << "||\n";
		cout << "\t  ---------------------------------------- \n";
	}
}
void Orders::showAllInfo() 
{
	for (auto it : readers)
	{
		cout << "  ============================================== \n";
		cout << "||            " << it.first << "             || \n";
		cout << "  ---------------------------------------------- \n";
		it.second.showInfo(); cout << endl;
	}
}
void Orders::showPublications(Library obj)
{
	obj.show();
}

void Orders::saveReader() const
{
	ofstream file("Reader.txt");
	if (file.is_open())
	{
		for (auto it = readers.begin(); it != readers.end(); it++)
		{
			file << it->first.getYear() << endl;
			file << it->first.getMonth() << endl;
			file << it->first.getDay() << endl;
			file << it->first.getHour() << endl;
			file << it->first.getMinutes() << endl;
			file << it->first.getSeconds() << endl;
			file << it->second.getName() << endl;
		}
		file.close();
	}
}
void Orders::savePublications() const
{
	ofstream file("Publication.txt");
	if (file.is_open())
	{
		for (auto it = readers.begin(); it != readers.end(); it++)
		{
			it->second.savePublication(file);
		}
		file.close();
	}
}
void Orders::save() const
{
	saveReader();
	savePublications();
}

void Orders::loadReaders()
{
	ifstream file("Reader.txt");
	if (file.is_open())
	{
		int y = 0, m = 0, d = 0, h = 0, min = 0, s = 0;
		string str = "";
		while (!file.eof())
		{
			file >> y >> m >> d >> h >> min >> s;
			file.get();
			getline(file, str);
			readers[Date_time(y, m, d, h, min, s)] = Reader(str);
		}
		file.get();
	}
}
void Orders::loadPublications()
{
	ifstream file("Publication.txt");
	if (file.is_open())
	{
		string strPubl = "";  string type = "";
		while (!file.eof())
		{
			getline(file, strPubl);
			getline(file, type);

			for (auto it = readers.begin(); it != readers.end(); it++)
			{
				if (it->second.getName() == strPubl)
				{
					if (type == "Book")
					{
						Book* obj = new Book();
						obj->loadFromTxt(file);
						it->second.addPublication(obj);
					}
					else if (type == "Magazine")
					{
						Magazine* obj = new Magazine();
						obj->loadFromTxt(file);
						it->second.addPublication(obj);
					}
					else if (type == "Thesis")
					{
						Thesis* obj = new Thesis();
						obj->loadFromTxt(file);
						it->second.addPublication(obj);
					}
					file.get();
				}
			}
		}
	}
}
void Orders::load()
{
	loadReaders();
	loadPublications();
}

int Orders::IntExeption()
{
	int number;
	cout << " >> ";
	while (!(cin >> number))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\t ------------------------------------ \n";
		cout << "\t| Invalid number entered! Try again. |\n";
		cout << "\t ------------------------------------ \n";
		cout << " >> ";
	}
	return number;
}

