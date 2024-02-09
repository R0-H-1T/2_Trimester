/**
 * AdminUser
 */

 package socialmedia;

public class AdminUser extends User{

    String permissions;

    public AdminUser(String userId, String userName, String userEmail, String permissions) {
        super(userId, userName, userEmail);
        this.permissions = permissions;
    }  

    @Override
    public void displayProfile() { 
        System.out.println(super.userId + " " + super.userName + " " + super.userEmail + " Permissions: "+ this.permissions);   
    }

}