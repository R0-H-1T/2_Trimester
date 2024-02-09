
class Bird {
    int age;
    Bird(){  
        System.out.println("Parent class constructor invoked");
    }
    Bird(int age) {
        this.age = age;
        System.out.println("Parent class constructor invoked");
    }
}

public class TestMain extends Bird{
    public static void main(String[] args) {
        Bird parrot = new Bird();
        Bird pigeon = new Bird(6);
        System.out.println("Pigeon age: " + pigeon.age);
        //pigeon.age
    }
}
