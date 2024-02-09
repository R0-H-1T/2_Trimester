package cinema;

public class DramaMovie implements Movie<DramaGenre> {
    private String title;
    private DramaGenre genre;

    public DramaMovie(String title, DramaGenre genre) {
        this.title = title;
        this.genre = genre;
    }

    @Override
    public String getTitle() {
        return title;
    }

    @Override
    public DramaGenre getGenre() {
        return genre;
    }

    @Override
    public void play() {
        System.out.println("Playing drama movie: " + title);
    }
}
