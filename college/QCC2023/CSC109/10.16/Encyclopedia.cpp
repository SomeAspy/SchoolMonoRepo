// Copyright 2023
#include "Encyclopedia.h"
#include <iostream>

using std::cout;
using std::endl;

// Define functions declared in Encyclopedia.h
void Encyclopedia::SetEdition(string edition)
{
    this->edition = edition;
}

void Encyclopedia::SetNumPages(int pages)
{
    this->pages = pages;
}

void Encyclopedia::SetNumVolumes(int volumes)
{
    this->volumes = volumes;
}

string Encyclopedia::GetEdition() const
{
    return edition;
}

int Encyclopedia::GetNumPages() const
{
    return pages;
}

int Encyclopedia::GetNumVolumes() const
{
    return volumes;
}

void Encyclopedia::PrintInfo() const
{
    cout << "Book Information: " << endl;
    cout << "   Book Title: " << title << endl;
    cout << "   Author: " << author << endl;
    cout << "   Publisher: " << publisher << endl;
    cout << "   Publication Date: " << publicationDate << endl;
    cout << "   Edition: " << edition << endl;
    cout << "   Number of Pages: " << pages << endl;
    cout << "   Number of Volumes: " << volumes << endl;
}
