#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
protected:
    int age;

public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }

    void showPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Getter for name since it's private and needed by derived class display
    string getName() { return name; }
};

class Student : public Person {
private:
    int studentID;

public:
    void setStudentDetails(string n, int a, int id) {
        setPersonDetails(n, a); 
        studentID = id;
    }

    void showStudentDetails() {

        cout << "Student Details:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    
    }
};

int main() {
    Student s1;
    s1.setStudentDetails("RAIHAN", 20, 35);
    s1.showStudentDetails();

    return 0;
}
