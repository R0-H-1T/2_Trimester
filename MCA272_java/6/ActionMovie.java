
package cinema;

public class ActionMovie implements Movie<ActionGenre> {
    private String title;
    private ActionGenre genre;

    public ActionMovie(String title, ActionGenre genre) {
        this.title = title;
        this.genre = genre;
    }

    @Override
    public String getTitle() {
        return title;
    }

    @Override
    public ActionGenre getGenre() {
        return genre;
    }

    @Override
    public void play() {
        System.out.println("Playing action movie: " + title);
    }
}
