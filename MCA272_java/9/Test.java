package com.Cinema;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Test {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Cinema Swing App");
            frame.setSize(400, 250);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            JPanel panel = new JPanel(new BorderLayout());
            panel.setBackground(new Color(240, 240, 240));

            JLabel label = new JLabel("Welcome to Cinema!");
            label.setHorizontalAlignment(JLabel.CENTER);
            label.setFont(new Font("Arial", Font.BOLD, 20));
            label.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 0));

            JButton bookTicketsButton = new JButton("Book Tickets");
            bookTicketsButton.setBackground(new Color(60, 179, 113));
            bookTicketsButton.setForeground(Color.WHITE);
            bookTicketsButton.setFocusPainted(false);
            bookTicketsButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    showBookingDialog(frame);
                }
            });

            panel.add(label, BorderLayout.CENTER);
            panel.add(bookTicketsButton, BorderLayout.SOUTH);

            frame.add(panel);
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }

    private static void showBookingDialog(JFrame parentFrame) {
        JDialog bookingDialog = new JDialog(parentFrame, "Book Tickets", true);
        bookingDialog.setSize(600, 280);
        bookingDialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        bookingDialog.setLocationRelativeTo(parentFrame);

        JPanel dialogPanel = new JPanel(new GridLayout(3, 2));
        dialogPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel movieLabel = new JLabel("Select Movie:");
        JComboBox<String> movieComboBox = new JComboBox<>(new String[]{"The Avengers", "Mission Impossible: Dead Reckoning", "John Wick"});
        movieComboBox.setFont(new Font("Arial", Font.PLAIN, 14));

        JLabel ticketsLabel = new JLabel("Number of Tickets:");
        JTextField ticketsTextField = new JTextField();
        ticketsTextField.setFont(new Font("Arial", Font.PLAIN, 14));

        JButton bookButton = new JButton("Book");
        bookButton.setBackground(new Color(60, 179, 113));
        bookButton.setForeground(Color.WHITE);
        bookButton.setFocusPainted(false);
        bookButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedMovie = (String) movieComboBox.getSelectedItem();
                String enteredTickets = ticketsTextField.getText();

                if (isValidTicketInput(enteredTickets)) {
                    // Insert the record into the database
                    insertBookingRecord(selectedMovie, Integer.parseInt(enteredTickets));

                    JOptionPane.showMessageDialog(bookingDialog, "Tickets booked for " + selectedMovie + ".\nTotal Tickets: " + enteredTickets, "Booking Confirmation", JOptionPane.INFORMATION_MESSAGE);
                    bookingDialog.dispose();
                } else {
                    JOptionPane.showMessageDialog(bookingDialog, "Please enter a valid number of tickets.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton cancelButton = new JButton("Cancel");
        cancelButton.setBackground(new Color(192, 57, 43));
        cancelButton.setForeground(Color.WHITE);
        cancelButton.setFocusPainted(false);
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                bookingDialog.dispose();
            }
        });

        dialogPanel.add(movieLabel);
        dialogPanel.add(movieComboBox);
        dialogPanel.add(ticketsLabel);
        dialogPanel.add(ticketsTextField);
        dialogPanel.add(bookButton);
        dialogPanel.add(cancelButton);

        bookingDialog.add(dialogPanel);
        bookingDialog.setVisible(true);
    }

    private static boolean isValidTicketInput(String input) {
        try {
            int tickets = Integer.parseInt(input);
            return tickets > 0;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private static void insertBookingRecord(String movie, int tickets) {
        // JDBC connection parameters
        String url = "jdbc:mysql://localhost:3306/cinema_db";
        String username = "rohit";
        String password = "root";

        // SQL query to insert data into the 'Bookings' table
        String insertQuery = "INSERT INTO Bookings (movie_name, tickets) VALUES (?, ?)";

        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement preparedStatement = connection.prepareStatement(insertQuery)) {

            preparedStatement.setString(1, movie);
            preparedStatement.setInt(2, tickets);

            // Execute the update
            preparedStatement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

