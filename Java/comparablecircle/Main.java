package com.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputUser = new Scanner(System.in);

        System.out.print("Input first circle's radius: ");
        ComparableCircle circle1 = new ComparableCircle(inputUser.nextDouble());
        while (circle1.radius < 0) {
            System.out.println("Well, circle's radius cannot be negative, right?");
            System.out.print("Input positive radius for first circle please: ");
            circle1.setRadius(inputUser.nextDouble());
        }

        System.out.print("Input second circle's radius: ");
        ComparableCircle circle2 = new ComparableCircle(inputUser.nextDouble());
        while (circle2.radius < 0) {
            System.out.println("Well, circle's radius cannot be negative, right?");
            System.out.print("Input positive radius for second circle please please: ");
            circle2.setRadius(inputUser.nextDouble());
        }

        System.out.println(circle1.max(circle2));
        System.out.println("Perimeter difference: " + Math.abs(circle1.perimeter() - circle2.perimeter()));
        System.out.println("Area difference: " + Math.abs(circle1.area() - circle2.area()));

        inputUser.close();
    }
}