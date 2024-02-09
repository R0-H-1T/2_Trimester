import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Test{

    static void insertRecord(PreparedStatement preparedStatement, String title, int releaseYear, String genre) throws SQLException {
        preparedStatement.setString(1, title);
        preparedStatement.setInt(2, releaseYear);
        preparedStatement.setString(3, genre);
        preparedStatement.executeUpdate();
    }


    public static void main(String[] args) {
        // JDBC URL, username, and password of MySQL server
        String jdbcUrl = "jdbc:mysql://localhost:3306/cinema_db";
        String username = "rohit";
        String password = "root";

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

            String insertSQL = "INSERT INTO movies (title, release_year, genre) VALUES (?, ?, ?)";
            preparedStatement = connection.prepareStatement(insertSQL);

            // Step 4: Insert multiple records
            insertRecord(preparedStatement, "John Wick: Chapter 4", 2023, "Action");
            insertRecord(preparedStatement, "The Equilizer", 2015, "Comedy");
            insertRecord(preparedStatement, "Mr. Nobody", 2019, "Drama");

            System.out.println("Multiple records inserted successfully!");

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

