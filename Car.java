public class Car {
    private String make;
    private String model;
    private int year;

    // Constructor
    public Car(String make, String model, int year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }

    // Method to display car information
    public void displayInfo() {
        System.out.println("Make: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
    }

    public static void main(String[] args) {
        // Creating a new instance of the Car class by invoking its constructor
        Car myCar = new Car("Toyota", "Camry", 2020);

        // Calling a method on the object to display its information
        myCar.displayInfo();
    }
}
