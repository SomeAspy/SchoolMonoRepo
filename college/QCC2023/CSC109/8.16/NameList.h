//
// Created by hloi on 4/6/2021.
//

#ifndef CSC109CH08_09EXAM_NAMELIST_H
#define CSC109CH08_09EXAM_NAMELIST_H
#include "NameNode.h"

class NameList
{
public:
    NameList();                         // set head and tail to nullptr
    NameList(const NameList &origList); // copy constructor

    NameList &operator=(const NameList &origList); // assignment operator

    void push_front(NameNode *node); // add the new node at the beginning of the linked list
    void push_back(NameNode *node);  // add the new node at the end of the linked list

    void print();              // use printdata from NameNode to print out the linked list
    virtual ~NameList();       // destructor of linked list.  Call printdata before you delete the node
    NameNode *getTail() const; // return the tail node of the linked list
    NameNode *getHead() const; // return the head node of the linked list
private:
    NameNode *head; // head of the linked list
    NameNode *tail; // tail of the linked list
};

#endif // CSC109CH08_09EXAM_NAMELIST_H
