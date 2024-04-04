#include <iostream>
#include <string>

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
        std::cout << "Rectangle - Length: " << length << ", Width: " << width << std::endl;
    }
};

void riskyFunction(int x) {
    if (x == 0)
        throw "Error: Division by zero!";
    else
        std::cout << "Result: " << 10 / x << std::endl;
}

class Outer {
public:
    // Nested class
    class Inner {
    public:
        void display() {
            std::cout << "Inside Inner class" << std::endl;
        }
    };

    void outerDisplay() {
        std::cout << "Inside Outer class" << std::endl;
    }
};

int main() {
    try {
        riskyFunction(0);
    } catch (const char* errorMessage) {
        std::cerr << "Caught an exception: " << errorMessage << std::endl;
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
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    return 0;
}
