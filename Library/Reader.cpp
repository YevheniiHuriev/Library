#include "Reader.h"
#include "PublicationException.h"

Reader::Reader()
{
    name = "empty";
}
Reader::Reader(string name)
{
    id = to_string(idCounter);
    idCounter++;
    this->name = name;
}

void Reader::addPublication(Publication* obj)
{
    publications.push_back(obj);
}

void Reader::takePublication(Publication* obj)
{
    if (obj == nullptr)
    {
        throw new TakeException;
    }
    int isExist = 0;
    for (int i = 0; i < publications.size(); i++)
    {
        if (publications[i]->getBookCode() == obj->getBookCode())
        {
            isExist++;
        }
    }
    if (isExist != 0)
    {
        for (int i = 0; i < publications.size(); i++)
        {
            if (publications[i]->getBookCode() == obj->getBookCode())
            {
                try {
                    publications[i]->setCopiesNumber(publications[i]->getCopiesNumber() + 1);
                }
                catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
            }
        }
    }
    else
    {
        publications.push_back(obj);

        for (int i = 0; i < publications.size(); i++)
        {
            if (publications[i]->getBookCode() == obj->getBookCode())
            {
                try {
                    publications[i]->setCopiesNumber(1);
                }
                catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
            }
        }
    }
}

Publication* Reader::returnPublication(string bookCode)
{
    auto item = find_if(publications.begin(), publications.end(), [bookCode](Publication* x) {return x->getBookCode() == bookCode; });
    if (item == publications.end())
    {
        return nullptr;
    }
    else
    {
        Publication* it = *item;
        for (int i = 0; i < publications.size(); i++)
        {
            if (publications[i]->getBookCode() == bookCode)
            {
                if (publications[i]->getCopiesNumber() > 1)
                {
                    try {
                        publications[i]->setCopiesNumber(publications[i]->getCopiesNumber() - 1);
                    }
                    catch (PublicationException* err) { cout << "\t" << err->Message() << endl; }
                }
                else
                {
                    publications.erase(item);
                }
            }
        }
        return it;
    }
}

string Reader::getId() const
{
    return id;
}

string Reader::getName() const
{
    return name;
}
int Reader::getAmountPublications() const
{
    return publications.size();
}

void Reader::showInfo() const
{
    cout << "|| Reader code: " << id << "        | " << "Name: " << setw(15) << name << "|| \n";
    cout << "  ============================================== \n";
    cout << "\t  ---------------------------------------------- \n";
    for (auto it : publications)
    {
        if (it->type() == "Magazine")
        {
            cout << "\t||" << setw(10) << it->getBookCode() << "\t|" << setw(2) << it->type() << "| " << setw(15) << it->getPublishingHouse() << " | " << setw(3) << it->getCopiesNumber() << "||\n";
            cout << "\t  ---------------------------------------------- \n";
        }
        else
        {
            cout << "\t||" << setw(10) << it->getBookCode() << "\t|" << setw(5) << it->type() << "\t | " << setw(15) << it->getTitle() << " | " << setw(3) << it->getCopiesNumber() << "||\n";
            cout << "\t  ---------------------------------------------- \n";
        }
    }
}

void Reader::savePublication(ofstream& file)const
{
    for (const Publication* obj : publications)
    {
        file << getName() << endl;
        obj->saveToTxt(file);
    }
}
