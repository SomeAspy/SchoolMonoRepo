#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl; // zybooks needs this
using std::getline;
using std::string;

// why the fuck we doing this in main.cpp

class ContactNode
{
public:
    string GetName();
    string GetPhoneNumber();
    void InsertAfter(ContactNode *CN);
    ContactNode *GetNext();
    void PrintContactNode();
    ContactNode(string contactName, string contactPhoneNumber);

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode *nextNodePtr;
};

/* Define member functions here */

string ContactNode::GetName()
{
    return contactName;
}

string ContactNode::GetPhoneNumber()
{
    return contactPhoneNumber;
}

void ContactNode::InsertAfter(ContactNode *CN)
{
    ContactNode *beforeNext = nextNodePtr;
    if (beforeNext != nullptr)
    {
        CN->nextNodePtr = beforeNext;
    }
    nextNodePtr = CN;
}

ContactNode *ContactNode::GetNext()
{
    return nextNodePtr;
}

void ContactNode::PrintContactNode()
{
    cout << "Name: " << contactName << '\n';
    cout << "Phone Number: " << contactPhoneNumber << '\n';
    nextNodePtr = nullptr;
}

ContactNode::ContactNode(string contactName, string contactPhoneNumber)
{
    this->contactName = contactName;
    this->contactPhoneNumber = contactPhoneNumber;
}

int main()
{
    string cn, cpn;
    getline(cin, cn);
    cin >> cpn;
    ContactNode *c1 = new ContactNode(cn, cpn);

    getline(cin, cn);
    cin >> cpn;
    ContactNode *c2 = new ContactNode(cn, cpn);

    getline(cin, cn);
    cin >> cpn;
    ContactNode *c3 = new ContactNode(cn, cpn);

    c1->InsertAfter(c2);
    c2->InsertAfter(c3);

    ContactNode *current = c1;
    // while (current != nullptr)
    // {
    //     current->PrintContactNode();
    //     current = current->GetNext();
    // }

    cout << "Person 1: " << current->GetName() << ", " << current->GetPhoneNumber() << '\n';
    current = current->GetNext();
    cout << "Person 2: " << current->GetName() << ", " << current->GetPhoneNumber() << '\n';
    current = current->GetNext();
    cout << "Person 3: " << current->GetName() << ", " << current->GetPhoneNumber() << '\n';
    return 0;
}
