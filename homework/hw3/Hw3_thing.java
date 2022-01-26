

public class Hw3_thing {
    public int a;

    public static void main(String[] argv) {
        Hw3_thing b = new Hw3_thing();
        Hw3_thing c;

        b.a = 5;
        c = b;
        b.a = 4;

        System.out.println("" + b.a);
        System.out.println("" + c.a);
    }
}
