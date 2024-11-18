package com.example;

public class Circle {
    double radius;

    public Circle(double newRadius) {
        this.radius = newRadius;
    }
    public Circle() {
        this.radius = 1;
    }

    public void setRadius(double newRadius) {
        this.radius = newRadius;
    }

    public double perimeter() {
        return (Math.PI * 2 * this.radius);
    }

    public double area() {
        return (Math.PI * Math.pow(this.radius, 2));
    }
}
