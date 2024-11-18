package com.example;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        ArrayList<Rectangle> rectangles = new ArrayList<Rectangle>();
        int operation = 0;

        while (operation != 4) {
            Scanner userInput = new Scanner(System.in);
            showOperation();
            operation = userInput.nextInt();

            if (operation == 1) {
                System.out.print("Input width: ");
                double newWidth = userInput.nextDouble();
                System.out.print("Input height: ");
                double newHeight = userInput.nextDouble();

                Rectangle newRectangle = new Rectangle(newWidth, newHeight);
                rectangles.add(newRectangle);

                System.out.println("New rectangle successfully added");
            } else if (operation == 2) {
                System.out.print("Input width: ");
                double deleteWidth = userInput.nextDouble();
                System.out.print("Input height: ");
                double deleteHeight = userInput.nextDouble();

                Rectangle deleteRectangle = new Rectangle(deleteWidth, deleteHeight);

                int i = 0;
                for (i=0;i<rectangles.size();i++) {
                    Rectangle currRectangle = rectangles.get(i);
                    if ( Arrays.equals(currRectangle.getPerimeter(), deleteRectangle.getPerimeter()) ) {
                        System.out.println("same!");
                        rectangles.remove(i);
                    }
                }

                rectangles.remove(deleteRectangle);
                System.out.println("Rectangles successfully deleted");
            } else if (operation == 3) {
                int i = 0;
                for (i=0;i<rectangles.size();i++) {
                    Rectangle currRectangle = rectangles.get(i);
                    System.out.printf("Width: %f Height: %f Area: %f", currRectangle.getPerimeter()[0], currRectangle.getPerimeter()[1], currRectangle.getArea());
                    System.out.print("\n");
                }
                System.out.print("\n");
            } else if (operation == 4) {
                userInput.close();
                System.out.println("Have a good day!");
            }
        }
    }

    public static void showOperation() {
        System.out.println("==================");
        System.out.println("1. Add rectangle");
        System.out.println("2. Remove rectangle");
        System.out.println("3. Show area list");
        System.out.println("4. Exit");
        System.out.println("==================");
        System.out.print("Input : ");
    }
}