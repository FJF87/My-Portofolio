/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.simpleLibrary;

/**
 *
 * @author Jeffrey
 */
public class SimpleLibrary {

    public static void main(String[] args) {
        Admin admin = new Admin("A001", "Jono", 31);
        Student student = new Student("S001", "Joni", 12);
        
        admin.login();
        student.login();
        
        System.out.println("\nadmin info");
        admin.displayInfo();
        
        System.out.println("\nadmin with additional info");
        admin.displayInfo("work since 1999");
        
        System.out.println("\nstudent info");
        student.displayInfo();
        
        System.out.println("\nstudent with additional info");
        student.displayInfo("in class A1");
    }
}
