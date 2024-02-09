import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class Cinema_DB{

    static String jdbcUrl = "jdbc:mysql://localhost:3306/cinema_db";
    static String username = "rohit";
    static String password = "root";



    static void dropAllRecords(Scanner scanner) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            // Step 1: Register JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Open a connection
            connection = DriverManager.getConnection(jdbcUrl, username, password);

            // Step 3: Prompt the user for confirmation
            System.out.print("Are you sure you want to drop all records from the table? (yes/no): ");
            String confirmation = scanner.nextLine().toLowerCase();

            if ("yes".equals(confirmation)) {
                // Step 4: Create a prepared statement for dropping all records
                String dropAllRecordsSQL = "DELETE FROM movies";
                preparedStatement = connection.prepareStatement(dropAllRecordsSQL);

                // Step 5: Execute the deletion
                int rowsAffected = preparedStatement.executeUpdate();
                System.out.println(rowsAffected + " records dropped successfully!");
            } else {
                System.out.println("Records not dropped. Exiting...");
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // Step 6: Close the resources
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }



    static void updateRecord(Scanner scanner) {

        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            // Step 1: Register JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Open a connection
            connection = DriverManager.getConnection(jdbcUrl, username, password);

            // Step 3: Prompt the user for the record ID to update
            System.out.print("Enter the ID of the record you want to update: ");
            int recordId = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            // Step 4: Prompt the user for new values
            System.out.print("Enter the new title: ");
            String newTitle = scanner.nextLine();

            System.out.print("Enter the new release year: ");
            int newReleaseYear = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            System.out.print("Enter the new genre: ");
            String newGenre = scanner.nextLine();

            // Step 5: Create a prepared statement for updating the record
            String updateSQL = "UPDATE movies SET title=?, release_year=?, genre=? WHERE id=?";
            preparedStatement = connection.prepareStatement(updateSQL);
            preparedStatement.setString(1, newTitle);
            preparedStatement.setInt(2, newReleaseYear);
            preparedStatement.setString(3, newGenre);
            preparedStatement.setInt(4, recordId);

            // Step 6: Execute the update
            int rowsAffected = preparedStatement.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Record updated successfully!");
            } else {
                System.out.println("Record not found or not updated.");
            }

        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        } finally {
            // Step 7: Close the resources
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }




    static void insertRecord(PreparedStatement preparedStatement, String title, int releaseYear, String genre) throws SQLException {
        preparedStatement.setString(1, title);
        preparedStatement.setInt(2, releaseYear);
        preparedStatement.setString(3, genre);
        preparedStatement.executeUpdate();
    }


    public static void main(String[] args) {
        // JDBC URL, username, and password of MySQL server
        // JDBC variables for opening, closing and managing connection
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            // Step 1: Register JDBC Driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Open a connection
            System.out.println("Connecting to database...");
            connection = DriverManager.getConnection(jdbcUrl, username, password);
            System.out.println("Connected to database successfully!");



            //---------------------------------------------------------------
            Statement statement = connection.createStatement();

            // Step 4: Execute a SQL statement to create a table
            String createTableSQL = "CREATE TABLE IF NOT EXISTS movies (" +
                    "id INT AUTO_INCREMENT PRIMARY KEY," +
                    "title VARCHAR(255) NOT NULL," +
                    "release_year INT," +
                    "genre VARCHAR(50)" +
                    ")";
            statement.executeUpdate(createTableSQL);
            System.out.println("Table 'movies' created successfully!");

            String customersTable = "CREATE TABLE IF NOT EXISTS customers (" +
                    "id INT AUTO_INCREMENT PRIMARY KEY," +
                    "customer_name VARCHAR(255) NOT NULL," +
                    "customer_age INT," +
                    "gender VARCHAR(50)" +
                    ")";
            statement.executeUpdate(customersTable);

            System.out.println("Table 'customers' created successfully!");


            Scanner scanner = new Scanner(System.in);

            System.out.print("Do you want to insert data? (yes/no): ");
            String userInput = scanner.nextLine().toLowerCase();
    
            if ("yes".equals(userInput)) {
                String insertSQL = "INSERT INTO movies (title, release_year, genre) VALUES (?, ?, ?)";
                preparedStatement = connection.prepareStatement(insertSQL);
    
                insertRecord(preparedStatement, "John Wick: Chapter 4", 2023, "Action");
                insertRecord(preparedStatement, "The Equilizer", 2015, "Comedy");
                insertRecord(preparedStatement, "Mr. Nobody", 2019, "Drama");
    
                System.out.println("Multiple records inserted successfully!");
            } else {
                System.out.println("No data inserted.");
            }
    
    


            String selectSQL = "SELECT * FROM movies";
            ResultSet resultSet = connection.createStatement().executeQuery(selectSQL);

            // Step 4: Print the inserted records
            System.out.println("Inserted Records:");
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String title = resultSet.getString("title");
                int releaseYear = resultSet.getInt("release_year");
                String genre = resultSet.getString("genre");

                System.out.println("ID: " + id + ", Title: " + title + ", Release Year: " + releaseYear + ", Genre: " + genre);
            }
            // Do something with the connection (e.g., execute queries)



            System.out.print("Do you want to update data? (yes/no): ");
            userInput = scanner.nextLine().toLowerCase();


            if ("yes".equals(userInput)) {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                    System.out.println("Connection closed.");
                }
                updateRecord(scanner);
            } else {
                System.out.println("No data inserted.");
            }



            System.out.print("Do you want to delete all records? (yes/no): ");
            userInput = scanner.nextLine().toLowerCase();


            if ("yes".equals(userInput)) {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                    System.out.println("Connection closed.");
                }
                dropAllRecords(scanner);
                // updateRecord(scanner);
            } else {
                System.out.println("No record deleted.");
            }


            scanner.close();


        } catch (SQLException | ClassNotFoundException e) {
            // Handle errors for JDBC or Class.forName
            e.printStackTrace();
        } finally {
            // Step 3: Close the connection
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
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


