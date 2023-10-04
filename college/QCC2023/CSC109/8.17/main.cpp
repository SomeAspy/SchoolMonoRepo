#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main()
{
    // References for MileageTrackerNode objects
    MileageTrackerNode *headNode;
    MileageTrackerNode *currNode;
    MileageTrackerNode *lastNode;

    double miles;
    string date;

    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;

    // TODO: Read in the number of nodes
    unsigned int nodeCount;
    cin >> nodeCount;

    // TODO: For the read in number of nodes, read
    //       in data and insert into the linked list
    lastNode = headNode;
    for (unsigned int i = 0; i < nodeCount; ++i)
    {
        cin >> miles;
        cin >> date;
        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }

    // TODO: Call the PrintNodeData() method
    //       to print the entire linked list
    currNode = headNode->GetNext();
    for (unsigned int i = 0; i < nodeCount; ++i)
    {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }

    // MileageTrackerNode Destructor deletes all
    //       following nodes
    delete headNode;
    return 0;
}