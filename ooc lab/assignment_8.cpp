//1032233447
//Shivank Tripathi

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Item {
public:
    int Item_Code;
    string Item_Name;
    int Item_Quantity;
    double Item_Price;

    Item(int code, string name, int quantity, double price)
        : Item_Code(code), Item_Name(name), Item_Quantity(quantity), Item_Price(price) {}
};

class Inventory {
private:
    list<Item> items;

public:
    void addItem(int code, string name, int quantity, double price) {
        items.emplace_back(code, name, quantity, price);
    }

    void displayItems() {
        for (const auto& item : items) {
            cout << "Code: " << item.Item_Code << ", Name: " << item.Item_Name
                 << ", Quantity: " << item.Item_Quantity << ", Price: " << item.Item_Price << endl;
        }
    }

    void searchItem(int code) {
        auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
            return item.Item_Code == code;
        });

        if (it != items.end()) {
            cout << "Item found: Code: " << it->Item_Code << ", Name: " << it->Item_Name
                 << ", Quantity: " << it->Item_Quantity << ", Price: " << it->Item_Price << endl;
        } else {
            cout << "Requested Item is not available" << endl;
        }
    }

    void purchaseItem(int code, int quantity) {
        auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
            return item.Item_Code == code;
        });

        if (it != items.end()) {
            if (it->Item_Quantity >= quantity) {
                double totalCost = quantity * it->Item_Price;
                it->Item_Quantity -= quantity;
                cout << "Purchase successful. Total cost: " << totalCost << endl;
            } else {
                cout << "Required item's Quantity is not in stock" << endl;
            }
        } else {
            cout << "Requested Item is not available" << endl;
        }
    }

    void updateItem(int code, int newQuantity, double newPrice) {
        auto it = find_if(items.begin(), items.end(), [code](const Item& item) {
            return item.Item_Code == code;
        });

        if (it != items.end()) {
            it->Item_Quantity = newQuantity;
            it->Item_Price = newPrice;
            cout << "Item updated successfully" << endl;
        } else {
            cout << "Requested Item is not available" << endl;
        }
    }

    void deleteItem(int code) {
        items.remove_if([code](const Item& item) {
            return item.Item_Code == code;
        });
        cout << "Item deleted successfully" << endl;
    }

    void sortItemsByCode() {
        items.sort([](const Item& a, const Item& b) {
            return a.Item_Code < b.Item_Code;
        });
    }
};

int main() {
    Inventory inventory;
    int choice, code, quantity;
    double price;
    string name;

    while (true) {
        cout << "1. Add Item\n2. Display Items\n3. Search Item\n"
             << "4. Purchase Item\n5. Update Item\n6. Delete Item\n7. Sort Items\n"
             << "8. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter code, name, quantity, price: ";
                cin >> code >> name >> quantity >> price;
                inventory.addItem(code, name, quantity, price);
                break;
            case 2:
                inventory.displayItems();
                break;
            case 3:
                cout << "Enter code: ";
                cin >> code;
                inventory.searchItem(code);
                break;
            case 4:
                cout << "Enter code and quantity: ";
                cin >> code >> quantity;
                inventory.purchaseItem(code, quantity);
                break;
            case 5:
                cout << "Enter code, new quantity, new price: ";
                cin >> code >> quantity >> price;
                inventory.updateItem(code, quantity, price);
                break;
            case 6:
                cout << "Enter code: ";
                cin >> code;
                inventory.deleteItem(code);
                break;
            case 7:
                inventory.sortItemsByCode();
                break;
            case 8:
                cout << "Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
