/**
 * Test
 */

import java.util.Scanner;

import socialmedia.AdminUser;
import socialmedia.RegularUser;

public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        RegularUser reg_user1 = new RegularUser("1", "Rohit Tank", "rowhittank@gmail.com");
        reg_user1.displayProfile();
        reg_user1.displayPost(reg_user1.createPost("What a lovely day it is.\n"));   
        reg_user1.displayPost(reg_user1.createPost("Not working out."));   

        AdminUser mick = new AdminUser("2", "Michael Scott", "michael@g.com", "Read, Write");
        AdminUser rick = new AdminUser("4", "Rick Morty", "rick@g.com", "Read, Execute");
        mick.displayProfile();        
        rick.displayProfile();

    }
}