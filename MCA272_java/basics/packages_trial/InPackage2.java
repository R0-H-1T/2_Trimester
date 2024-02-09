package package2;
import package1.InPackage1;

public class InPackage2 {
    public int year1 = 2012;
    protected int year2 = 2023;
    private int year3 = 2011;
    int year4 = 2001;

    public static void main(String args[]) {
        InPackage1 p1 = new InPackage1();

        System.out.println("Age1: " + p1.age1);
        System.out.println("Age2: " + p1.age2);
        System.out.println("Age3: " + p1.age3);
        System.out.println("Age4: " + p1.age4);
    }
}