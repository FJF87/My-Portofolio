package com.example;

public class Rectangle {
    double width;
    double height;

    public Rectangle() {
        this.width = 1;
        this.height = 1;
    }

    public Rectangle(double newWidth, double newHeight) {
        this.width = newWidth;
        this.height = newHeight;
    }

    public double getArea(){
        return (this.width * this.height);
    }

    public double[] getPerimeter() {
        // returning width and heigth in an array
        
        double[] widthAndHeight = {this.width, this.height};

        return widthAndHeight;
    }
}
