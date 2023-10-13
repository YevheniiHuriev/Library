#include "Library.h"
#include <sstream>

void Library::addReturned(Publication* obj)
{
	int isExist = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->getBookCode() == obj->getBookCode())
		{
			isExist++;
		}
	}

	if (isExist != 0)
	{
		for (int i = 0; i < lib.size(); i++)
		{
			if (lib[i]->getBookCode() == obj->getBookCode())
			{
				try {
					lib[i]->setCopiesNumber(lib[i]->getCopiesNumber() + 1);
				}
				catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
			}
		}
	}
	else
	{
		lib.push_back(obj);
		for (int i = 0; i < lib.size(); i++)
		{
			if (lib[i]->getBookCode() == obj->getBookCode())
			{
				try {
					lib[i]->setCopiesNumber(1);
				}
				catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
			}
		}
	}
}

void Library::addPublication(Publication* obj)
{
	if (obj == 0)
	{
		throw "\t\tError: incorrect object\n";
	}
	lib.push_back(obj);
}
void Library::addExPub(string bookCode, int copNum)
{
	int isExist = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->getBookCode() == bookCode)
		{
			isExist++;
		}
	}

	if (isExist != 0)
	{
		for (int i = 0; i < lib.size(); i++)
		{
			if (lib[i]->getBookCode() == bookCode)
			{
				lib[i]->setCopiesNumber(lib[i]->getCopiesNumber() + copNum);
			}
		}
		savePublications();
		cout << "\t --------------- \n";
		cout << "\t| Successfully! |\n";
		cout << "\t --------------- \n";
	}
	else
	{
		cout << "\t ---------------------- \n";
		cout << "\t| Book code not found! |\n";
		cout << "\t ---------------------- \n";
	}
}

void Library::delBookByBookCode(string bookCode)
{
	int isExist = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->getBookCode() == bookCode)
		{
			isExist++;
		}
	}

	if (isExist != 0)
	{
		int menu = 0;
		do
		{
			cout << "\n\t ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
			cout << "\t| Enter >> 1 - show publication | >> 2 - delete one copy | >> 3 - delete all copies and return to the main menu | >> 4 - clear console | >> 0 - return to the main menu |\n";
			cout << "\t ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
			menu = IntExeption();

			switch (menu)
			{
			case 1:
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == bookCode and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == bookCode and lib[i]->type() == "Magazine")
					{
						showMagazine();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == bookCode and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
				break;
			case 2:
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == bookCode)
					{
						if (lib[i]->getCopiesNumber() > 1)
						{
							try {
								lib[i]->setCopiesNumber(lib[i]->getCopiesNumber() - 1);
							}
							catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
							savePublications();
						}
						else
						{
							lib.erase(lib.begin() + i);

						}
					}
				}
				break;
			case 3:
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == bookCode)
					{
						lib.erase(lib.begin() + i);
					}
				}
				savePublications();
				menu = 0;
				break;
			case 4: system("cls"); break;
			case 0: break;
			default:
				cout << "\t -------------------------------------------- \n";
				cout << "\t| Ñheck the correctness of the entered data! |\n";
				cout << "\t -------------------------------------------- \n";
				break;
			}
		} while (menu != 0);
	}
	else
	{
		cout << "\t ---------------------- \n";
		cout << "\t| Book code not found! |\n";
		cout << "\t ---------------------- \n";
	}
}
void Library::delPublication(string bookCode)
{
	int isExist = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->getBookCode() == bookCode)
		{
			isExist++;
		}
	}

	if (isExist != 0)
	{
		for (int i = 0; i < lib.size(); i++)
		{
			if (lib[i]->getBookCode() == bookCode)
			{
				if (lib[i]->getCopiesNumber() > 1)
				{
					int num = lib[i]->getCopiesNumber();
					num -= 1;

					try {
						lib[i]->setCopiesNumber(num);
					}
					catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
				}
				else
				{
					lib.erase(lib.begin() + i);
				}
			}
		}
	}
	else
	{
		cout << "\t ---------------------- \n";
		cout << "\t| Book code not found! |\n";
		cout << "\t ---------------------- \n";
	}
}

void Library::findBookByÑriteria()
{
	int menu = 0;
	string tmp; Date startDate, endDate; int isExist = 0;

	do
	{
		cout << "\n\t -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
		cout << "\t| Find by >> 1 - type | >> 2 - book ñode | >> 3 - title | >> 4 - author | >> 5 - genre/topic | >> 6 - publishing house | >> 7 - publication date | >> 8 - clear console | >> 0 - return to the main menu |\n";
		cout << "\t -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
		menu = IntExeption();

		switch (menu)
		{
		case 1:

			cout << "\t ------------ \n";
			cout << "\t| Enter type |\n";
			cout << "\t ------------ \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			if (tmp == "Book")
			{
				showBook();
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->type() == tmp)
					{
						lib[i]->description();
					}
				}
			}
			else if (tmp == "Magazine")
			{
				showMagazine();
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->type() == tmp)
					{
						lib[i]->description();
					}
				}
			}
			else if (tmp == "Thesis")
			{
				showThesis();
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->type() == tmp)
					{
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ----------------- \n";
				cout << "\t| Type not found! |\n";
				cout << "\t ----------------- \n\n";
			}
			break;
		case 2:
			cout << "\t ----------------- \n";
			cout << "\t| Enter book code |\n";
			cout << "\t ----------------- \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getBookCode() == tmp)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == tmp and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == tmp and lib[i]->type() == "Magazine")
					{
						showMagazine();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == tmp and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ---------------------- \n";
				cout << "\t| Book code not found! |\n";
				cout << "\t ---------------------- \n\n";
			}
			break;
		case 3:
			cout << "\t ------------- \n";
			cout << "\t| Enter title |\n";
			cout << "\t ------------- \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getTitle() == tmp)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getTitle() == tmp and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getTitle() == tmp and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ------------------ \n";
				cout << "\t| Title not found! |\n";
				cout << "\t ------------------ \n\n";
			}
			break;
		case 4:
			cout << "\t -------------- \n";
			cout << "\t| Enter author |\n";
			cout << "\t -------------- \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getAuthor() == tmp)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getAuthor() == tmp and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getAuthor() == tmp and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ------------------- \n";
				cout << "\t| Author not found! |\n";
				cout << "\t ------------------- \n\n";
			}
			break;
		case 5:
			cout << "\t --------------------- \n";
			cout << "\t| Enter genre / topic |\n";
			cout << "\t --------------------- \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getGenre() == tmp)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getGenre() == tmp and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getGenre() == tmp and lib[i]->type() == "Magazine")
					{
						showMagazine();
						lib[i]->description();
					}
					else if (lib[i]->getGenre() == tmp and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ------------------ \n";
				cout << "\t| Genre not found! |\n";
				cout << "\t ------------------ \n\n";
			}
			break;
		case 6:
			cout << "\t ------------------------ \n";
			cout << "\t| Enter publishing house |\n";
			cout << "\t ------------------------ \n";
			cout << endl << " >> ";
			cin.ignore();
			getline(cin, tmp);

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getPublishingHouse() == tmp)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getPublishingHouse() == tmp and lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getPublishingHouse() == tmp and lib[i]->type() == "Magazine")
					{
						showMagazine();
						lib[i]->description();
					}
					else if (lib[i]->getPublishingHouse() == tmp and lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
			}
			else
			{
				cout << "\t ----------------------------- \n";
				cout << "\t| Publishing house not found! |\n";
				cout << "\t ----------------------------- \n\n";
			}
			break;
		case 7:
			cout << "\t ---------------------------- \n";
			cout << "\t| Enter receipt date (range) |\n";
			cout << "\t ---------------------------- \n";
			cout << "\t ------- \n";
			cout << "\t| Start |\n";
			cout << "\t ------- \n";
			cout << endl << " >> ";
			cin >> startDate;
			cout << "\n\t ----- \n";
			cout << "\t| End |\n";
			cout << "\t ----- \n";
			cout << endl << " >> ";
			cin >> endDate;

			for (int i = 0; i < lib.size(); i++)
			{
				if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate)
				{
					isExist++;
				}
			}

			if (isExist != 0)
			{
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Book")
					{
						showBook();
						for (int i = 0; i < lib.size(); i++)
						{
							if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Book")
							{
								lib[i]->description();
							}
						}break;
					}
				}
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Magazine")
					{
						showMagazine();
						for (int i = 0; i < lib.size(); i++)
						{
							if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Magazine")
							{
								lib[i]->description();
							}
						}break;
					}
				}
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Thesis")
					{
						showThesis();
						for (int i = 0; i < lib.size(); i++)
						{
							if (lib[i]->getReceiptDate() >= startDate && lib[i]->getReceiptDate() <= endDate && lib[i]->type() == "Thesis")
							{
								lib[i]->description();
							}
						}break;
					}
				}
			}
			else
			{
				cout << "\t ----------------------------------------- \n";
				cout << "\t| No books found for the specified range! |\n";
				cout << "\t ----------------------------------------- \n\n";
			}
			break;
		case 8: system("cls"); break;
		case 0: break;

		default:
			cout << "\t -------------------------------------------- \n";
			cout << "\t| Ñheck the correctness of the entered data! |\n";
			cout << "\t -------------------------------------------- \n\n";
			break;
		}
	} while (menu != 0);
	
}

void Library::editByBookCode(string bookCode)
{
	int isExist = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->getBookCode() == bookCode)
		{
			isExist++;
		}
	}

	if (isExist != 0)
	{
		int menu = 0;
		do
		{
			cout << "\n\t ----------------------------------------------------------------------------------------------------- \n";
			cout << "\t| Enter >> 1 - show publication | >> 2 - edit | >> 3 - clear console | >> 0 - return to the main menu |\n";
			cout << "\t ----------------------------------------------------------------------------------------------------- \n";
			menu = IntExeption();

			switch (menu)
			{
			case 1:
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Book")
					{
						showBook();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Magazine")
					{
						showMagazine();
						lib[i]->description();
					}
					else if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Thesis")
					{
						showThesis();
						lib[i]->description();
					}
				}
				break;
			case 2:
				for (int i = 0; i < lib.size(); i++)
				{
					if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Book")
					{
						lib[i]->edit();
					}
					else if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Magazine")
					{
						lib[i]->edit();
					}
					else if (lib[i]->getBookCode() == bookCode && lib[i]->type() == "Thesis")
					{
						lib[i]->edit();
					}
					savePublications();
				}
				break;
			case 3: system("cls"); break;
			case 0: break;
			default:
				cout << "\t -------------------------------------------- \n";
				cout << "\t| Ñheck the correctness of the entered data! |\n";
				cout << "\t -------------------------------------------- \n";
				break;
			}
		} while (menu != 0);
	}
	else
	{
		cout << "\t ---------------------- \n";
		cout << "\t| Book code not found! |\n";
		cout << "\t ---------------------- \n";
	}
	
}

void Library::savePublications()
{
	ofstream file("Library.txt");
	if (file.is_open())
	{
		for (Publication* obj : lib)
		{
			obj->saveToTxt(file);
		}
		file.close();
	}
}
void Library::loadPublications()
{
	ifstream file("Library.txt");
	if (file.is_open())
	{
		string type = "";
		while (!file.eof())
		{
			getline(file, type);
			if (type == "Book")
			{
				Book* obj = new Book();
				obj->loadFromTxt(file);
				lib.push_back(obj);
			}
			else if (type == "Magazine")
			{
				Magazine* obj = new Magazine();
				obj->loadFromTxt(file);
				lib.push_back(obj);
			}
			else if (type == "Thesis")
			{
				Thesis* obj = new Thesis();
				obj->loadFromTxt(file);
				lib.push_back(obj);
			}
			file.get();
		}
	}
}

void Library::sortByType()
{
	sort(lib.begin(), lib.end(), cmpByType);
}
void Library::sortByDate()
{
	sort(lib.begin(), lib.end(), cmpByRecDate);
}

void Library::showBook()const
{
	cout << endl << "\t ------ \n";
	cout << "\t| Book |\n";
	cout << "\t ------ \n";

	cout << "\t  ================================================================================================================================================================= \n";
	cout << "\t||   Book code  |||      Title      |||    Author    |||    Genre   ||| Publising house ||| Tome |||   Receipt date   ||| Pages number ||| Price ||| Copies number ||\n";
	cout << "\t  ================================================================================================================================================================= \n";
}
void Library::showMagazine()const
{
	cout << endl << "\t ---------- \n";
	cout << "\t| Magazine |\n";
	cout << "\t ---------- \n";

	cout << "\t  =============================================================================================================================== \n";
	cout << "\t||   Book code  |||    Genre   ||| Publising house ||| Edition |||   Receipt date   ||| Pages number ||| Price ||| Copies number ||\n";
	cout << "\t  =============================================================================================================================== \n";
}
void Library::showThesis()const
{
	cout << endl << "\t -------- \n";
	cout << "\t| Thesis |\n";
	cout << "\t -------- \n";

	cout << "\t  ========================================================================================================================================================== \n";
	cout << "\t||   Book code  |||      Title      |||     Author     |||    Genre   ||| Publising house |||   Receipt date   ||| Pages number ||| Price ||| Copies number ||\n";
	cout << "\t  ========================================================================================================================================================== \n";
}

int Library::IntExeption()
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
double Library::doubleExeption()
{
	double number;
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

Publication* Library::searchPublicationByBookCode(string bookCode) 
{
	vector<Publication*> tmp;
	
	for (auto it : lib)
	{
		if (it->getBookCode() == bookCode)
		{
			ofstream f("tmp.txt");
			if (f.is_open())
			{
				it->saveToTxt(f);
				f.close();
			}

			ifstream file("tmp.txt");
			if (file.is_open())
			{
				string type = "";
				while (!file.eof())
				{
					getline(file, type);
					if (type == "Book")
					{
						Book* obj = new Book();
						obj->loadFromTxt(file);
						tmp.push_back(obj);
					}
					else if (type == "Magazine")
					{
						Magazine* obj = new Magazine();
						obj->loadFromTxt(file);
						tmp.push_back(obj);
					}
					else if (type == "Thesis")
					{
						Thesis* obj = new Thesis();
						obj->loadFromTxt(file);
						tmp.push_back(obj);
					}
					file.get();
				}
				for (auto tmpItem : tmp)
				{
					if (tmpItem->getBookCode() == bookCode)
					{
						return tmpItem;
					}
				}
				file.close();
			}
		}
	}
	return nullptr;
}

void Library::show()
{
	sortByDate();
	sortByType();

	int b = 0, m = 0, t = 0;
	for (int i = 0; i < lib.size(); i++)
	{
		if (lib[i]->type() == "Book")
		{
			b++;
		}
		else if (lib[i]->type() == "Magazine")
		{
			m++;
		}
		else if (lib[i]->type() == "Thesis")
		{
			t++;
		}
	}

	showBook();
	for (int i = 0; i < b; i++)
	{
		lib[i]->description();
	}

	showThesis();
	for (int i = b+m; i < b+m+t; i++)
	{
		lib[i]->description();
	}

	showMagazine();
	for (int i = b; i < b + m; i++)
	{
		lib[i]->description();
	}
}

bool cmpByType(const Publication* left, const Publication* right)
{
	return left->type() < right->type();
}
bool cmpByRecDate(const Publication* left, const Publication* right)
{
	return left->getReceiptDate() > right->getReceiptDate();
}
