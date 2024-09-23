import java.util.Scanner;

public class antonAndDanik {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int matchAmount = input.nextInt();
        input.nextLine();
        String matchString = input.nextLine();

        int i = 0;
        int anton = 0;
        int danik = 0;

        for(i = 0; i < matchAmount; i++) {
            if (matchString.charAt(i) == 'A') {
                anton++;
            }
            else if (matchString.charAt(i) == 'D') {
                danik++;
            }
        }

        if (anton > danik) {
            System.out.println("Anton");
        }
        else if (danik > anton) {
            System.out.println("Danik");
        }
        else {
            System.out.println("Friendship");
        }
    }
}
