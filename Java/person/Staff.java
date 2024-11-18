package com.example;

public class Staff extends Employee {
    String title;

    @Override public void description() {
        System.out.printf("Name: %s\nClass: Staff\n", this.name);
    }
}
