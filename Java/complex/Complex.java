package com.example;

public class Complex implements Cloneable {
    double a;
    double b;

    public Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public Complex(double a) {
        this.a = a;
        this.b = 0;
    }

    public Complex() {
        this.a = 0;
        this.b = 0;
    }

    public double getRealPart() {
        return this.a;
    }

    public double getImaginaryPart() {
        return this.b;
    }

    public double[] add(double otherA, double otherB) {
        double[] result = {(this.a + otherA), (this.b + otherB)};
        return result;
    }
    public double[] add(Complex complex2) {
        double[] result = {(this.a + complex2.a), (this.b + complex2.b)};
        return result;
    }

    public double[] subtract(double otherA, double otherB) {
        double[] result = {(this.a - otherA), (this.b - otherB)};
        return result;
    }
    public double[] subtract(Complex complex2) {
        double[] result = {(this.a - complex2.a), (this.b - complex2.b)};
        return result;
    }

    public double[] multiply(double otherA, double otherB) {
        double[] result = {((this.a*otherA) - (this.b*otherB)), ((this.b*otherA) + (this.a*otherB))};
        return result;
    }
    public double[] multiply(Complex complex2) {
        double[] result = {((this.a*complex2.a) - (this.b*complex2.b)), ((this.b*complex2.a) + (this.a*complex2.b))};
        return result;
    }

    public double[] divide(double otherA, double otherB) {
        double[] result = { (((this.a*otherA) + (this.b*otherB)) / (Math.pow(otherA,2) + Math.pow(otherB,2) )), ((this.b*otherA) - (this.a*otherB)) / (Math.pow(otherA,2) + Math.pow(otherB,2) )};
        return result;
    }
    public double[] divide(Complex complex2) {
        double[] result = { (((this.a*complex2.a) + (this.b*complex2.b)) / (Math.pow(complex2.a,2) + Math.pow(complex2.b,2) )), ((this.b*complex2.a) - (this.a*complex2.b)) / (Math.pow(complex2.a,2) + Math.pow(complex2.b,2) )};
        return result;
    }

    public double abs() {
        return (Math.sqrt( (Math.pow(a, 2)) + Math.pow(b, 2) ));
    }

    @Override public String toString() {
        String result = "(" + this.a + " + " + this.b + "i)";
        return result;
    }
}
