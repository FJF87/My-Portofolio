package com.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);

        System.out.println("Creating new triangle");
        System.out.print("Input side 1 length: ");
        double new1 = userInput.nextDouble();
        System.out.print("Input side 2 length: ");
        double new2 = userInput.nextDouble();
        System.out.print("Input side 3 length: ");
        double new3 = userInput.nextDouble();

        Triangle triangle = new Triangle(new1, new2, new3);

        int operation = 0;

        while (operation != 6) {
            showMenu();
            operation = userInput.nextInt();

            if (operation == 1) {
                System.out.println(triangle.getSide1());
            } else if (operation == 2) {
                System.out.println(triangle.getSide2());
            } else if (operation == 3) {
                System.out.println(triangle.getSide3());
            } else if (operation == 4) {
                System.out.println(triangle.getArea());
            } else if (operation == 5) {
                System.out.println(triangle.toString());
            }
        }
        userInput.close();
    }

    public static void showMenu() {
        System.out.println("=====================");
        System.out.println("1. Side 1");
        System.out.println("2. Side 2");
        System.out.println("3. Side 3");
        System.out.println("4. Area");
        System.out.println("5. Description");
        System.out.println("6. Exit");
        System.out.println("=====================");
        System.out.print("Input: ");
    }
}