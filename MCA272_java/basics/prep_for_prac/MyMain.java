abstract class Vehicle {
    String VehicleType;

    public abstract void setVehicleType(String VehicleType);

}


public class MyMain {
    public static void main(String args[]) {
        MyMain o = new MyMain();
        o.justPrint();
        System.out.println("Good morning");
    }
    public void justPrint() {
        System.out.println("Good");
    }
}