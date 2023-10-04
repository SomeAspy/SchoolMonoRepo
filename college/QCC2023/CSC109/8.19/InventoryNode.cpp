// Copyright 2023
#include "InventoryNode.h"
using std::cout;

InventoryNode::InventoryNode()
{
    nextNodeRef = nullptr;
}

InventoryNode::InventoryNode(string itemInit, int numberOfItemsInit)
{
    item = itemInit;
    numberOfItems = numberOfItemsInit;
    nextNodeRef = nullptr;
}

InventoryNode::InventoryNode(string itemInit, int numberOfItemsInit, InventoryNode *nextLoc)
{
    item = itemInit;
    numberOfItems = numberOfItemsInit;
    nextNodeRef = nextLoc;
}

InventoryNode *InventoryNode::GetNext()
{
    return nextNodeRef;
}

void InventoryNode::PrintNodeData()
{
    cout << numberOfItems << ' ' << item << '\n';
}

void InventoryNode::InsertAtFront(InventoryNode *head, InventoryNode *b)
{
    InventoryNode *originalNext = head->GetNext();
    nextNodeRef = originalNext;
    head->nextNodeRef = this;
}

int InventoryNode::GetNumberOfItems()
{
    return numberOfItems;
}

string InventoryNode::GetItem()
{
    return item;
}
