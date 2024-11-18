/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

import java.util.ArrayList;
import java.util.List;

// Customer class
public class Customer {
    private int customerId;
    private String name;
    private String email;
    private String phoneNumber;
    private List<Order> orders = new ArrayList<>();

    public Customer(int customerId, String name, String email, String phoneNumber) {
        this.customerId = customerId;
        this.name = name;
        this.email = email;
        this.phoneNumber = phoneNumber;
    }

    public void placeOrder(Order order) {
        orders.add(order);
    }

    public void viewOrderHistory() {
        for (Order order : orders) {
            System.out.println(order);
        }
    }
}