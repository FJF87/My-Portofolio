package com.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputUser = new Scanner(System.in);

        System.out.print("Enter the first complex number: ");
        double newReal = inputUser.nextDouble();
        double newImaginary = inputUser.nextDouble();

        Complex complex1 = new Complex(newReal, newImaginary);

        System.out.print("Enter the second complex number: ");
        newReal = inputUser.nextDouble();
        newImaginary = inputUser.nextDouble();

        Complex complex2 = new Complex(newReal, newImaginary);

        System.out.println(operationText(complex1, complex2, "+") + operationResult(complex1.add(complex2)));
        System.out.println(operationText(complex1, complex2, "-") + operationResult(complex1.subtract(complex2)));
        System.out.println(operationText(complex1, complex2, "*") + operationResult(complex1.multiply(complex2)));
        System.out.println(operationText(complex1, complex2, "/") + operationResult(complex1.divide(complex2)));
        System.out.println("|" + complex1.toString() + "| = " + complex1.abs());
        System.out.println("|" + complex2.toString() + "| = " + complex2.abs());

        inputUser.close();
    }

    public static String operationResult(double[] result) {
        return (result[0] + " + " + result[1]);
    }

    public static String operationText(Complex complex1, Complex complex2, String operationSymbol) {
        return (complex1.toString() + " " + operationSymbol + " " + complex2.toString() + "i = ");
    }
}