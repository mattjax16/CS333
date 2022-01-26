//This is a file to practice code for hw3 of cs333


class CS333HW3 {
    public static void main(String[] args) {

        int x = 0;

        System.out.print("(x++ == x++) :");
        System.out.println(x++ == x++);
        System.out.println("(x++ on left = 0 and x++ on right = 1");
        System.out.println("The value of x after the expression is evaluated is 2\n");


        x = 0;

        System.out.print("(x++ == ++x) :");
        System.out.println(x++ == ++x);
        System.out.println("(x++ on left = 0 and ++x on right = 2");
        System.out.println("The value of x after the expression is evaluated is 2\n");



        x = 0;

        System.out.print("(++x == x++) :");
        System.out.println(++x == x++);
        System.out.println("(++x on left = 1 and x++ on right = 1");
        System.out.println("The value of x after the expression is evaluated is 2\n");

        x = 0;

        System.out.print("(++x == ++x) :");
        System.out.println(++x == ++x);
        System.out.println("(++x on left = 1 and ++x on right = 2");
        System.out.println("The value of x after the expression is evaluated is 2\n");


    }
}