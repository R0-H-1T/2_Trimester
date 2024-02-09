class Cinema {
    // Constants
    public static final String CINEMA_NAME = "CinePlex"; // Constant for cinema name
    public static final int MAX_SEATING_CAPACITY = 200; // Constant for maximum seating capacity

    // Static variable
    private static int totalCinemas = 0; // Total number of cinemas

    // Instance variables
    private int currentSeatingCapacity;

    // Constructor
    public Cinema(int initialSeatingCapacity) {
        // Validate and set the initial seating capacity
        if (initialSeatingCapacity <= MAX_SEATING_CAPACITY) {
            this.currentSeatingCapacity = initialSeatingCapacity;
        } else {
            System.out.println("Error: Exceeded maximum seating capacity.");
            this.currentSeatingCapacity = MAX_SEATING_CAPACITY;
        }

        // Increment the total number of cinemas
        totalCinemas++;
    }

    // Static method to get the total number of cinemas
    public static int getTotalCinemas() {
        return totalCinemas;
    }

    // Instance method to display cinema information
    public void displayCinemaInfo() {
        System.out.println("Cinema Name: " + CINEMA_NAME);
        System.out.println("Seating Capacity: " + currentSeatingCapacity);
    }
}



public class IMAXCinema extends Cinema {
    // Additional attributes specific to IMAX cinemas
    private boolean hasIMAXProjection;
    private String soundSystem;

    // Constructor
    public IMAXCinema(int seatingCapacity, boolean hasIMAXProjection, String soundSystem) {
        super(seatingCapacity); // Call the constructor of the parent class

        // Set the additional attributes
        this.hasIMAXProjection = hasIMAXProjection;
        this.soundSystem = soundSystem;
    }

    // Override the displayCinemaInfo method to include IMAX-specific information
    @Override
    public void displayCinemaInfo() {
        super.displayCinemaInfo(); // Call the displayCinemaInfo method of the parent class
        System.out.println("Has IMAX Projection: " + hasIMAXProjection);
        System.out.println("Sound System: " + soundSystem);
    }

    public static void main(String[] args) {
        // Create a regular cinema
        Cinema regularCinema = new Cinema(150);

        // Create an IMAX cinema
        IMAXCinema imaxCinema = new IMAXCinema(100, true, "Dolby Atmos");

        // Display information for regular cinema
        System.out.println("Regular Cinema Information:");
        regularCinema.displayCinemaInfo();

        System.out.println("\n--------------------------\n");

        // Display information for IMAX cinema
        System.out.println("IMAX Cinema Information:");
        imaxCinema.displayCinemaInfo();
    }
}





//
//In the provided Java code, the static and final keywords are used with specific meanings:
//
//static Keyword:
//
//totalCinemas Variable:
//
//totalCinemas is a static variable, which means it belongs to the class rather than any specific instance of the class. There is only one copy of this variable shared among all instances of the Cinema class.
//It is used to keep track of the total number of cinemas created.
//getTotalCinemas() Method:
//
//getTotalCinemas() is a static method, which means it belongs to the class and can be called without creating an instance of the class.
//It provides a way to retrieve the total number of cinemas from outside the class without having an instance of the class.
//final Keyword:
//
//CINEMA_NAME and MAX_SEATING_CAPACITY Constants:
//
//CINEMA_NAME and MAX_SEATING_CAPACITY are declared as final constants. Once assigned, their values cannot be changed.
//They are intended to represent constant values that are shared among all instances of the class and cannot be modified.
//DEFAULT_MOVIE_NAME Constant:
//
//DEFAULT_MOVIE_NAME in the Movie class is another example of a final constant.
//It represents a default value for the movie name and cannot be modified once assigned.
//displayCinemaInfo() Method in Cinema Class:
//
//The displayCinemaInfo() method in the Cinema class is not marked as final, but it could be considered effectively final in this context. If a subclass extends Cinema, it can inherit this method but cannot override it because it's called by super.displayCinemaInfo() in the IMAXCinema class.
//The use of static and final in this code promotes the creation of shared constants (CINEMA_NAME, MAX_SEATING_CAPACITY, DEFAULT_MOVIE_NAME) and shared variables/methods (totalCinemas, getTotalCinemas()), enhancing code organization and encapsulation.
