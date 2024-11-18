package com.example;

public class ComparableCircle extends Circle implements Comparable {
    public ComparableCircle(double radius) {
        super(radius);
    }

    public String max() {
        return "Nothing to be compared";
    }

    public String max(ComparableCircle circle2) {
        if (this.radius > circle2.radius) {
            return "first circle is bigger";
        } else if (this.radius < circle2.radius) {
            return "second circle is bigger";
        } else if (this.radius == circle2.radius) {
            return "it's the same!";
        } else {
            return "Error! Make sure the property is right";
        }
    }

    public String toString() {
        return ("This circle has size " + this.radius + " radius");
    }
}
