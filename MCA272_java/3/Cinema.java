package com;

public class Cinema {
    private String name;
    private int capacity;

    // Inner class Movie
    public class Movie {
        private String title;
        private int duration;

        public Movie(String title, int duration) {
            this.title = title;
            this.duration = duration;
        }

        public String getTitle() {
            return title;
        }

        public int getDuration() {
            return duration;
        }

        public void displayMovieInfo() {
            System.out.println("Movie Title: " + title);
           System.out.println("Duration: " + duration + " minutes");
        }
    }

    public class Showtime {
        private Movie movie;
        private String time;

        public Showtime(Movie movie, String time) {
            this.movie = movie;
            this.time = time;
        }

        public Movie getMovie() {
            return movie;
        }

        public String getTime() {
            return time;
        }

        public void displayShowtimeInfo() {
            System.out.println("Showtime for " + movie.getTitle() + " at " + time);
        }
    }

    // Nested class Ticket
    public static class Ticket {
        private int seatNumber;
        private double price;

        public Ticket(int seatNumber, double price) {
            this.seatNumber = seatNumber;
            this.price = price;
        }

        public int getSeatNumber() {
            return seatNumber;
        }

        public double getPrice() {
            return price;
        }

        public void displayTicketInfo() {
            System.out.println("Ticket for Seat " + seatNumber + " - Price: $" + price);
        }
    }

    public Cinema(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
    }
    

     public void displaySchedule() {
        // Using String
        String stringSchedule = "Cinema Schedule (String):\n";
        stringSchedule += "1. " + new Movie("The Great Movie", 120).getTitle() + " - " +
                          new Movie("The Great Movie", 120).getDuration() + " minutes\n";
        stringSchedule += "2. " + new Movie("Awesome Film", 90).getTitle() + " - " +
                          new Movie("Awesome Film", 90).getDuration() + " minutes\n";

        System.out.println(stringSchedule);

        // Using StringBuffer
        StringBuffer stringBufferSchedule = new StringBuffer("Cinema Schedule (StringBuffer):\n");
        stringBufferSchedule.append("1. ").append(new Movie("The Great Movie", 120).getTitle())
                            .append(" - ").append(new Movie("The Great Movie", 120).getDuration()).append(" minutes\n");
        stringBufferSchedule.append("2. ").append(new Movie("Awesome Film", 90).getTitle())
                            .append(" - ").append(new Movie("Awesome Film", 90).getDuration()).append(" minutes\n");

        System.out.println(stringBufferSchedule.toString());
    }

    public String getName() {
        return name;
    }

    public int getCapacity() {
        return capacity;
    }

    public void displayCinemaInfo() {
        System.out.println("Cinema Name: " + name);
        System.out.println("Capacity: " + capacity + " seats");
    }

    public static void main(String[] args) {
        // Create an instance of Cinema
        Cinema cinema = new Cinema("ABC Cinema", 100);

        // Create an instance of the inner class Movie
        Cinema.Movie movie = cinema.new Movie("The Great Movie", 120);

        // Display cinema and movie information
        cinema.displayCinemaInfo();
        movie.displayMovieInfo();
        cinema.displayCinemaInfo();
        movie.displayMovieInfo();

        // Display cinema schedule using String and StringBuffer
        cinema.displaySchedule();
           Cinema.Showtime showtime = cinema.new Showtime(movie, "8:00 PM");

        // Create an instance of nested class Ticket
        Cinema.Ticket ticket = new Cinema.Ticket(1, 15.99);

        // Display showtime and ticket information
        showtime.displayShowtimeInfo();
        ticket.displayTicketInfo();
    }
}

