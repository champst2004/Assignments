#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class Items {
public:
    int Item_Code;
    string Item_Name;
    int Item_Quantity;
    float Item_Price;

    Items(int code, string name, int quantity, float price) 
        : Item_Code(code), Item_Name(name), Item_Quantity(quantity), Item_Price(price) {}

    void display() const {
        cout << "Item Code: " << Item_Code << "\n";
        cout << "Item Name: " << Item_Name << "\n";
        cout << "Item Quantity: " << Item_Quantity << "\n";
        cout << "Item Price per Unit: " << Item_Price << "\n";
    }
};

bool compareByCode(const Items& a, const Items& b) {
    return a.Item_Code < b.Item_Code;
}

bool compareByName(const Items& a, const Items& b) {
    return a.Item_Name < b.Item_Name;
}

class InventorySystem {
private:
    list<Items> inventory;

public:
    void addItem(int code, string name, int quantity, float price) {
        Items newItem(code, name, quantity, price);
        inventory.push_back(newItem);
    }

    void searchItem(int code = -1, string name = "") {
        bool found = false;
        for (const auto& item : inventory) {
            if (item.Item_Code == code || item.Item_Name == name) {
                cout << "Item Found!\n";
                item.display();
                found = true;
                return;
            }
        }
        if (!found)
            cout << "Requested Item is not available\n";
    }

    void purchaseItem(int code, int quantity) {
        for (auto& item : inventory) {
            if (item.Item_Code == code) {
                if (item.Item_Quantity >= quantity) {
                    float totalCost = quantity * item.Item_Price;
                    item.Item_Quantity -= quantity;
                    cout << "Item Purchased Successfully!\n";
                    cout << "Total Bill: " << totalCost << "\n";
                } else {
                    cout << "Required item's Quantity is not in stock\n";
                }
                return;
            }
        }
        cout << "Item not found\n";
    }

    void deleteItem(int code) {
        auto it = find_if(inventory.begin(), inventory.end(), [code](const Items& item) {
            return item.Item_Code == code;
        });
        if (it != inventory.end()) {
            inventory.erase(it);
            cout << "Item removed successfully!\n";
        } else {
            cout << "Item not found!\n";
        }
    }

    void displayAll() {
        cout << "Current Inventory:\n";
        for (const auto& item : inventory) {
            item.display();
            cout << "-------------------------\n";
        }
    }

    void sortInventory(int option) {
        if (option == 1) {
            inventory.sort(compareByCode);
            cout << "Items sorted by Item Code\n";
        } else if (option == 2) {
            inventory.sort(compareByName);
            cout << "Items sorted by Item Name\n";
        }
    }
};

int main() {
    InventorySystem system;
    int choice;

    do {
        cout << "\n=== Inventory System Menu ===\n";
        cout << "1. Add Item\n";
        cout << "2. Search Item\n";
        cout << "3. Purchase Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Display All Items\n";
        cout << "6. Sort Items\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int code, quantity;
                float price;
                string name;
                cout << "Enter Item Code: ";
                cin >> code;
                cout << "Enter Item Name: ";
                cin >> name;
                cout << "Enter Item Quantity: ";
                cin >> quantity;
                cout << "Enter Item Price per Unit: ";
                cin >> price;
                system.addItem(code, name, quantity, price);
                break;
            }
            case 2: {
                int searchOption;
                cout << "Search by: 1. Code 2. Name: ";
                cin >> searchOption;
                if (searchOption == 1) {
                    int code;
                    cout << "Enter Item Code: ";
                    cin >> code;
                    system.searchItem(code);
                } else {
                    string name;
                    cout << "Enter Item Name: ";
                    cin >> name;
                    system.searchItem(-1, name);
                }
                break;
            }
            case 3: {
                int code, quantity;
                cout << "Enter Item Code: ";
                cin >> code;
                cout << "Enter Quantity: ";
                cin >> quantity;
                system.purchaseItem(code, quantity);
                break;
            }
            case 4: {
                int code;
                cout << "Enter Item Code to delete: ";
                cin >> code;
                system.deleteItem(code);
                break;
            }
            case 5: {
                system.displayAll();
                break;
            }
            case 6: {
                int sortOption;
                cout << "Sort by: 1. Code 2. Name: ";
                cin >> sortOption;
                system.sortInventory(sortOption);
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}