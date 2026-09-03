#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // 1. Default Constructor
    Rectangle() {
        length = 0;
        width = 0;
        cout << "Default Constructor called." << endl;
    }

    // 2. Parameterized Constructor
    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout << "Parameterized Constructor called." << endl;
    }

    // 3. Copy Constructor
    Rectangle(const Rectangle &obj) {
        length = obj.length;
        width = obj.width;
        cout << "Copy Constructor called." << endl;
    }

    // Destructor
    ~Rectangle() {
        cout << "Destructor called: Object is being destroyed." << endl;
    }

    // Member function to calculate area
    double area() {
        return length * width;
    }
};

int main() {
    // Create object using default constructor
    Rectangle r1;
    cout << "Area 1: " << r1.area() << endl << endl;

    // Create object using parameterized constructor
    Rectangle r2(10.5, 5.0);
    cout << "Area 2: " << r2.area() << endl << endl;

    // Create object using copy constructor
    Rectangle r3 = r2;
    cout << "Area 3 (Copied): " << r3.area() << endl << endl;

    return 0;
}
