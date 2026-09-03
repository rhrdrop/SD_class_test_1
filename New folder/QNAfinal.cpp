#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload == operator
    bool operator==(const Complex &c) {
        return (real == c.real && imag == c.imag);
    }

    // Display function
    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }
};

int main() {
    Complex c1(3.5, -2.5);
    Complex c2(1.5, 4.5);

    Complex sum = c1 + c2;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Sum: ";
    sum.display();

    if (c1 == c2)
        cout << "Both complex numbers are equal." << endl;
    else
        cout << "Both complex numbers are not equal." << endl;

    return 0;
}