package socialmedia;

import java.util.ArrayList;


public class RegularUser extends User implements Post{
    private ArrayList<Integer> postList = new ArrayList<Integer>();
    private ArrayList<String> postMsgs = new ArrayList<String>();
    public int postId = 0;

    public RegularUser(String userId, String userName, String userEmail) {
        super(userId, userName, userEmail);
    }

    public void displayProfile(){
        System.out.print(super.userId + " " + super.userName + " " + super.userEmail);
    }

    @Override
    public int createPost(String content) {
        postMsgs.add(content);
        postList.add(postId);
        return postId++;
    }

    @Override
    public void displayPost(int postId) {
        if (postMsgs.isEmpty()) {
            System.out.println("No posts of user.");
        }
        for(int i=0; i<postList.size(); i++) {
            System.out.println("\nComment: " + postMsgs.get(postList.get(i)));
        }
    }
}