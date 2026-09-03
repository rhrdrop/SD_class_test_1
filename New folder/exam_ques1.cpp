




























































































































































///1
/*#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor with default values
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // Overload + operator for addition
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overload - operator for subtraction
    Complex operator-(const Complex& obj) {
        return Complex(real - obj.real, imag - obj.imag);
    }

    // Overload == operator for equality comparison
    bool operator==(const Complex& obj) {
        return (real == obj.real) && (imag == obj.imag);
    }

    // Helper function to display the complex number
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main() {
    Complex c1(5.5, 3.2);
    Complex c2(2.0, 1.5);

    cout << "C1: "; c1.display(); cout << endl;
    cout << "C2: "; c2.display(); cout << endl;

    Complex c3 = c1 + c2;
    cout << "Addition (C1 + C2): "; c3.display(); cout << endl;

    Complex c4 = c1 - c2;
    cout << "Subtraction (C1 - C2): "; c4.display(); cout << endl;

    if (c1 == c2) {
        cout << "C1 and C2 are equal." << endl;
    } else {
        cout << "C1 and C2 are NOT equal." << endl;
    }

    return 0;
}
*/

///2

/*
#include <iostream>
using namespace std;

class Engine {
public:
    void startEngine() {
        cout << "Engine started." << endl;
    }
};

// Private inheritance
class Car : private Engine {
public:
    void drive() {
        // Car can use the base class method internally
        startEngine();
        cout << "Car is driving." << endl;
    }
};

int main() {
    Car myCar;
    myCar.drive(); // Works fine

    // myCar.startEngine(); // ERROR! startEngine() is private in Car
    return 0;
}
*/

///3
/*
#include <iostream>
#include <string>

using namespace std;

// Base Class
class Course {
protected:
    string courseName;
    double baseFee;

public:
    Course(string name, double fee) {
        courseName = name;
        baseFee = fee;
    }

    // Virtual function for runtime polymorphism
    virtual double calculateFee() {
        return baseFee;
    }

    virtual void displayDetails() {
        cout << "Course: " << courseName << "\t Total Fee: $" << calculateFee() << endl;
    }
};

// Derived Class 1
class TheoryCourse : public Course {
public:
    TheoryCourse(string name, double fee) : Course(name, fee) {}

    double calculateFee() override {
        return baseFee; // No extra charges for theory
    }
};

// Derived Class 2
class LabCourse : public Course {
private:
    double labCharge;
public:
    LabCourse(string name, double fee, double charge) : Course(name, fee) {
        labCharge = charge;
    }

    double calculateFee() override {
        return baseFee + labCharge;
    }
};

// Derived Class 3
class OnlineCourse : public Course {
private:
    double techCharge;
public:
    OnlineCourse(string name, double fee, double charge) : Course(name, fee) {
        techCharge = charge;
    }

    double calculateFee() override {
        return baseFee + techCharge;
    }
};

int main() {
    // Demonstrating runtime polymorphism using base class pointers
    Course* courses[3];

    courses[0] = new TheoryCourse("Computer Programming", 1000.0);
    courses[1] = new LabCourse("Physics Lab", 1000.0, 500.0);
    courses[2] = new OnlineCourse("Web Development", 1000.0, 300.0);

    cout << "--- Course Registration System ---" << endl;
    for (int i = 0; i < 3; i++) {
        // The correct calculateFee() is called at runtime
        courses[i]->displayDetails();
    }

    // Free memory
    for (int i = 0; i < 3; i++) delete courses[i];

    return 0;
}
*/

///4

/*
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::reverse

using namespace std;

int main() {
    // 1. Start with vector initialized
    vector<int> vec = {10, 12, 15, 18, 22};

    // 2. Append the number 30 at the end
    vec.push_back(30);

    // 3. Insert the number 11 at the second position (index 1)
    vec.insert(vec.begin() + 1, 11);

    // 4. Delete the last element
    vec.pop_back();

    // 5. Replace the element at index 2 with 19
    vec[2] = 19;

    // 6. Reverse the vector
    reverse(vec.begin(), vec.end());

    // 7. Finally, display all the elements
    cout << "Final Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

///5

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string title, author, isbn;

    // --- WRITING TO FILE ---
    ofstream outFile("LibraryDB.txt");

    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    cout << "Enter Book Details to store in LibraryDB:" << endl;
    cout << "Title: ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "ISBN: ";
    getline(cin, isbn);

    // Store in file
    outFile << "Title: " << title << endl;
    outFile << "Author: " << author << endl;
    outFile << "ISBN: " << isbn << endl;

    outFile.close();
    cout << "\nData successfully saved to LibraryDB.txt\n" << endl;

    // --- READING FROM FILE ---
    ifstream inFile("LibraryDB.txt");
    string line;

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "--- Stored Books in Library Database ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
*/
