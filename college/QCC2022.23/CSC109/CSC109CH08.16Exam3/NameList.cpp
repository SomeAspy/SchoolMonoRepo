#include "NameList.h"
#include <iostream>

using std::cout;

NameList::NameList() : head(nullptr), tail(nullptr)
{
}

void NameList::push_front(NameNode *node)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->setNext(head);
        head = node;
    }
}

void NameList::push_back(NameNode *node)
{
    if (tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        tail = node;
    }
}

void NameList::print()
{
    NameNode *current = head;
    while (current != nullptr)
    {
        current->printdata();
        current = current->getNext();
    }
}

NameList::~NameList()
{
    NameNode *current = head;
    while (current != nullptr)
    {
        cout << "delete \n";
        current->printdata();
        NameNode *temp = current;
        current = current->getNext();
        delete temp;
    }
}

void NameList::setTail(NameNode *node)
{
    tail = node;
}

NameNode *NameList::getTail() const
{
    return tail;
}

void NameList::setHead(NameNode *node)
{
    head = node;
}

NameNode *NameList::getHead() const
{
    return head;
}
