package socialmedia;

abstract class User {
    protected String userId;
    protected String userName;
    protected String userEmail;

    public User(String userId, String userName, String userEmail){
        this.userId = userId;      
        this.userName = userName;
        this.userEmail = userEmail;
    }

    abstract void displayProfile();
}