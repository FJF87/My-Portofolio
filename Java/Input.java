import java.util.Scanner;

public class Input {
    public static void main(String[] args) {
        Scanner inputUser = new Scanner(System.in);
        System.out.print("enter your name: ");
        String name = inputUser.nextLine();
        int age;
        System.out.print("Enter your age: ");
        age = inputUser.nextInt();
        System.out.println("Hello " + name);
        System.out.println("Your age is " + age);
    }
}
