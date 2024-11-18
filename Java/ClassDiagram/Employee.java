/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

// Employee class
public class Employee {
    private int employeeId;
    private String name;
    private String position;
    private float salary;

    public Employee(int employeeId, String name, String position, float salary) {
        this.employeeId = employeeId;
        this.name = name;
        this.position = position;
        this.salary = salary;
    }

    public void processOrder(Order order) {
        System.out.printf("%s processing order: \n", this.name);
        System.out.println("calculating total...");
        System.out.printf("Total: %f\n", order.calculateTotal());
        System.out.println("updating status...");
        order.updateStatus("done");
        System.out.println("done updating status");
    }

    public float calculateSalary(int hoursWorked) {
        return salary * hoursWorked;
    }
    
    public void introduction(Shop shop) {
        System.out.printf("Hello, my name is %s", this.name);
        System.out.printf("I'm working at %s shop located in %s", shop.getName(), shop.getLocation());
    }
}