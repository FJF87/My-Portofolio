/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

// Product class
public class Product {
    private int productId;
    private String name;
    private float price;
    private int quantity;
    private Category category;

    public Product(int productId, String name, float price, int quantity, Category category) {
        this.productId = productId;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
        this.category = category;
    }

    public void updateStock(int quantity) {
        this.quantity += quantity;
    }

    public float getPrice() {
        return price * quantity;
    }
    
    public void advertise(Shop shop) {
        System.out.printf("%s is sold in %s shop in %s", this.name, shop.getName(), shop.getLocation());
    }
}