#include "Magazine.h"

Magazine::Magazine()
{
    edition = 0;
}

Magazine::Magazine(string bookCode, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber, int edition)
{
    this->genre = "empty";
    setGenre(genre);
    this->bookCode = "empty";
    setBookCode(bookCode);
    this->publishingHouse = "empty";
    setPublishingHouse(publishingHouse);
    this->edition = 0;
    setEdition(edition);
    this->receiptDate = Date();
    setReceiptDate(receiptDate);
    this->pagesNumber = 0;
    setPagesNumber(pagesNumber);
    this->price = 0;
    setPrice(price);
    this->copiesNumber = 0;
    setCopiesNumber(copiesNumber);
    this->edition = 0;
    setEdition(edition);
}

int Magazine::getEdition() const
{
    return edition;
}

void Magazine::setEdition(int edition)
{
    if (edition < 1)
    {
        throw new BookEditionException;
    }
    this->edition = edition;
}

void Magazine::description() const
{
    cout << "\t||" << setw(13) << bookCode << " ||| "
        << setw(10) << genre << " ||| "
        << setw(15) << publishingHouse << " ||| "
        << setw(7) << edition << " ||| "
        << setw(7) << receiptDate << " ||| "
        << setw(12) << pagesNumber << " ||| "
        << setw(5) << price << " ||| ";
    cout << setw(13) << copiesNumber; cout << " ||\n";
    cout << "\t  =============================================================================================================================== \n";
}

string Magazine::type() const
{
	return "Magazine";
}

void Magazine::edit()
{
    int menu = 0; string strTmp; int intTmp; Date tmp; double dTmp;

    cout << "\n\t ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
    cout << "\t| Enter >> 1 - topic | >> 2 - publising house | >> 3 - edition | >> 4 - receipt date | >> 5 - pages number | >> 6 - price | >> 7 - copies number | >> 0 - return to the previous menu |\n";
    cout << "\t ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
    cout << endl << " >> "; cin >> menu;
    switch (menu)
    {
    case 1:
        cout << "\t ----------------- \n";
        cout << "\t| Enter new topic |\n";
        cout << "\t ----------------- \n";
        cout << endl << " >> ";
        cin.ignore();
        getline(cin, genre);
        break;
    case 2:
        cout << "\t --------------------------- \n";
        cout << "\t| Enter new publising house |\n";
        cout << "\t --------------------------- \n";
        cout << endl << " >> ";
        cin.ignore();
        getline(cin, strTmp);
        try {
            setPublishingHouse(strTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 3:
        cout << "\t ------------------- \n";
        cout << "\t| Enter new edition |\n";
        cout << "\t ------------------- \n";
        intTmp = IntExeption();
        try {
            setEdition(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 4:
        cout << "\t ---------------------------- \n";
        cout << "\t| Enter new receipt date |\n";
        cout << "\t ---------------------------- \n";
        cout << endl << " >> ";
        cin >> tmp;
        try {
            setReceiptDate(tmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 5:
        cout << "\t ------------------------ \n";
        cout << "\t| Enter new pages number |\n";
        cout << "\t ------------------------ \n";
        intTmp = IntExeption();
        try {
            setPagesNumber(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 6:
        cout << "\t ----------------- \n";
        cout << "\t| Enter new price |\n";
        cout << "\t ----------------- \n";
        dTmp = doubleExeption();
        try {
            setPrice(dTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 7:
        cout << "\t ------------------------- \n";
        cout << "\t| Enter new copies number |\n";
        cout << "\t ------------------------- \n";
        intTmp = IntExeption();
        try {
            setCopiesNumber(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 0: break;
    default:
        cout << "\t -------------------------------------------- \n";
        cout << "\t| Ñheck the correctness of the entered data! |\n";
        cout << "\t -------------------------------------------- \n\n";
        break;
    }
}

void Magazine::saveToTxt(ofstream& file) const
{
    file << type() << endl;
    file << bookCode << endl;
    file << genre << endl;
    file << publishingHouse << endl;
    file << receiptDate.getYear() << " ";
    file << receiptDate.getMonth() << " ";
    file << receiptDate.getDay() << endl;
    file << pagesNumber << endl;
    file << price << endl;
    file << copiesNumber << endl;
    file << edition << endl;
}

void Magazine::loadFromTxt(ifstream& file)
{
    int a = 0, b = 0, c = 0;
    getline(file, bookCode);
    getline(file, genre);
    getline(file, publishingHouse);
    file >> a >> b >> c;
    setReceiptDate(Date(a, b, c));
    file >> pagesNumber >> price >> copiesNumber >> edition;
}
