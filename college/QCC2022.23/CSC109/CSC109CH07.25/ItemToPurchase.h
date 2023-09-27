#define CSC109CH0725_ITEMTOPURCHASE_H
#include <string>
using std::string;
class ItemToPurchase
{
public:
    ItemToPurchase();
    void SetName(string itemName);
    string GetName();
    void SetPrice(int itemPrice);
    int GetPrice();
    void SetQuantity(int itemQuantity);
    int GetQuantity();

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
};
