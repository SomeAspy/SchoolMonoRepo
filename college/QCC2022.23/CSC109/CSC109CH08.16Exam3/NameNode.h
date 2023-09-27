#ifndef NAMENODE_H
#define NAMENODE_H
#include <string>

using std::string;

class NameNode
{
public:
    NameNode();                     // default constructor
    NameNode(string name, int age); // set name and age constructor
    void printdata();               // print out name and age.  One line each
    NameNode *getNext();            // return the next pointer
    void setNext(NameNode *node);
    void setAge(int age);
    int getAge() const;
    void setName(string name);
    string getName() const; // set next pointer to the node

private:
    string name;    // name
    int age;        // age
    NameNode *next; // next pointer
};

#endif /* NAMENODE_H */
