// Copyright 2023
#include "ItemNode.h"
using std::cout;

// TODO: Implement your source code here
ItemNode::ItemNode()
{
    nextNodeRef = nullptr;
}

ItemNode::ItemNode(string itemInit)
{
    item = itemInit;
    nextNodeRef = nullptr;
}

ItemNode::ItemNode(string itemInit, ItemNode *nextLoc)
{
    item = itemInit;
    nextNodeRef = nextLoc;
}

void ItemNode::InsertAfter(ItemNode *nodeLoc)
{
    nextNodeRef = nodeLoc;
}

void ItemNode::InsertAtEnd(ItemNode *head, ItemNode *b)
{
    nextNodeRef = b;
}

ItemNode *ItemNode::GetNext()
{
    return nextNodeRef;
}

string ItemNode::GetItem() const
{
    return item;
}

void ItemNode::PrintNodeData()
{
    cout << item << '\n';
}
