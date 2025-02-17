#include <iostream>
#include <string>
#include <iomanip> // For setprecision

using namespace std;

const int MAX_MENU_ITEMS = 100;
const int MAX_ORDERS = 100;

struct MenuItem {
    string item;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    MenuItem menu[MAX_MENU_ITEMS];
    int menuSize = 0;
    string orders[MAX_ORDERS];
    int orderSize = 0;

public:
    CoffeeShop(string shopName) : name(shopName) {}

    void addMenuItem(const MenuItem& menuItem) {
        if (menuSize < MAX_MENU_ITEMS) {
            menu[menuSize++] = menuItem;
        } else {
            cout << "Menu is full. Cannot add more items." << endl;
        }
    }

    string addOrder(const string& itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].item == itemName) {
                if (orderSize < MAX_ORDERS) {
                    orders[orderSize++] = itemName;
                    return "";
                } else {
                    return "Maximum number of orders reached.";
                }
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (orderSize > 0) {
            string item = orders[0];
            for (int i = 0; i < orderSize - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderSize--;
            return "The " + item + " is ready";
        } else {
            return "All orders have been fulfilled";
        }
    }

    string* listOrders(int& orderCount) const {
        if (orderSize == 0) {
            orderCount = 0;
            return nullptr;
        }

        string* orderList = new string[orderSize];
        for (int i = 0; i < orderSize; ++i) {
            orderList[i] = orders[i];
        }
        orderCount = orderSize;
        return orderList;
    }

    double dueAmount() const {
        double total = 0.0;
        for (int i = 0; i < orderSize; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].item == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        if (menuSize == 0) return "";

        string cheapest = menu[0].item;
        double minPrice = menu[0].price;

        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < minPrice) {
                minPrice = menu[i].price;
                cheapest = menu[i].item;
            }
        }
        return cheapest;
    }

    string* drinksOnly(int& drinkCount) const {
        drinkCount = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                drinkCount++;
            }
        }
        if (drinkCount == 0) return nullptr;

        string* drinks = new string[drinkCount];
        int j = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                drinks[j++] = menu[i].item;
            }
        }
        return drinks;
    }

    string* foodOnly(int& foodCount) const {
        foodCount = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                foodCount++;
            }
        }
        if (foodCount == 0) return nullptr;

        string* food = new string[foodCount];
        int j = 0;
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                food[j++] = menu[i].item;
            }
        }
        return food;
    }
};

int main() {
    CoffeeShop shop("My Coffee Shop");

    // Input menu items from the user:
    int numMenuItems;
    cout << "Enter the number of menu items: ";
    cin >> numMenuItems;
    cin.ignore(); // Consume the newline left by cin

    for (int i = 0; i < numMenuItems; i++) {
        MenuItem item;
        cout << "Enter item name: ";
        getline(cin, item.item);
        cout << "Enter item type (food or drink): ";
        getline(cin, item.type);
        cout << "Enter item price: ";
        cin >> item.price;
        cin.ignore(); // Consume the newline
        shop.addMenuItem(item);
    }


    char choice;
    do {
        cout << "\nCoffee Shop Menu\n";
        cout << "1. Add Order\n";
        cout << "2. Fulfill Order\n";
        cout << "3. List Orders\n";
        cout << "4. Due Amount\n";
        cout << "5. Cheapest Item\n";
        cout << "6. Drinks Only\n";
        cout << "7. Food Only\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Consume the newline

        switch (choice) {
            case '1': {
                string itemName;
                cout << "Enter item name to order: ";
                getline(cin, itemName);
                cout << shop.addOrder(itemName) << endl;
                break;
            }
            case '2':
                cout << shop.fulfillOrder() << endl;
                break;
            case '3': {
                int orderCount;
                string* orders = shop.listOrders(orderCount);
                cout << "Orders: ";
                if (orders == nullptr) {
                    cout << "Empty" << endl;
                } else {
                    for (int i = 0; i < orderCount; ++i) {
                        cout << orders[i] << " ";
                    }
                    cout << endl;
                    delete[] orders;
                }
                break;
            }
            case '4':
                cout << "Due Amount: $" << fixed << setprecision(2) << shop.dueAmount() << endl;
                break;
            case '5':
                cout << "Cheapest Item: " << shop.cheapestItem() << endl;
                break;
            case '6': {
                int drinkCount;
                string* drinks = shop.drinksOnly(drinkCount);
                cout << "Drinks: ";
                if (drinks == nullptr) {
                    cout << "Empty" << endl;
                } else {
                    for (int i = 0; i < drinkCount; i++) {
                        cout << drinks[i] << " ";
                    }
                    cout << endl;
                    delete[] drinks;
                }
                break;
            }
            case '7': {
                int foodCount;
                string* food = shop.foodOnly(foodCount);
                cout << "Food: ";
                if (food == nullptr) {
                    cout << "Empty" << endl;
                } else {
                    for (int i = 0; i < foodCount; i++) {
                        cout << food[i] << " ";
                    }
                    cout << endl;
                    delete[] food;
                }
                break;
            }
            case '8':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '8');

    return 0;
}