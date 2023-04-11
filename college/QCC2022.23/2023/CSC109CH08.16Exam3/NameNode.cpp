#include "NameNode.h"
#include <iostream>

using std::cout;

NameNode::NameNode() : name(""), age(0), next(nullptr)
{
}

NameNode::NameNode(string name, int age) : name(name), age(age), next(nullptr)
{
}

void NameNode::printdata()
{
    cout << name << '\n';
    cout << age << '\n';
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
