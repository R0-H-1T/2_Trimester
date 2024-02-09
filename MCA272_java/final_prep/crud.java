import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class crud {

    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3307/stock";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "12345";

    // JDBC variables for opening, closing, and managing connection
    private static Connection connection;
    private static Statement statement;
    private static ResultSet resultSet;

    private static Scanner scanner = new Scanner(System.in);

    // Establish the connection
    public static void connect() throws SQLException {
        connection = DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD);
    }

    // Create a sales table
    public static void createSalesTable() throws SQLException {
        statement = connection.createStatement();
        String createTableQuery = "CREATE TABLE IF NOT EXISTS sales (id INT AUTO_INCREMENT PRIMARY KEY, "
                + "product_name VARCHAR(255), quantity INT, price DOUBLE)";
        statement.executeUpdate(createTableQuery);
    }

    // Insert sample sales records
    public static void insertSalesRecords() throws SQLException {
        System.out.println("Enter product name:");
        String productName = scanner.nextLine();

        System.out.println("Enter quantity:");
        int quantity = scanner.nextInt();

        System.out.println("Enter price:");
        double price = scanner.nextDouble();

        String insertQuery = "INSERT INTO sales (product_name, quantity, price) VALUES (?, ?, ?)";
        try (PreparedStatement preparedStatement = connection.prepareStatement(insertQuery)) {
            preparedStatement.setString(1, productName);
            preparedStatement.setInt(2, quantity);
            preparedStatement.setDouble(3, price);
            preparedStatement.executeUpdate();
        }
    }

    // Retrieve all sales records
    public static void readSalesRecords() throws SQLException {
        statement = connection.createStatement();
        resultSet = statement.executeQuery("SELECT * FROM sales");

        while (resultSet.next()) {
            System.out.println("ID: " + resultSet.getInt("id") +
                    ", Product: " + resultSet.getString("product_name") +
                    ", Quantity: " + resultSet.getInt("quantity") +
                    ", Price: " + resultSet.getDouble("price"));
        }
    }

    // Update a sales record
    public static void updateSalesRecord() throws SQLException {
        System.out.println("Enter the ID of the record you want to update:");
        int id = scanner.nextInt();

        System.out.println("Enter the new quantity:");
        int newQuantity = scanner.nextInt();

        String updateQuery = "UPDATE sales SET quantity = ? WHERE id = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(updateQuery)) {
            preparedStatement.setInt(1, newQuantity);
            preparedStatement.setInt(2, id);
            preparedStatement.executeUpdate();
        }
    }

    // Delete a sales record
    public static void deleteSalesRecord() throws SQLException {
        System.out.println("Enter the ID of the record you want to delete:");
        int id = scanner.nextInt();

        String deleteQuery = "DELETE FROM sales WHERE id = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(deleteQuery)) {
            preparedStatement.setInt(1, id);
            preparedStatement.executeUpdate();
        }
    }

    // Close the connection
    public static void close() throws SQLException {
        if (resultSet != null) resultSet.close();
        if (statement != null) statement.close();
        if (connection != null) connection.close();
        scanner.close();
    }

    public static void main(String[] args) {
        try {
            // Connect to the database
            connect();

            // Create sales table
            createSalesTable();

            int choice;
            do {
                System.out.println("\nSelect an operation:");
                System.out.println("1. Add Sales Record");
                System.out.println("2. View Sales Records");
                System.out.println("3. Update Sales Record");
                System.out.println("4. Delete Sales Record");
                System.out.println("0. Exit");

                choice = scanner.nextInt();
                scanner.nextLine(); // Consume the newline

                switch (choice) {
                    case 1:
                        insertSalesRecords();
                        break;
                    case 2:
                        readSalesRecords();
                        break;
                    case 3:
                        updateSalesRecord();
                        break;
                    case 4:
                        deleteSalesRecord();
                        break;
                    case 0:
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } while (choice != 0);

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                // Close the connection
                close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}

