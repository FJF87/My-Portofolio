/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.oop_sesi_8;

/**
 *
 * @author Jeffrey
 */
public class Admin extends User {
    public Admin(String id, String name, int age){
        super(id, name, age);
    }
    
    public void login(){
        System.out.println("Login as Admin");
    }
}
