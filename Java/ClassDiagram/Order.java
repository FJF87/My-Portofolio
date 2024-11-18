/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

import java.util.Date;
import java.util.List;

// Order class
public class Order {
    private int orderID;
    private Date orderDate;
    private Customer customer;
    private List<Product> products;
    private float totalAmount;
    private String status;
    
    public Order(int orderId, Date orderDate, Customer customer) {
        this.orderID = orderId;
        this.orderDate = orderDate;
        this.customer = customer;
    }
    
    public float calculateTotal() {
        float total = 0;
        for(Product product: this.products){
            total += product.getPrice();
        };
        return total;
    }
    
    public void updateStatus(String status) {
        this.status = status;
    }
}
