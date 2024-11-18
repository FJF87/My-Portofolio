/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.oop_sesi_8;

/**
 *
 * @author Jeffrey
 */
public class User {
    public String id;
    public String name;
    public int age;
    
    public User(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }
    
    public void login(){
        System.out.println("Logged in");
    }
    
    public void displayInfo(){
        System.out.printf("id: %s\n name: %s\nage: %d\n", this.id, this.name, this.age);
    }
    
    public void displayInfo(String additionalInfo){
        System.out.printf("id: %s\n name: %s\nage: %d\nadditional info: %s", this.id, this.name, this.age, additionalInfo);
    }
}
