package com;

import java.util.Scanner;

class Cinema {
    private static final int TOTAL_SEATS = 10;
    private static int availableSeats = TOTAL_SEATS;

    synchronized static void bookSeat(String user, int numSeats) {
        if (availableSeats >= numSeats) {
            System.out.println(user + " booked " + numSeats + " seat(s).");
            availableSeats -= numSeats;
        } else {
            System.out.println(user + " couldn't book " + numSeats + " seat(s). Not enough seats available.");
        }
        System.out.println("Available seats: " + availableSeats);
    }
}

class UserBookingThread extends Thread {
    private String username;
    private int numSeats;

    public UserBookingThread(String username, int numSeats) {
        this.username = username;
        this.numSeats = numSeats;
    }

    @Override
    public void run() {
        Cinema.bookSeat(username, numSeats);
    }
}

public class CinemaBookingApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your username: ");
        String username = scanner.nextLine();

        System.out.print("Enter the number of seats to book: ");
        int numSeats = scanner.nextInt();

        // Create multiple threads for concurrent booking
        UserBookingThread bookingThread1 = new UserBookingThread(username + "_1", numSeats);
        UserBookingThread bookingThread2 = new UserBookingThread(username + "_2", numSeats);

        // Start the threads
        bookingThread1.start();
        bookingThread2.start();

        // Wait for both threads to finish before proceeding
        try {
            bookingThread1.join();
            bookingThread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Program execution completed.");
    }
}

