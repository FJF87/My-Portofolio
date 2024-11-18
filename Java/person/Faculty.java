package com.example;

public class Faculty extends Employee {
    int officeHours;
    String rank;

    @Override public void description() {
        System.out.printf("Name: %s\nClass: Faculty\n", this.name);
    }
}
