import java.lang.Cloneable;
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Comparator;
import testpackage.Test;

// Define a custom exception class
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

// Sample for marker annotation:
// Custom annotation declaration
@interface books_data
{
    // Multiple variable declaration
    String book_name();
    int book_price();
    String author();
}

// Using the custom Annotation
@books_data(book_name = "Effective Java", book_price = 30,
        author = "Joshua Bloch")

class MathOperations {
    public static int add(int a, int b) {
        return a + b;
    }

    public static int subtract(int a, int b) {
        return a - b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }

    public static double divide(int a, int b) {
        if (b == 0) {
            throw new IllegalArgumentException("Division by zero");
        }
        return (double) a / b;
    }
}

// Define a class that implements the Comparator interface for comparing strings by length
class StringLengthComparator implements Comparator<String> {
    // Implement the compare method to compare strings by length
    @Override
    public int compare(String str1, String str2) {
        return Integer.compare(str1.length(), str2.length());
    }
}

// Define an interface Shape extending Cloneable from Java library
interface Shape extends Cloneable {
    void draw(); // Method signature without implementation
}

// Class implementing the Shape interface
class Circle implements Shape {
    // Implementing the draw method defined in the Shape interface
    @Override
    public void draw() {
        System.out.println("Drawing a circle");
    }
}

abstract class AbstractClass {
    // Constant variable
    public static final int CONSTANT_VALUE = 100;

    // Static variable
    public static int staticValue;

    // Static block to initialize static variables
    static {
        staticValue = 200;
    }

    // Abstract method
    public abstract void abstractMethod();

    // Non-abstract method
    public void concreteMethod() {
        System.out.println("Concrete method implementation");
    }
}

// Main class to test the interface and its implementation
public class Main {
    // Define an enum named Day
    enum Day {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    }

    static class NestedClass {
        void display() {
            System.out.println("This is a static nested class");
        }
    }

    // Method with a List and a String parameter
    public static void processList(List<Integer> numbers, String message) {
        System.out.println("Message: " + message);
        System.out.println("Numbers in the list:");
        for (Integer number : numbers) {
            System.out.println(number);
        }
    }

    // Method that throws IOException
    public static void myMethod() throws IOException {
        throw new IOException("This is an IOException");
    }

    // Method that throws the custom exception
    public static void myCustomMethod(int value) throws CustomException {
        if (value < 0) {
            throw new CustomException("Value cannot be negative");
        } else {
            System.out.println("Value is: " + value);
        }
    }

    public static void main(String[] args) {
        try {
            // Call myMethod which throws IOException
            myMethod();
        } catch (IOException e) {
            // Catch and handle the IOException
            System.out.println("Caught IOException: " + e.getMessage());
        }

        try {
            // Call myMethod with a negative value
            myCustomMethod(-5);
        } catch (CustomException e) {
            // Catch and handle the custom exception
            System.out.println("Caught CustomException: " + e.getMessage());
        }

        // Iterating through all the values of the enum Day
        for (Day day : Day.values()) {
            System.out.println(day);
        }

        Main.NestedClass nestedObject = new Main.NestedClass();
        nestedObject.display();

        // Create an instance of StringLengthComparator
        StringLengthComparator comparator = new StringLengthComparator();

        // Compare strings using the implemented comparator
        String str1 = "Apple";
        String str2 = "Banana";
        int result = comparator.compare(str1, str2);

        // Print the comparison result
        if (result < 0) {
            System.out.println(str1 + " is shorter than " + str2);
        } else if (result > 0) {
            System.out.println(str1 + " is longer than " + str2);
        } else {
            System.out.println(str1 + " has the same length as " + str2);
        }

        // Create an instance of Circle
        Circle circle = new Circle();

        // Call the draw method through the Circle object
        circle.draw();

        // Create a sample list of numbers
        List<Integer> numbers = List.of(1, 2, 3, 4, 5);

        // Call the processList method with the list and a string message
        processList(numbers, "Processing the list of numbers:");

        // Create an instance of ArrayList which implements the List interface
        List<String> myList = new ArrayList<>();

        // Add elements to the list
        myList.add("Apple");
        myList.add("Banana");
        myList.add("Orange");

        // Print the elements of the list
        System.out.println("Elements of the list:");
        for (String element : myList) {
            System.out.println(element);
        }

        // Creating an object of Test class
        Test t = new Test();

        // Calling the functions show() and view()
        // using the object of Test class
        t.show();
        t.view();
    }
}
