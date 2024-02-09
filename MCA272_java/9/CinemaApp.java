import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CinemaApp{
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Cinema Swing App");
            frame.setSize(300, 200);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            JLabel label = new JLabel("Welcome to Cinema!");
            label.setHorizontalAlignment(JLabel.CENTER);
            label.setVerticalAlignment(JLabel.CENTER);

            JButton bookTicketsButton = new JButton("Book Tickets");
            bookTicketsButton.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    showBookingDialog(frame);
                }
            });

            JPanel panel = new JPanel(new BorderLayout());
            panel.add(label, BorderLayout.CENTER);
            panel.add(bookTicketsButton, BorderLayout.SOUTH);

            frame.add(panel);
            frame.setVisible(true);
        });
    }

    private static void showBookingDialog(JFrame parentFrame) {
        JDialog bookingDialog = new JDialog(parentFrame, "Book Tickets", true);
        bookingDialog.setSize(300, 150);
        bookingDialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);

        JPanel dialogPanel = new JPanel(new GridLayout(3, 2));

        JLabel movieLabel = new JLabel("Select Movie:");
        JComboBox<String> movieComboBox = new JComboBox<>(new String[]{"The Avengers", "Mission Impossible: Dead Reckoning", "John Wick"});

        JLabel ticketsLabel = new JLabel("Number of Tickets:");
        JTextField ticketsTextField = new JTextField();

        JButton bookButton = new JButton("Book");
        bookButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedMovie = (String) movieComboBox.getSelectedItem();
                String enteredTickets = ticketsTextField.getText();

                if (!enteredTickets.isEmpty()) {
                    JOptionPane.showMessageDialog(bookingDialog, "Tickets booked for " + selectedMovie + ".\nTotal Tickets: " + enteredTickets, "Booking Confirmation", JOptionPane.INFORMATION_MESSAGE);
                    bookingDialog.dispose();
                } else {
                    JOptionPane.showMessageDialog(bookingDialog, "Please enter the number of tickets.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        JButton cancelButton = new JButton("Cancel");
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
        bookingDialog.setLocationRelativeTo(parentFrame);
        bookingDialog.setVisible(true);
    }
}

