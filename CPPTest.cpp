#include <iostream>
#include <string>

using namespace std;

// Define an enum class called Fruit
enum class Fruit {
    Apple,
    Banana,
    Orange
};

// Define a function that takes a Fruit enum class value and prints its name
void printFruitName(Fruit fruit) {
    switch (fruit) {
        case Fruit::Apple:
            cout << "Apple" << endl;
            break;
        case Fruit::Banana:
            cout << "Banana" << endl;
            break;
        case Fruit::Orange:
            cout << "Orange" << endl;
            break;
        default:
            cout << "Unknown fruit" << endl;
            break;
    }
}

// Abstract class
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
};

// Concrete subclass
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void display() const override {
        cout << "Rectangle - Length: " << length << ", Width: " << width << endl;
    }
};

void riskyFunction(int x) {
    if (x == 0)
        throw "Error: Division by zero!";
    else
        cout << "Result: " << 10 / x << endl;
}

class Outer {
public:
    // Nested class
    class Inner {
    public:
        void display() {
            cout << "Inside Inner class" << endl;
        }
    };

    void outerDisplay() {
        cout << "Inside Outer class" << endl;
    }
};

int main() {
    try {
        riskyFunction(0);
    } catch (const char* errorMessage) {
        cerr << "Caught an exception: " << errorMessage << endl;
    }

    // Creating object of outer class
    Outer outerObj;
    // Creating object of inner class
    Outer::Inner innerObj;

    // Accessing methods of outer class
    outerObj.outerDisplay();

    // Accessing methods of inner class
    innerObj.display();

    Rectangle rect(5.0, 4.0);
    rect.display();
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;

    // Declare a variable of type Fruit
    Fruit myFruit = Fruit::Banana;

    // Print the name of the fruit
    printFruitName(myFruit);

    return 0;
}
