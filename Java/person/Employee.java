package com.example;

import java.util.Date;

public class Employee extends Person {
    String office;
    double salary;
    Date dateHired;

    @Override public void description() {
        System.out.printf("Name: %s\nClass: Employee\n", this.name);
    }
}
