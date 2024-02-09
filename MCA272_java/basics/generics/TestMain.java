import java.util.Scanner;

class ListNode<T> {
   public T data;
   public ListNode next;

    public ListNode(T data) {
        this.data = data;
    }

    public T getData()  {
        return this.data;
    }
}

public class TestMain {
    
    public static ListNode createNode() {
        Scanner sc = new Scanner(System.in);

        return newnode;
    }

    public static ListNode createList() {
         
        return new_node;
    }

    public static void main(String[] args) {
        ListNode<String> node1 = new ListNode<>("Reynolds");
        ListNode<Integer> node2 = new ListNode<>(56);
        ListNode<Double> node3 = new ListNode<>(90.45);
        node1.next = node2;
        node2.next = node3;
        node3.next = null;

        System.out.println("Node 1 data: " + node1.data);
        System.out.println("Node 2 data: " + node2.data);
        System.out.println("Node 3 data: " + node3.data);
    }
}
