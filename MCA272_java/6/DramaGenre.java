package cinema;

public class DramaGenre implements Genre {
    private String name;

    public DramaGenre(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }
}
