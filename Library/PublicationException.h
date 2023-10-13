#pragma once
#include <iostream>

using std::string;

class PublicationException
{
public:
	virtual string Message() = 0;
};

class BookCodeException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookTitleException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookAuthorException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookGenreException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookPublishingHouseException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookEditionException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookTomeException : public PublicationException
{
public:
	virtual string Message() override;
};
class ReceiptDateException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookPagesNumberException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookPriceException : public PublicationException
{
public:
	virtual string Message() override;
};
class BookCopiesNumberException : public PublicationException
{
public:
	virtual string Message() override;
};

class TakeException : public PublicationException
{
public:
	virtual string Message() override;
};
class NameException : public PublicationException
{
public:
	virtual string Message() override;
};