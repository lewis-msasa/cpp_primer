#include <iostream>
using namespace std;

class Box;  // Forward declaration of class Box

class BoxManager {
public:
    void setDimensions(Box& box, double length, double width, double height);
    void displayDimensions(const Box& box);
};

class Box {
private:
    double length;
    double width;
    double height;

public:
    Box() : length(0), width(0), height(0) {}

    // Declare BoxManager as a friend of Box
    friend class BoxManager;
};

// Friend functions implementation
void BoxManager::setDimensions(Box& box, double length, double width, double height) {
    box.length = length;  // Accessing private members of Box
    box.width = width;
    box.height = height;
}

void BoxManager::displayDimensions(const Box& box) {
    cout << "Box dimensions: "
         << "Length = " << box.length << ", "
         << "Width = " << box.width << ", "
         << "Height = " << box.height << endl;
}

int main() {
    Box box;
    BoxManager manager;

    // Setting dimensions of the box using BoxManager
    manager.setDimensions(box, 10.0, 5.0, 8.0);

    // Displaying the dimensions of the box
    manager.displayDimensions(box);

    return 0;
}
