#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;
    virtual ~Shape() {} // Virtual destructor
};

// Derived class
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

// Another derived class
class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square" << endl;
    }
};

int main() {
    // Shape shape; // This line would cause a compile-time error because Shape is abstract

    // Create instances of derived classes
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();  // Output: Drawing a Circle
    shape2->draw();  // Output: Drawing a Square

    // Clean up
    delete shape1;
    delete shape2;

    return 0;
}
