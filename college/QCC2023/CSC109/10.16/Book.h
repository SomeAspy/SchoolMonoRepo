// Copyright 2023
#ifndef BOOKH
#define BOOKH

#include <string>

using std::string;

class Book
{
public:
    void SetTitle(string userTitle);

    string GetTitle();

    void SetAuthor(string userAuthor);

    string GetAuthor();

    void SetPublisher(string userPublisher);

    string GetPublisher();

    void SetPublicationDate(string userPublicationDate);

    string GetPublicationDate();

    void PrintInfo();

protected:
    string title;
    string author;
    string publisher;
    string publicationDate;
};

#endif
