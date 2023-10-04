// Copyright 2023
#ifndef MILEAGETRACKERNODEH
#define MILEAGETRACKERNODEH

#include <string>
using std::string;

class MileageTrackerNode
{
public:
    // Constructor
    MileageTrackerNode();

    // Destructor
    ~MileageTrackerNode();

    // Constructor
    MileageTrackerNode(double milesInit, string dateInit);

    // Constructor
    MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode *nextLoc);

    /* Insert node after this node.
    Before: this -- next
    After:  this -- node -- next
    */
    void InsertAfter(MileageTrackerNode *nodeLoc);

    // Get location pointed by nextNodeRef
    MileageTrackerNode *GetNext();

    void PrintNodeData();

    string GetDate();

    double GetMiles();

private:
    double miles;                    // Node data
    string date;                     // Node data
    MileageTrackerNode *nextNodeRef; // Reference to the next node
};

#endif
