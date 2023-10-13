#include "Book.h"

Book::Book()
{
    tome = 0;
}

Book::Book(string bookCode, string title, string author, string genre, string publishingHouse,  Date receiptDate, int pagesNumber, double price, int copiesNumber, int tome)
    :Publication(bookCode, title, author, genre, publishingHouse, receiptDate, pagesNumber, price, copiesNumber)
{
    this->tome = 0;
    setTome(tome);
}

int Book::getTome() const
{
    return tome;
}

void Book::setTome(int tome)
{
    if (tome < 1)
    {
        throw new BookTomeException;
    }
    this->tome = tome;
}

void Book::description() const
{
    cout << "\t||" << setw(13) << bookCode << " ||| "
        << setw(15) << title << " ||| "
        << setw(12) << author << " ||| "
        << setw(10) << genre << " ||| "
        << setw(15) << publishingHouse << " ||| "
        << setw(4) << tome << " ||| "
        << setw(7) << receiptDate << " ||| "
        << setw(12) << pagesNumber << " ||| "
        << setw(5) << price << " ||| ";
    cout << setw(13) << copiesNumber; cout << " ||\n";
    cout << "\t  ================================================================================================================================================================= \n";
}

string Book::type() const
{
    return "Book";
}

void Book::edit()
{
    int menu = 0; string strTmp; int intTmp; Date tmp; double dTmp;

    cout << "\n\t -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
    cout << "\t| 1 - title | >> 2 - author | >> 3 - genre | >> 4 - publising house | >> 5 - tome | >> 6 - receipt date | >> 7 - pages number | >> 8 - price | >> 9 - copies number | >> 0 - return to the previous menu |\n";
    cout << "\t -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
    cout << endl << ">> "; cin >> menu;
    switch (menu)
    {
    case 1:
        cout << "\t ----------------- \n";
        cout << "\t| Enter new title |\n";
        cout << "\t ----------------- \n";
        cout << endl << " >> ";
        cin.ignore();
        getline(cin, strTmp);
        try {
            setTitle(strTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 2:
        cout << "\t ------------------ \n";
        cout << "\t| Enter new author |\n";
        cout << "\t ------------------ \n";
        cout << endl << " >> ";
        cin.ignore();
        getline(cin, strTmp);
        try {
            setAuthor(strTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 3:
        cout << "\t ----------------- \n";
        cout << "\t| Enter new genre |\n";
        cout << "\t ----------------- \n";
        cout << endl << " >> ";
        cin.ignore();
        getline(cin, strTmp);
        try {
            setGenre(strTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 4:
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
    case 5:
        cout << "\t ---------------- \n";
        cout << "\t| Enter new tome |\n";
        cout << "\t ---------------- \n";
        intTmp = IntExeption();
        try {
            setTome(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 6:
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
    case 7:
        cout << "\t ------------------------ \n";
        cout << "\t| Enter new pages number |\n";
        cout << "\t ------------------------ \n";
        intTmp = IntExeption();
        try {
            setPagesNumber(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 8:
        cout << "\t ----------------- \n";
        cout << "\t| Enter new price |\n";
        cout << "\t ----------------- \n";
        dTmp = doubleExeption();
        try {
            setPrice(dTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
        break;
    case 9:
        cout << "\t ------------------------- \n";
        cout << "\t| Enter new copies number |\n";
        cout << "\t ------------------------- \n";
        intTmp = IntExeption();
        try {
            setCopiesNumber(intTmp);
        }
        catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
    case 0: break;
        break;
    default:
        cout << "\t -------------------------------------------- \n";
        cout << "\t| Ñheck the correctness of the entered data! |\n";
        cout << "\t -------------------------------------------- \n\n";
        break;
    }
}

void Book::saveToTxt(ofstream& file) const
{
    file << type() << endl;
    file << bookCode << endl;
    file << title << endl;
    file << author << endl;
    file << genre << endl;
    file << publishingHouse << endl;
    file << receiptDate.getYear() << " ";
    file << receiptDate.getMonth() << " ";
    file << receiptDate.getDay() << endl;
    file << pagesNumber << endl;
    file << price << endl;
    file << copiesNumber << endl;
    file << tome << endl;
}

void Book::loadFromTxt(ifstream& file)
{
    int a = 0, b = 0, c = 0;
    getline(file, bookCode);
    getline(file, title);
    getline(file, author);
    getline(file, genre);
    getline(file, publishingHouse);
    file >> a >> b >> c;
    setReceiptDate(Date(a, b, c));
    file >> pagesNumber >> price >> copiesNumber >> tome;
}

