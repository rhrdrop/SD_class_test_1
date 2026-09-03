#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    // Attributes
    string modelNumber;
    string colour;
    int maxSpeed;

    // Functions
    void start() {
        cout << "The " << colour << " " << modelNumber << " has started." << endl;
    }

    void stop() {
        cout << "The " << colour << " " << modelNumber << " has stopped." << endl;
    }

    void display() {
        cout << "Model: " << modelNumber << " | Colour: " << colour << " | Max Speed: " << maxSpeed << "km/h" << endl;
    }
};

int main() {
    // Creating first car object
    Car car1;
    car1.modelNumber = "A-100";
    car1.colour = "Red";
    car1.maxSpeed = 220;

    // Creating second car object
    Car car2;
    car2.modelNumber = "B-200";
    car2.colour = "Blue";
    car2.maxSpeed = 250;

    // Output
    cout << "--- Car 1 Details ---" << endl;
    car1.display();
    car1.start();
    car1.stop();

    cout << "\n--- Car 2 Details ---" << endl;
    car2.display();
    car2.start();
    car2.stop();

    return 0;
}