package com.example;

import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);
        int operation = 0;
        Vector<Account> userAccount = new Vector<Account>();

        while (operation != 8) {
            showMenu();
            operation = userInput.nextInt();

            if (operation == 1) {
                System.out.print("Input your initial balance: ");
                double initialBalance = userInput.nextDouble();
                System.out.print("Input your initial annual interest rate: ");
                double initialAnnualInterestRate = userInput.nextDouble();

                Account newAccount = new Account(userAccount.size()+1, initialBalance, initialAnnualInterestRate);
                userAccount.add(newAccount);
                System.out.printf("Your account is successfully created with id %d\n", userAccount.size());
            } else if (operation == 2) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.printf("Your account balance is %f\n", userAccount.elementAt(userId-1).getBalance());
            } else if (operation == 3) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.printf("Your annual interest rate is %f\n", userAccount.elementAt(userId-1).getAnnualInterestRate());
            } else if (operation == 4) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.printf("Your monthly interest rate is %f\n", userAccount.elementAt(userId-1).getMonthlyInterestRate());
            } else if (operation == 5) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.printf("Your monthly interest is %f\n", userAccount.elementAt(userId-1).getMonthlyInterest());
            } else if (operation == 6) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.print("Input amount of money you want to withdraw: ");
                double withdrawAmount = userInput.nextDouble();
                userAccount.elementAt(userId-1).deposit(withdrawAmount);
                System.out.println("You have successfully withdraw your money!");
                System.out.printf("Your balance now: %f\n", userAccount.elementAt(userId-1).getBalance());
            } else if (operation == 7) {
                System.out.print("Input your id: ");
                int userId = userInput.nextInt();
                System.out.print("Input amount of money you want to deposit: ");
                double depositAmount = userInput.nextDouble();
                userAccount.elementAt(userId-1).deposit(depositAmount);
                System.out.println("You have successfully deposit your money!");
                System.out.printf("Your balance now: %f\n", userAccount.elementAt(userId-1).getBalance());
            }
        }
        userInput.close();
    }

    public static void showMenu() {
        System.err.println("======================");
        System.out.println("Bank Simulation");
        System.out.println("1. Add account");
        System.out.println("2. Show balance");
        System.out.println("3. Show annual interest rate");
        System.out.println("4. Show monthly interest rate");
        System.out.println("5. Show monthly interest");
        System.out.println("6. Withdraw");
        System.out.println("7. Deposit");
        System.out.println("8. Exit");
        System.out.println("======================");
        System.out.print("Input: ");
    }

    // private static int getUserId() {
    //     Scanner inputId = new Scanner(System.in);
    //     System.out.print("Input your id: ");
    //     int userId = inputId.nextInt();

    //     inputId.close();
    //     return userId;
    // }
}