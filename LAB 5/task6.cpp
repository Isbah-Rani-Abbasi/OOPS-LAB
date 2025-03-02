#include <iostream>
#include <string>

using namespace std;

struct MenuItem {
    string name;
    string type;
    int price;
};

class CoffeeShop {
private:
    const string name;
    MenuItem menu[5];
    string order[10];
    int order_count;
    int menu_count;

public:
    CoffeeShop(string name, MenuItem m[5], int menu_count) : name(name), menu_count(menu_count) {
        for (int i = 0; i < menu_count; i++) {
            menu[i] = m[i];
        }
        order_count = 0;
        for (int i = 0; i < 10; i++) {
            order[i] = "null";
        }
    }

    void addOrder(string orderName) {
        bool check = false;
        for (int i = 0; i < menu_count; i++) {
            if (orderName == menu[i].name) {
                check = true;
                break;
            }
        }
        if (check && order_count < 10) {
            order[order_count++] = orderName;
        } else {
            cout << orderName<<" is currently unavailable!" << endl;
        }
    }

    void fulfillOrder() {
        if (order_count > 0) {
            cout << "The " << order[0] << " is ready!" << endl;
            for (int i = 0; i < order_count - 1; i++) {
                order[i] = order[i + 1];
            }
            order[order_count - 1] = "null";
            order_count--;
        } else {
            cout << "All orders have been fulfilled" << endl;
        }
    }

    void listOrders() {
        if (order_count == 0) {
            cout << "[]" << endl;
        } else {
            cout << "[";
            for (int i = 0; i < order_count; i++) {
                cout << "\"" << order[i] << "\"";
                if (i < order_count - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }

    float dueAmount() {
        float total = 0;
        for (int i = 0; i < order_count; i++) {
            for (int j = 0; j < menu_count; j++) {
                if (order[i] == menu[j].name) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu_count == 0) {
            return "No items on the menu.";
        }
        int cheapestPrice = menu[0].price;
        string cheapestName = menu[0].name;
        for (int i = 1; i < menu_count; i++) {
            if (menu[i].price < cheapestPrice) {
                cheapestPrice = menu[i].price;
                cheapestName = menu[i].name;
            }
        }
        return cheapestName;
    }

    void drinksOnly() {
        cout << "[";
        bool first = true;
        for (int i = 0; i < menu_count; i++) {
            if (menu[i].type == "drink") {
                if (!first) {
                    cout << ", ";
                }
                cout << "\"" << menu[i].name << "\"";
                first = false;
            }
        }
        cout << "]" << endl;
    }

    void foodOnly() {
        cout << "[";
        bool first = true;
        for (int i = 0; i < menu_count; i++) {
            if (menu[i].type == "food") {
                if (!first) {
                    cout << ", ";
                }
                cout << "\"" << menu[i].name << "\"";
                first = false;
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    MenuItem menuItems[5] = {
        {"Cappuccino", "drink", 50},
        {"Latte", "drink", 60},
        {"Croissant", "food", 40},
        {"Muffin", "food", 35},
        {"Tea","drink",20}
    };

    CoffeeShop shop("My Coffee Shop", menuItems, 5);

    shop.addOrder("Cappuccino");
    shop.addOrder("Croissant");
    shop.addOrder("Latte");
    shop.addOrder("IceCream");

    shop.listOrders();

    shop.fulfillOrder();
    shop.fulfillOrder();

    shop.listOrders();

    cout << "Due Amount: " << shop.dueAmount() << endl;

    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    cout << "Drinks Only: ";
    shop.drinksOnly();

    cout << "Food Only: ";
    shop.foodOnly();

    return 0;
}
