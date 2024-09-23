import java.util.Scanner;

public class buttons {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int matchAmount = input.nextInt();

        int i = 0;
        for(i=0; i<matchAmount ; i++) {
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();

            if (c % 2 == 1) {
                b--;
            }

            if (a > b) {
                System.out.println("First");
            } else if (a <= b) {
                System.out.println("Second");
            }
        }
    }
}
