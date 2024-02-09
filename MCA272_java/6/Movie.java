public interface Movie<T extends Enum<T>> {
    String getTitle();
    T getGenre();
    void play();
}

