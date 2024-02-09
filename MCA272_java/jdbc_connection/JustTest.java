
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JustTest{
    public static void main(String[] args) {
        // JDBC URL, username, and password of MySQL server
        String jdbcUrl = "jdbc:mysql://localhost:3306/cinema_db";
        String username = "rohit";
        String password = "root";

        // JDBC variables for opening, closing and managing connection
        Connection connection = null;

        try {
            // Step 1: Register JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Open a connection
            System.out.println("Connecting to database...");
            connection = DriverManager.getConnection(jdbcUrl, username, password);
            System.out.println("Connected to database successfully!");

        } catch (SQLException | ClassNotFoundException e) {
            // Handle errors for JDBC or Class.forName
            e.printStackTrace();
        } finally {
            // Step 3: Close the connection
            try {
                if (connection != null) {
                    connection.close();
                    System.out.println("Connection closed.");
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}

