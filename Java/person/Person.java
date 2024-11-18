package com.example;

public class Person {
    String name;
    String address;
    String phoneNumber;
    String email;

    public void description() {
        System.out.printf("Name: %s\nClass: Person\n", this.name);
    }
}
