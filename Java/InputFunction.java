import java.util.Scanner;

public class InputFunction {
    int number = 12;
    public void sayHello() {
        System.out.println("hello world");
    }
    static void printData(String name, int age) {
        System.out.println("Hello " + name);
        System.out.println("Your age is " + age);
    }
    static int getAge(Scanner userInput) {
        // Scanner userInput = new Scanner(System.in);
        int age = userInput.nextInt();
        return age;
    }
    static String getName(Scanner userInput) {
        // Scanner userInput = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = userInput.nextLine();
        return name;
    }
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);
        String name = getName(userInput);
        System.out.print("Enter your age: ");
        int age = getAge(userInput);
        printData(name, age);
    }
}
