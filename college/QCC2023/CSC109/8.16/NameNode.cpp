#include "NameNode.h"
#include <iostream>
using std::cout;

NameNode::NameNode()
{
    next = nullptr;
    age = 0;
    name = "none";
}

NameNode::NameNode(string name, int age)
{
    next = nullptr;
    this->age = age;
    this->name = name;
}

void NameNode::printdata()
{
    cout << name << '\n'
         << age << '\n';
}

NameNode *NameNode::getNext()
{
    return next;
}

void NameNode::setNext(NameNode *node)
{
    next = node;
}

void NameNode::setAge(int age)
{
    this->age = age;
}

int NameNode::getAge() const
{
    return age;
}

void NameNode::setName(string name)
{
    this->name = name;
}

string NameNode::getName() const
{
    return name;
}