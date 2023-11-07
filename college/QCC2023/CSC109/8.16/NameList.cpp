#include "NameList.h"
#include <iostream>

using std::cout;

NameList::NameList()
{
    head = new NameNode();
    tail = new NameNode();
}

NameList::NameList(const NameList &origList)
{
    // TODO - IMPLEMENT
}

NameList &NameList::operator=(const NameList &origList)
{
    // TODO - IMPLEMENT
}

void NameList::push_front(NameNode *node)
{
    head->setName(node->getName());
    head->setAge(node->getAge());
    if (tail->getName() == "none")
    {
        tail->setName(node->getName());
        tail->setAge(node->getAge());
    }
}

void NameList::push_back(NameNode *node)
{
    tail->setNext(node);
    tail = node;
}

NameNode *NameList::getHead() const
{
    return head;
}

NameNode *NameList::getTail() const
{
    return tail;
}

void NameList::print()
{
    NameNode *currNode = head->getNext();
    while (currNode != nullptr)
    {
        currNode->printdata();
        currNode = currNode->getNext();
    }
}

NameList::~NameList()
{
    // TODO - IMPLEMENT
}

/*!SECTION

2 = push front , get head

3 = push back , get head

4 = push back , get head

5 = push back , get head

6 = copy

7 = assign

code = 2232

*/