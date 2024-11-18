/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.classdiagramsesi6;

import java.util.ArrayList;
import java.util.List;

// Category class
public class Category {
    private int categoryId;
    private String name;
    private List<Product> products = new ArrayList<>();

    public Category(int categoryId, String name) {
        this.categoryId = categoryId;
        this.name = name;
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }
}