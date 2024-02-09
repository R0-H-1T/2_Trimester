
package cinema;

public class ActionGenre implements Genre {
    private String name;

    public ActionGenre(String name) {
        this.name = name;
    }

    @Override
    public String getName() {
        return name;
    }
}

