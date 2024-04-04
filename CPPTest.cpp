#include <iostream>
#include <string>
#include <vector>

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

class ObjectCounter {
public:
    // Constant member variable
    static const int MAX_SIZE = 100;

    // Static member variable
    static int objectCount;

    // Constructor
    ObjectCounter() {
        objectCount++; // Increment object count each time a new object is created
    }

    // Destructor
    ~ObjectCounter() {
        objectCount--; // Decrement object count each time an object is destroyed
    }
};

// Definition of static member variable
int ObjectCounter::objectCount = 0;

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

    vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    cout << "Elements of the vector:";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << " " << myVector[i];
    }
    cout << endl;

    cout << "Size of the vector: " << myVector.size() << endl;
    cout << "Capacity of the vector: " << myVector.capacity() << endl;

    myVector[1] = 50;

    cout << "Modified vector:";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << " " << myVector[i];
    }
    cout << endl;

    // Accessing constant member variable
    cout << "Max size: " << ObjectCounter::MAX_SIZE << endl;

    // Accessing and modifying static member variable
    cout << "Initial object count: " << ObjectCounter::objectCount << endl;

    ObjectCounter obj1;
    ObjectCounter obj2;
    ObjectCounter obj3;

    cout << "Object count after creating 3 objects: " << ObjectCounter::objectCount << endl;

    return 0;
}
