package com.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        StopWatch stopWatch = new StopWatch();
        Scanner userInput = new Scanner(System.in);
        int operation = 0;
        
        while (operation != 5) {
            showOperation();
            operation = userInput.nextInt();
            
            if (operation == 1) {
                stopWatch.start();
            } else if (operation == 2) {
                stopWatch.end();
            } else if (operation == 3) {
                System.out.printf("start: %d stop: %d\n", stopWatch.getStartTime(), stopWatch.getEndTime());
            } else if (operation == 4) {
                System.out.printf("Elapsed time: %d millis\n", stopWatch.getElapsedTime());
            }
        }

        userInput.close();
    }

    public static void showOperation() {
        System.out.println("============================");
        System.out.println("Stopwatch");
        System.out.println("1. Set start");
        System.out.println("2. Set end");
        System.out.println("3. Print start and end");
        System.out.println("4. Print elapsed time");
        System.out.println("5. Exit");
        System.out.println("============================");
        System.out.print("Input : ");
    }
}