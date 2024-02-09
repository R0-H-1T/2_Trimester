class Outer {

    int outer_x = 100;
    int y = 20;

    void test() {
        InnerClass ic = new InnerClass();
        ic.display(); 
        ic.show(); 
    }

    class InnerClass{
        int y = 10;
        void display() {
            System.out.println("Display outer x: " + outer_x);
        }
        void show() { 
            System.out.println("y: " + y);
        }
    }

}


public class InnerClassDemo {
    public static void main( String[] args ) {
       Outer obj1 = new Outer();
       obj1.test();
    }
}
