#include <bits/stdc++.h>

using namespace std;

class Product {
private:
    string name;
    float price;
    static int totalProducts; // Static member

public:
    Product(string n, float p) {
        name = n;
        price = p;
        totalProducts++;
    }

    // Inline function to display product price
    inline void showPrice() {
        cout << "Price of " << name << ": $" << price << endl;
    }

    // Static function to get total product count
    static void showTotal() {
        cout << "Total products in store: " << totalProducts << endl;
    }

    // Friend function declaration
    friend void applyDiscount(Product &p, float percent);
};

// Initializing static member
int Product::totalProducts = 0;

// Friend function definition
void applyDiscount(Product &p, float percent) {
    p.price -= (p.price * (percent / 100));
    cout << "Discount applied! New price for " << p.name << ": $" << p.price << endl;
}

int main() {
    Product p1("Gaming Mouse", 50.0);
    Product p2("Mechanical Keyboard", 120.0);

    Product::showTotal(); // Calling static function

    p1.showPrice(); // Calling inline function

    applyDiscount(p1, 10); // Calling friend function

    return 0;
}
