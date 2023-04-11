#ifndef NAMELIST_H
#define NAMELIST_H
#include "NameNode.h"

class NameList
{
public:
    NameList();                      // set head and tail to nullptr
    void push_front(NameNode *node); // add the new node at the beginning of the linked list
    void push_back(NameNode *node);  // add the new node at the end of the linked list

    void print();                 // use printdata from NameNode to print out the linked list
    virtual ~NameList();          // destructor of linked list.  Call printdata before you delete the node
    void setTail(NameNode *node); // set the tail to the new node
    NameNode *getTail() const;    // return the tail node of the linked list
    void setHead(NameNode *node); // the head to the new node
    NameNode *getHead() const;    // return the head node of the linked list
private:
    NameNode *head; // head of the linked list
    NameNode *tail; // tail of the linked list
};

#endif /* NAMELIST_H */
