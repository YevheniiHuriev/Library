#include "Publication.h"

Publication::Publication()
{
    title = "empty";
    author = "empty";
    genre = "empty";
    bookCode = "empty";
    publishingHouse = "empty";
    receiptDate = Date();
    pagesNumber = 0;
    price = 0;
    copiesNumber = 0;
}

Publication::Publication(string bookCode, string title, string author, string genre, string publishingHouse, Date receiptDate, int pagesNumber, double price, int copiesNumber)
{
    this->title = "empty";
    setTitle(title);
    this->author = "empty";
    setAuthor(author);
    this->genre = "empty";
    setGenre(genre);
    this->bookCode = "empty";
    setBookCode(bookCode);
    this->publishingHouse = "empty";
    setPublishingHouse(publishingHouse);
    this->receiptDate = Date();
    setReceiptDate(receiptDate);
    this->pagesNumber = 0;
    setPagesNumber(pagesNumber);
    this->price = 0;
    setPrice(price);
    this->copiesNumber = 0;
    setCopiesNumber(copiesNumber);
}

string Publication::getTitle() const
{
    return title;
}
string Publication::getAuthor() const
{
    return author;
}
string Publication::getGenre() const
{
    return genre;
}
string Publication::getBookCode() const
{
    return bookCode;
}
string Publication::getPublishingHouse() const
{
    return publishingHouse;
}
Date Publication::getReceiptDate() const
{
    return receiptDate;
}
int Publication::getPagesNumber() const
{
    return pagesNumber;
}
double Publication::getPrice() const
{
    return price;
}
int Publication::getCopiesNumber() const
{
    return copiesNumber;
}

void Publication::setTitle(string title)
{
    if (title.length() < 3)
    {
        throw new BookTitleException;
    }
    this->title = title;
}
void Publication::setAuthor(string author)
{
    if (author.length() < 3)
    {
        throw new BookAuthorException;
    }
    this->author = author;
}
void Publication::setGenre(string genre)
{
    if (genre.length() < 3)
    {
        throw new BookGenreException;
    }
    this->genre = genre;
}
void Publication::setBookCode(string bookCode)
{
    if (bookCode.length() < 4)
    {
        throw new BookCodeException;
    }
    this->bookCode = bookCode;
}
void Publication::setPublishingHouse(string publishingHouse)
{
    if (publishingHouse.length() < 4)
    {
        throw new BookPublishingHouseException;
    }
    this->publishingHouse = publishingHouse;
}
void Publication::setReceiptDate(Date receiptDate)
{
    if (receiptDate > Date())
    {
        throw new ReceiptDateException;
    }
    this->receiptDate = receiptDate;
}
void Publication::setPagesNumber(int pagesNumber)
{
    if (pagesNumber < 1)
    {
        throw new BookCopiesNumberException;
    }
    this->pagesNumber = pagesNumber;
}
void Publication::setPrice(double price)
{
    if (price < 1)
    {
        throw new BookPriceException;
    }
    this->price = price;
}
void Publication::setCopiesNumber(int copiesNumber)
{
    if (copiesNumber < 1)
    {
        throw new BookCopiesNumberException;
    }
    this->copiesNumber = copiesNumber;
}

int Publication::IntExeption()
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

double Publication::doubleExeption()
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


