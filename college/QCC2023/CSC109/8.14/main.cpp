#include <iostream>
using namespace std;

class ContactNode
{
public:
    string GetName();
    string GetPhoneNumber();
    void InsertAfter(ContactNode *next);
    ContactNode *GetNext();
    void PrintContactNode();
    ContactNode(string name, string num);

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode *nextNodePtr = nullptr;
};

ContactNode::ContactNode(string name, string num)
{
    contactName = name;
    contactPhoneNumber = num;
}

void ContactNode::PrintContactNode()
{
    cout << contactName << ", " << contactPhoneNumber << '\n';
}

string ContactNode::GetName()
{
    return contactName;
}
string ContactNode::GetPhoneNumber()
{
    return contactPhoneNumber;
}

ContactNode *ContactNode::GetNext()
{
    return nextNodePtr;
}

void ContactNode::InsertAfter(ContactNode *next)
{
    if (nextNodePtr == nullptr)
    {
        nextNodePtr = next;
    }
    else
    {
        ContactNode *temp = nextNodePtr;
        nextNodePtr = next;
        next->InsertAfter(temp);
    }
}

int main()
{
    ContactNode *head = new ContactNode("null", "null");
    ContactNode *temp = head;
    for (unsigned int i = 0; i < 3; ++i)
    {
        string name, num;
        getline(cin, name);
        cin >> num;
        cin.ignore();
        ContactNode *x = new ContactNode(name, num);
        temp->InsertAfter(x);
        temp = x;
    }
    temp = head->GetNext();
    unsigned int currentPerson = 1;
    while (true)
    {
        cout << "Person " << currentPerson << ": ";
        ++currentPerson;
        temp->PrintContactNode();
        if (temp->GetNext() == nullptr)
        {
            break;
        }
        temp = temp->GetNext();
    }
    temp = head->GetNext();
    cout << "\nCONTACT LIST\n";
    while (true)
    {
        cout << "Name: " << temp->GetName() << "\nPhone number: " << temp->GetPhoneNumber() << "\n\n";
        if (temp->GetNext() == nullptr)
        {
            break;
        }
        temp = temp->GetNext();
    }
    return 0;
}
