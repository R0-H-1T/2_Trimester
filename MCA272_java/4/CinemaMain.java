package com;

import java.util.Scanner;

// Interface for ticket booking operations
interface TicketBooking {
    void bookTicket(int seatNumber);
    void cancelTicket(int seatNumber);
}

// Interface for retrieving movie information
interface MovieInfo {
    void displayMovieDetails();
    void checkShowTimings();
}

// Interface for payment operations
interface Payment {
    void processPayment(double amount);
    void refundPayment(double amount);
}

// Class representing the Booking System that implements TicketBooking and Payment interfaces
class BookingSystem implements TicketBooking, Payment {
    private static final double BASE_TICKET_PRICE = 10;
    private double totalRevenue = 0;

    @Override
    public void bookTicket(int seatNumber) {
        System.out.println("Ticket booked for seat number: " + seatNumber);
        double ticketPrice = calculateTicketPrice(seatNumber);
        totalRevenue += ticketPrice;
        processPayment(ticketPrice);
    }

    @Override
    public void cancelTicket(int seatNumber) {
        System.out.println("Ticket canceled for seat number: " + seatNumber);
        double refundAmount = calculateRefundAmount(seatNumber);
        refundPayment(refundAmount);
    }

    private double calculateTicketPrice(int seatNumber) {
        // Assume a simple pricing logic (e.g., $10 + $2 for premium seats)
        return BASE_TICKET_PRICE + (seatNumber % 2 == 0 ? 2 : 0);
    }

    private double calculateRefundAmount(int seatNumber) {
        // Assume 80% refund for canceled tickets
        return 0.8 * calculateTicketPrice(seatNumber);
    }

    @Override
    public void processPayment(double amount) {
        System.out.println("Payment processed: $" + amount);
    }

    @Override
    public void refundPayment(double amount) {
        System.out.println("Refund processed: $" + amount);
        totalRevenue -= amount;
    }

    public double getTotalRevenue() {
        return totalRevenue;
    }
}

// Class representing Movie that implements MovieInfo interface
class Movie implements MovieInfo {
    private String title = "Avengers: Endgame";
    private String director = "Anthony and Joe Russo";

    @Override
    public void displayMovieDetails() {
        System.out.println("Movie Title: " + title);
        System.out.println("Director: " + director);
    }

    @Override
    public void checkShowTimings() {
        System.out.println("Show timings: 12:00 PM, 3:00 PM, 6:00 PM, 9:00 PM");
    }
}

// Main class to test the interfaces and classes
public class CinemaMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        BookingSystem bookingSystem = new BookingSystem();
        Movie movie = new Movie();

        System.out.print("Enter seat number for booking: ");
        int seatNumber = scanner.nextInt();

        // Book a ticket and display movie details
        bookingSystem.bookTicket(seatNumber);
        movie.displayMovieDetails();

        System.out.println("Total Revenue: $" + bookingSystem.getTotalRevenue());
    
        System.out.print("Enter seat number for cancellation: ");
        int cancelSeatNumber = scanner.nextInt();

        // Cancel a ticket and check show timings
        bookingSystem.cancelTicket(cancelSeatNumber);
        movie.checkShowTimings();

        // Display total revenue
        System.out.println("Total Revenue: $" + bookingSystem.getTotalRevenue());

        scanner.close();
    }
}

