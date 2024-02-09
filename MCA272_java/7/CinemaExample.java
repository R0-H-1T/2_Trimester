import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Movie {
    private String title;
    private int releaseYear;
    private double rating;

    public Movie(String title, int releaseYear, double rating) {
        this.title = title;
        this.releaseYear = releaseYear;
        this.rating = rating;
    }

    public String getTitle() {
        return title;
    }

    public int getReleaseYear() {
        return releaseYear;
    }

    public double getRating() {
        return rating;
    }

    @Override
    public String toString() {
        return "Movie{" +
                "title='" + title + '\'' +
                ", releaseYear=" + releaseYear +
                ", rating=" + rating +
                '}';
    }
}

// MovieFilter interface for movie filtering
interface MovieFilter {
    boolean test(Movie movie);
}

public class CinemaExample {
    public static void main(String[] args) {
        // Create a list of movies
        List<Movie> movies = new ArrayList<>();
        movies.add(new Movie("Inception", 2010, 8.8));
        movies.add(new Movie("The Dark Knight", 2008, 9.0));
        movies.add(new Movie("Interstellar", 2014, 8.6));
        movies.add(new Movie("The Shawshank Redemption", 1994, 9.3));
        movies.add(new Movie("Pulp Fiction", 1994, 8.9));

        // Use lambda expression to filter movies released after 2000
        List<Movie> recentMovies = filterMovies(movies, movie -> movie.getReleaseYear() > 2000);
        System.out.println("Recent Movies: " + recentMovies);

        // Use lambda expression to sort movies by rating in descending order
        sortMoviesByRatingDesc(movies);
        System.out.println("Movies Sorted by Rating (Descending):");
        for (Movie movie : movies) {
            System.out.println(movie);
        }
    }

    // Lambda expression to filter movies based on a condition
    private static List<Movie> filterMovies(List<Movie> movies, MovieFilter filter) {
        List<Movie> filteredMovies = new ArrayList<>();
        for (Movie movie : movies) {
            if (filter.test(movie)) {
                filteredMovies.add(movie);
            }
        }
        return filteredMovies;
    }

    // Lambda expression to sort movies by rating in descending order
    private static void sortMoviesByRatingDesc(List<Movie> movies) {
        Collections.sort(movies, (movie1, movie2) -> Double.compare(movie2.getRating(), movie1.getRating()));
    }
}

