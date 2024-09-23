import java.util.Scanner;

public class arithmeticArray {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int testCase = input.nextInt();

        for(int i = 0; i < testCase; i++) {
            int inputAmount = input.nextInt();
            double totalInputNumber = 0;
            for(int j = 0; j < inputAmount ; j++) {
                int newNumber = input.nextInt();
                totalInputNumber += newNumber;
            }

            if (totalInputNumber / inputAmount == 1) {
                System.out.println(0);
            } else if (totalInputNumber / inputAmount < 1) {
                System.out.println(1);
            } else if (totalInputNumber / inputAmount > 1) {
                System.out.println( (int)(totalInputNumber - inputAmount));
            }
            // } else {
            //     // System.out.println( (inputAmount + 1) - totalInputNumber );
            //     System.out.println( inputAmount - () );
            // }
        }
    }
}