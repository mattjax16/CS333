//Matthew Bass
//Java garbage collection tests
//CS333
//Project 7

import java.util.ArrayList;

public class garbageTest {
    
    public static void main(String[] args) {

        //create large array 100 times
        for (int i = 0; i < 100; i++) {
            long start = System.currentTimeMillis();
            ArrayList<Integer> arr = new ArrayList<Integer>(10000000);
            long end = System.currentTimeMillis();
            // print the iteration and the elapsed time
            System.out.println("iteration " + i + " loop duration: " + (end-start) + " milliseconds");

            // check if the array creation took longer than 36 milliseconds
            if ((end-start) > 35) {
                System.out.println("garbage likely collected");
            }
        }
    }
}
// end class