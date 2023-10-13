#include "Library.h"
#include "PublicationException.h"
#include "Orders.h"
#include "Reader.h"
#include "Date_time.h"

int Reader::idCounter = 1;

int main()
{
	setlocale(0, "");

	Library obj;

	/*
	try
	{
		obj.addPublication(new Magazine("956-0-6438547", "Decor", "DECOR", Date(2023, 2, 10), 180, 48, 7, 2));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Magazine("689-1-8947512", "Decor", "Elle Decoration", Date(2023, 4, 8), 124, 50.5, 6, 8));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Magazine("215-7-487563",  "Beauty", "VOGUE", Date(2023, 5, 11), 145, 75, 7, 3));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Magazine("155-0-755246", "Sport", "Football", Date(2023, 7, 3), 98, 9, 16, 15));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Magazine("963-6-4343", "Fashion", "Majeur", Date(2023, 1, 14), 84, 18, 16, 23));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }

	try
	{
		obj.addPublication(new Book("159-6-55123", "Dragonfly Notes", "Mo Ana", "Poetry", "ReadRate", Date(2023, 1, 1), 190, 95, 8, 2));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Book("649-1-8677512", "Thirst", "Tracy Wolfe", "Fantasy", "BookChef", Date(2023, 3, 1), 630, 310, 7, 1));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Book("572-3-445434", "One", "Vlad Lei", "Horror", "Author.Today", Date(2023, 7, 10), 451, 180, 10, 1));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Book("642-8-156485", "Dead lions", "Mick Gerron", "Thriller", "ReadRate", Date(2023, 8, 3), 320, 87, 13, 1));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Book("122-5-223258", "Illegal", "Barchuk P.", "Detective", "Author.Today", Date(2023, 4, 25), 240, 139, 14, 1));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }

	try
	{
		obj.addPublication(new Thesis("665-1-58742", "testTitle_1", "Mukovoz P.P.", "Chemistry", "disserCat", Date(2023, 1, 27), 697, 450, 5));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Thesis("265-7-153265", "testTitle_2", "Tsaplin D.E.", "Chemistry", "disserCat", Date(2023, 7, 1), 365, 340, 4));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Thesis("624-3-525252", "testTitle_3", "Koshkin K.A.", "Medicine", "disserCat", Date(2023, 5, 13), 207, 350, 8));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Thesis("552-1-8412325", "testTitle_4", "Polyanina D.A.", "Medicine", "disserCat", Date(2023, 6, 17), 203, 410, 6));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }
	try
	{
		obj.addPublication(new Thesis("456-3-654789", "testTitle_5", "Krais V.V.", "Veterinary", "disserCat", Date(2023, 4, 8), 155, 320, 3));
	}
	catch (PublicationException* err) { cout << err->Message() << endl; }

	obj.savePublications();*/


	obj.loadPublications();

	int mainMenu = 0;

	string author, title, genre, bookCode, publishingHouse;
	Date receiptDate;
	int pagesNumber, copiesNumber, edition, tome;
	double price;
	int publMenu = 0, addMenu_1 = 0, addMenu_2;

	Orders KharkivLib;
	int orderMenu = 0;
	string s = "";
	string id = "";
	KharkivLib.load();

	do
	{
		cout << "\n\t  ========================================\n";
		cout << "\t||\t    	     MENU"; cout << "                 ||\n";
		cout << "\t  ========================================\n";
		cout << "\t|| 0. Exit.                               ||\n";
		cout << "\t  ----------------------------------------\n";
		cout << "\t|| 1. Work with publications.             ||\n";
		cout << "\t  ----------------------------------------\n";
		cout << "\t|| 2. Work with orders.                   ||\n";
		cout << "\t  ========================================\n";
		mainMenu = obj.IntExeption();
		system("cls");

		switch (mainMenu)
		{
		case 1:

			do
			{
				cout << "\n\t  ===================================================\n";
				cout << "\t||\t\t	 MENU"; cout << "                        ||\n";
				cout << "\t  ===================================================\n";
				cout << "\t|| 0. Return to the main menu.                       ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 1. View all publications.	                     ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 2. Add publication.                               ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 3. Delete publication by book code.               ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 4. Find publication by criterion.                 ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 5. Edit publication.                              ||\n";
				cout << "\t  ===================================================\n";
				publMenu = obj.IntExeption();
				system("cls");

				switch (publMenu)
				{
				case 1:
					obj.show();
					break;
				case 2:
					do
					{
						cout << "\n\t ----------------------------------------------------------------------------------------------------- \n";
						cout << "\t| Enter >> 1 - add new publication | >> 2 - add existing publication | >> 0 - return to the main menu |\n";
						cout << "\t ----------------------------------------------------------------------------------------------------- \n";
						addMenu_1 = obj.IntExeption();

						switch (addMenu_1)
						{
						case 1:
							do
							{
								cout << "\n\t ------------------------------------------------------------------------------------------------------ \n";
								cout << "\t| Enter >> 1 - add book | >> 2 - add magazine | >> 3 - add thesis | >> 0 - return to the previous menu |\n";
								cout << "\t ------------------------------------------------------------------------------------------------------ \n";
								addMenu_2 = obj.IntExeption();

								switch (addMenu_2)
								{
								case 1:
									cout << "\t --------------------- \n";
									cout << "\t| Enter the book code |\n";
									cout << "\t --------------------- \n";
									cout << endl << " >> "; cin >> ws;
									getline(cin, bookCode);
									cout << "\t ----------------- \n";
									cout << "\t| Enter the title |\n";
									cout << "\t ----------------- \n";
									cout << endl << " >> ";
									getline(cin, title);
									cout << "\t ------------------ \n";
									cout << "\t| Enter the author |\n";
									cout << "\t ------------------ \n";
									cout << endl << " >> ";
									getline(cin, author);
									cout << "\t ----------------- \n";
									cout << "\t| Enter the genre |\n";
									cout << "\t ----------------- \n";
									cout << endl << " >> ";
									getline(cin, genre);
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the publishing house |\n";
									cout << "\t ---------------------------- \n";
									cout << endl << " >> ";
									getline(cin, publishingHouse);
									cout << "\t ---------------- \n";
									cout << "\t| Enter the tome |\n";
									cout << "\t ---------------- \n";
									tome = obj.IntExeption();
									receiptDate = Date();
									cout << "\t ----------------------- \n";
									cout << "\t| Enter number of pages |\n";
									cout << "\t ----------------------- \n";
									pagesNumber = obj.IntExeption();
									cout << "\t ----------------- \n";
									cout << "\t| Enter the price |\n";
									cout << "\t ----------------- \n";
									price = obj.doubleExeption();
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the number of copies |\n";
									cout << "\t ---------------------------- \n";
									copiesNumber = obj.IntExeption();

									try
									{
										obj.addPublication(new Book(bookCode, title, author, genre, publishingHouse, receiptDate, pagesNumber, price, copiesNumber, tome));
									}
									catch (PublicationException* err) { cout << err->Message() << endl; }
									obj.savePublications();
									break;

								case 2:
									cout << "\t --------------------- \n";
									cout << "\t| Enter the book code |\n";
									cout << "\t --------------------- \n";
									cout << endl << " >> "; cin >> ws;
									getline(cin, bookCode);
									cout << "\t ----------------- \n";
									cout << "\t| Enter the genre |\n";
									cout << "\t ----------------- \n";
									cout << endl << " >> ";
									getline(cin, genre);
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the publishing house |\n";
									cout << "\t ---------------------------- \n";
									cout << endl << " >> ";
									getline(cin, publishingHouse);
									cout << "\t ------------------- \n";
									cout << "\t| Enter the edition |\n";
									cout << "\t ------------------- \n";
									edition = obj.IntExeption();
									receiptDate = Date();
									cout << "\t ----------------------- \n";
									cout << "\t| Enter number of pages |\n";
									cout << "\t ----------------------- \n";
									pagesNumber = obj.IntExeption();
									cout << "\t ----------------- \n";
									cout << "\t| Enter the price |\n";
									cout << "\t ----------------- \n";
									price = obj.doubleExeption();
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the number of copies |\n";
									cout << "\t ---------------------------- \n";
									copiesNumber = obj.IntExeption();

									try
									{
										obj.addPublication(new Magazine(bookCode, genre, publishingHouse, receiptDate, pagesNumber, price, copiesNumber, edition));
									}
									catch (PublicationException* err) { cout << err->Message() << endl; }
									obj.savePublications();
									break;

								case 3:
									cout << "\t --------------------- \n";
									cout << "\t| Enter the book code |\n";
									cout << "\t --------------------- \n";
									cout << endl << " >> "; cin >> ws;
									getline(cin, bookCode);
									cout << "\t ----------------- \n";
									cout << "\t| Enter the title |\n";
									cout << "\t ----------------- \n";
									cout << endl << " >> ";
									getline(cin, title);
									cout << "\t ------------------ \n";
									cout << "\t| Enter the author |\n";
									cout << "\t ------------------ \n";
									cout << endl << " >> ";
									getline(cin, author);
									cout << "\t ----------------- \n";
									cout << "\t| Enter the genre |\n";
									cout << "\t ----------------- \n";
									cout << endl << " >> ";
									getline(cin, genre);
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the publishing house |\n";
									cout << "\t ---------------------------- \n";
									cout << endl << " >> ";
									getline(cin, publishingHouse);
									receiptDate = Date();
									cout << "\t ----------------------- \n";
									cout << "\t| Enter number of pages |\n";
									cout << "\t ----------------------- \n";
									pagesNumber = obj.IntExeption();
									cout << "\t ----------------- \n";
									cout << "\t| Enter the price |\n";
									cout << "\t ----------------- \n";
									price = obj.doubleExeption();
									cout << "\t ---------------------------- \n";
									cout << "\t| Enter the number of copies |\n";
									cout << "\t ---------------------------- \n";
									copiesNumber = obj.IntExeption();

									try
									{
										obj.addPublication(new Thesis(bookCode, title, author, genre, publishingHouse, receiptDate, pagesNumber, price, copiesNumber));
									}
									catch (PublicationException* err) { cout << err->Message() << endl; }
									obj.savePublications();
									break;
								case 0: break;

								default:
									cout << "\t ------------------ \n";
									cout << "\t| Wrong menu item! |\n";
									cout << "\t ------------------ \n";
									break;
								}
							} while (addMenu_2 != 0);
							break;

						case 2:
							cout << "\t --------------------- \n";
							cout << "\t| Enter the book code |\n";
							cout << "\t --------------------- \n";
							cout << endl << " >> ";
							cin.ignore();
							getline(cin, bookCode);

							cout << "\n\t ----------------------------------- \n";
							cout << "\t| Enter the number of copies to add |\n";
							cout << "\t ----------------------------------- \n";
							copiesNumber = obj.IntExeption();

							obj.addExPub(bookCode, copiesNumber);
							obj.savePublications();
							break;

						case 0: break;
						default:
							cout << "\t ------------------ \n";
							cout << "\t| Wrong menu item! |\n";
							cout << "\t ------------------ \n";
							break;
						}
					} while (addMenu_1 != 0);
					break;
				case 3:
					cout << "\t --------------------- \n";
					cout << "\t| Enter the book code |\n";
					cout << "\t --------------------- \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, bookCode);
					obj.delBookByBookCode(bookCode);
					break;
				case 4:
					obj.sortByDate();
					obj.sortByType();
					obj.findBookBy—riteria();
					break;

				case 5:
					cout << "\t --------------------- \n";
					cout << "\t| Enter the book code |\n";
					cout << "\t --------------------- \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, bookCode);
					obj.editByBookCode(bookCode);
					break;
				case 0: break;
				default:
					cout << "\t ------------------ \n";
					cout << "\t| Wrong menu item! |\n";
					cout << "\t ------------------ \n"; break;
				}

			} while (publMenu != 0);

			break;

		case 2:
			do
			{
				cout << "\n\t  ===================================================\n";
				cout << "\t||\t\t	 MENU"; cout << "                        ||\n";
				cout << "\t  ===================================================\n";
				cout << "\t|| 0. Return to the main menu.                       ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 1. Show publications.                             ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 2. Add reader.           	                     ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 3. Show all readers.                              ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 4. Take publication.                              ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 5. Return publication.                            ||\n";
				cout << "\t  ---------------------------------------------------\n";
				cout << "\t|| 6. Show full information about readers.           ||\n";
				cout << "\t  ===================================================\n";
				orderMenu = KharkivLib.IntExeption();
				system("cls");

				switch (orderMenu)
				{
				case 1:
					KharkivLib.showPublications(obj);
					break;
				case 2:
					cout << "\t --------------------- \n";
					cout << "\t| Enter reader name.  |\n";
					cout << "\t --------------------- \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, s);
					try
					{
						KharkivLib.addReader(s);
					}
					catch (PublicationException* err) { cout << err->Message() << endl; }
					KharkivLib.save();
					break;
				case 3:
					KharkivLib.showInfo();
					break;
				case 4:
					cout << "\t -------------------- \n";
					cout << "\t| Enter reader code. |\n";
					cout << "\t -------------------- \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, id);
					cout << "\t ------------------ \n";
					cout << "\t| Enter book code. |\n";
					cout << "\t ------------------ \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, s);
					KharkivLib.takePublication(obj, id, s);
					KharkivLib.save();
					obj.savePublications();
					
					break;
				case 5:
					cout << "\t -------------------- \n";
					cout << "\t| Enter reader code. |\n";
					cout << "\t -------------------- \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, id);
					cout << "\t ------------------ \n";
					cout << "\t| Enter book code. |\n";
					cout << "\t ------------------ \n";
					cout << endl << " >> "; cin >> ws;
					getline(cin, s);
					KharkivLib.returnPublication(obj, id, s);
					KharkivLib.save();
					obj.savePublications();
					break;
				case 6:
					KharkivLib.showAllInfo();
					break;
				case 0: break;
				default:
					cout << "\t ------------------ \n";
					cout << "\t| Wrong menu item! |\n";
					cout << "\t ------------------ \n";
					break;
				}
			} while (orderMenu != 0);
			break;

		case 0:
			cout << "\t ------------------ \n";
			cout << "\t| Have a good day! |\n";
			cout << "\t ------------------ \n";
			break;
		default:
			cout << "\t ------------------ \n";
			cout << "\t| Wrong menu item! |\n";
			cout << "\t ------------------ \n";
			break;
		}
	} while (mainMenu);

	return 0;
}