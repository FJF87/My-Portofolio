/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

import java.util.ArrayList;
import java.util.List;

// Shop class
public class Shop {
    private int shopId;
    private String name;
    private String location;
    private List<Product> products = new ArrayList<>();
    private List<Employee> employees = new ArrayList<>();
    private List<Order> orders = new ArrayList<>();

    public Shop(int shopId, String name, String location) {
        this.shopId = shopId;
        this.name = name;
        this.location = location;
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }

    public void hireEmployee(Employee employee) {
        employees.add(employee);
    }

    public void fireEmployee(Employee employee) {
        employees.remove(employee);
    }
    
    public void countingOrder() {
        System.out.printf("%s has %d orders", this.name, this.orders.size());
    }
    
    public String getName() {
        return this.name;
    }
    
    public String getLocation() {
        return this.location;
    }
}