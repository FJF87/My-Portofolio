package com.example;

public final class Triangle extends GeometricObject {
    private double side1;
    private double side2;
    private double side3;

    public Triangle() {
        this.side1 = 1;
        this.side2 = 1;
        this.side3 = 1;
    }

    public Triangle(double new1, double new2, double new3) {
        this.side1 = new1;
        this.side2 = new2;
        this.side3 = new3;
    }

    public double getSide1() {
        return this.side1;
    }

    public double getSide2() {
        return this.side2;
    }

    public double getSide3() {
        return this.side3;
    }

    public double getArea() {
        double s = (this.side1 + this.side2 + this.side3) / 2;
        double area = Math.sqrt(s * Math.abs(s - this.side1) * Math.abs(s - this.side2) * Math.abs(s - this.side3));
        return area;
    }

    public double[] getPerimeter() {
        double[] perimeters = {this.side1, this.side2, this.side3};
        return perimeters;
    }

    @Override public String toString() {
        return "Triangle: side1 = " + this.side1 + " side2 = " + this.side2 + " side3 = " + this.side3;
    }
}