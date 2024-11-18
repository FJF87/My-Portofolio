package com.example;

public class Student extends Person {
    final String classStatus = "freshman";  // freshman/sophomore/junior/senior

    @Override public void description() {
        System.out.printf("Name: %s\nClass: Student\n", this.name);
    }
}
