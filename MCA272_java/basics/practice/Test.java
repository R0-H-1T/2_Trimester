public class Test {
    
    public int age = 34;
    public static int my_age = 34;

    static int add (int num1, int num2) { return num1 + num2; }
    static double add (double num1, double num2) { return num1 + num2; }

    static PizzaSalesOrder {
        static int oredered_count;
        int deliverered_count;
        
        PizzaSalesOrder () {
            System.out.println ("N")
        }

    }

    public static void main(String[] args) {
        System.out.print("CMD args ");
        for (int i=0; i<args.length; i++) {
            System.out.print(" " + args[i]);
        }                

        System.out.println("\nInteger: " + add (3, 4));
        System.out.println("Double: " + add (3.4, 4.1));
    }

}
