package com;
/**
 * What Im Doing in this class
 * 
 * Cinema is the main class
 * MovieCinema, IMAXCinema, SpecialScreenCinema extends Cinema class    
 */


class Cinema {
    private String cinemaName;
    protected int seatingCapacity;
    private double ticketPrice;

    public Cinema() {
        cinemaName = "Default Cinema";
        seatingCapacity = 100;
        ticketPrice = 10.0;
    }

    public Cinema(String name, int capacity, double price) {
        cinemaName = name;
        seatingCapacity = capacity;
        ticketPrice = price;
    }

    public String getCinemaName() {
        return cinemaName;
    }

    public void setCinemaName(String name) {
        cinemaName = name;
    }

    public double getTicketPrice() {
        return ticketPrice;
    }

    public void setTicketPrice(double price) {
        ticketPrice = price;
    }

    public void displayCinemaDetails() {
        System.out.println("Cinema Name: " + cinemaName);
        System.out.println("Seating Capacity: " + seatingCapacity);
        System.out.println("Ticket Price: $" + ticketPrice);
    }
}

class MovieCinema extends Cinema {
    private String movieName;
    private int movieYear;

    public MovieCinema(String cinemaName, int seatingCapacity, double ticketPrice, String movieName, int movieYear) {
        super(cinemaName, seatingCapacity, ticketPrice);
        this.movieName = movieName;
        this.movieYear = movieYear;
    }

    @Override
    public void displayCinemaDetails() {
        super.displayCinemaDetails();
        System.out.println("Movie Name: " + movieName);
        System.out.println("Movie Year: " + movieYear);
    }
}

class IMAXCinema extends Cinema {
    // Additional data members
    private boolean isIMAX;
    private String soundSystem;

    public IMAXCinema(String cinemaName, int seatingCapacity, double ticketPrice, boolean isIMAX, String soundSystem) {
        super(cinemaName, seatingCapacity, ticketPrice);
        this.isIMAX = isIMAX;
        this.soundSystem = soundSystem;
    }

    @Override
    public void displayCinemaDetails() {
        super.displayCinemaDetails();
        System.out.println("IMAX: " + isIMAX);
        System.out.println("Sound System: " + soundSystem);
    }
}

class SpecialScreenCinema extends Cinema {
    private String specialScreenType;

    public SpecialScreenCinema(String cinemaName, int seatingCapacity, double ticketPrice, String specialScreenType) {
        super(cinemaName, seatingCapacity, ticketPrice);
        this.specialScreenType = specialScreenType;
    }

    public void displayCinemaDetails() {
        super.displayCinemaDetails();
        System.out.println("Special Screen Type: " + specialScreenType);
    }
}

public class CinemaMain {
    public static void main(String[] args) {
        MovieCinema movieCinema = new MovieCinema("MovieMax", 200, 12.5, "Action Movie", 2023);
        IMAXCinema imaxCinema = new IMAXCinema("IMAX World", 150, 15.0, true, "Dolby Atmos");
        SpecialScreenCinema specialScreenCinema = new SpecialScreenCinema("VIP Screen", 50, 20.0, "VIP Lounge");

       

        System.out.println("Movie Cinema Details:");
        movieCinema.displayCinemaDetails();

        System.out.println("\nIMAX Cinema Details:");
        imaxCinema.displayCinemaDetails();

        System.out.println("\nSpecial Screen Cinema Details:");
        specialScreenCinema.displayCinemaDetails();

    }
}

