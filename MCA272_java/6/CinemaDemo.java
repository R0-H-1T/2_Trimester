

    public class CinemaDemo {
        public static void main(String[] args) {
            ActionGenre actionGenre = new ActionGenre("Action");
            DramaGenre dramaGenre = new DramaGenre("Drama");

            ActionMovie actionMovie = new ActionMovie("Die Hard", actionGenre);
            DramaMovie dramaMovie = new DramaMovie("The Shawshank Redemption", dramaGenre);

            // Play movies
            actionMovie.play();
            dramaMovie.play();
        }
    }
