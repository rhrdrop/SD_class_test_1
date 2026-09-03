#include <bits/stdc++.h>
using namespace std;

class Coordinate {
private:
    int x, y;

public:
    // Constructor
    Coordinate(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Method 1: Overloading '+' using a Member Function
    Coordinate operator+(const Coordinate& other) {
        Coordinate temp;
        temp.x = this->x + other.x;
        temp.y = this->y + other.y;
        return temp;
    }

    // Declaration of Friend Function for '+' operator overloading
    friend Coordinate operator+(const Coordinate& c1, int value);

    // Display function
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Method 2: Overloading '+' using a Friend Function (Object + Integer)
Coordinate operator+(const Coordinate& c1, int value) {
    Coordinate temp;
    temp.x = c1.x + value;
    temp.y = c1.y + value;
    return temp;
}

int main() {
    Coordinate point1(10, 20), point2(5, 15);

    cout << "Point 1: "; point1.display();
    cout << "Point 2: "; point2.display();

    // Using Member Function Overload (Object + Object)
    Coordinate point3 = point1 + point2;
    cout << "\nResult of Point 1 + Point 2 (Member Function): ";
    point3.display();

    // Using Friend Function Overload (Object + Constant value)
    Coordinate point4 = point1 + 10;
    cout << "Result of Point 1 + 10 (Friend Function): ";
    point4.display();

    return 0;
}
