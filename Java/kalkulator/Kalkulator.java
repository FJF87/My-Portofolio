/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.kalkulator;

import java.util.Scanner;

/**
 *
 * @author Jeffrey
 */
public class Kalkulator {
    public static void main(String[] args) {
        double firstNumber = 0.0d;
        double otherNumber = 0.0d;
        double numberNow = 0.0d;
        int operation = 0;
        
        while(operation != 7) {
            printHeader(numberNow);
            
            if(operation == 0) {
                firstNumber = inputNumber();
            } else {
                firstNumber = numberNow;
            }
            
            operation = inputOperation();
            
            if(operation >= 1 && operation <= 5) {
                otherNumber = inputNumber();
            }
            
            numberNow = operation(firstNumber, operation, otherNumber);
            
            System.out.flush();
        }
    }
    
    static void printHeader(double angkaSekarang) {
        System.out.println("Calculator");
        System.out.println("=================");
        System.out.printf("Total = %f\n\n\n", angkaSekarang);
    }
    
    static void printOperation() {
        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Modulo");
        System.out.println("6. Clear Total");
        System.out.println("7. Exit");
    }
    
    static int inputOperation() {
        Scanner input = new Scanner(System.in);
        printOperation();
        int operation = 0;
//        while(operation < 1 && operation > 7) {
            System.out.print("Operator [1..7]: ");
            operation = input.nextInt();
//        }
        return operation;
    }
    
    static double inputNumber() {
        Scanner input = new Scanner(System.in);
        System.out.print("Input number : ");
        double number = input.nextDouble();
        return number;
    }
    
    static double operation(double firstNumber, int operationNumber, double secondNumber) {
        double result = 0.0d;
        if(operationNumber == 1) {
            result = firstNumber + secondNumber;
        } else if(operationNumber == 2) {
            result = firstNumber - secondNumber;
        } else if(operationNumber == 3) {
            result = firstNumber * secondNumber;
        } else if(operationNumber == 4) {
            result = firstNumber / secondNumber;
        } else if(operationNumber == 5) {
            result = firstNumber % secondNumber;
        }
        return result;
    }
}
