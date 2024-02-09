/*
 * Create an interface named Post with the following methods:
 createPost(String content): Takes a content string and returns a
post ID.
 displayPost(String postId): Takes a post ID and displays the
details of the post.
 */

package socialmedia;

public interface Post {

    public int createPost(String content);
    
    public void displayPost(int postId);
}