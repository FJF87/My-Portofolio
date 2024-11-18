/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.entrydataver2;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Jeffrey
 */

class Person {
    int no;
    String name;
    String pass;
    String phone;
    
    public Person(int no, String name, String pass, String phone) {
        this.no = no;
        this.name = name;
        this.pass = pass;
        this.phone = phone;
    }
    
    public int getNo() {
        return this.no;
    }
    
    public void setName(String name) {
        this.name = name;
    }
    
    public String getName() {
        return this.name;
    }
    
    public void setPass(String pass) {
        this.pass = pass;
    }
    
    public String getPass() {
        return this.pass;
    }
    
    public void setPhone(String phone) {
        this.phone = phone;
    }
    
    public String getPhone() {
        return this.phone;
    }
}

public class EntryDataVer2 {
    public static void main(String[] args) {
        ArrayList<Person> personList = new ArrayList<Person>();
//        ArrayList<Integer> no = new ArrayList<Integer>();
//        ArrayList<String> name = new ArrayList<String>();
//        ArrayList<String> pass = new ArrayList<String>();
//        ArrayList<String> phone = new ArrayList<String>();
        
        int menu = 0;
        int index = 1;
        Scanner input = new Scanner(System.in);
        
        do {
            do {
                menu = chooseMenu();
            }while(menu < 0 && menu > 5);
            
            if(menu == 1) {
                input.nextLine();
                System.out.print("Name : ");
                String newName = input.nextLine();
                
                System.out.print("Pass : ");
                String newPass = input.nextLine();
                
                System.out.print("Phone : ");
                String newPhone = input.nextLine();
                
                Person newPerson = new Person(index, newName, newPass, newPhone);
                personList.add(newPerson);
                
//                no.add(index);
//                name.add(newName);
//                pass.add(newPass);
//                phone.add(newPhone);
                index++;
                
                System.out.println("New data is added");
            } else if(menu == 2) {
                printHeader();
                if(personList.size() <= 0) {
                    System.out.println("No data exist!\n");
                } else {
                    for(int j = 0; j < personList.size(); j++) {
//                        printContent(no.get(j), name.get(j), pass.get(j), phone.get(j));
                        Person getPerson = personList.get(j);
                        printContent(getPerson.getNo(), getPerson.getName(), getPerson.getPass(), getPerson.getPhone());
                    }
                }
            } else if(menu == 3) {
                printHeader();
                if(personList.size() < 0) {
                    System.out.println("No data exist!");
                } else {
                    for(int j = 0; j < personList.size(); j++) {
//                        printContent(no.get(j), name.get(j), pass.get(j), phone.get(j));
                        Person getPerson = personList.get(j);
                        printContent(getPerson.getNo(), getPerson.getName(), getPerson.getPass(), getPerson.getPhone());
                        
                        System.out.print("Input data number to be deleted: ");
                        int dataToBeDeleted = input.nextInt();
                        input.reset();

                        personList.remove(dataToBeDeleted - 1);

        //                no.remove(dataToBeDeleted-1);
        //                name.remove(dataToBeDeleted-1);
        //                pass.remove(dataToBeDeleted-1);
        //                phone.remove(dataToBeDeleted-1);

                        System.out.println("Data is removed");
                    }
                }
            }
        }while(menu != 4);
    }
    
    
    static void printMenu() {
        System.out.println("1. Input Data");
        System.out.println("2. Show Data");
        System.out.println("3. Delete data");
        System.out.println("4. Exit data");
    }
    
    static int chooseMenu() {
        Scanner input = new Scanner(System.in);
              
        printMenu();
        
        System.out.print("Your choice: ");
        int choiceNumber = input.nextInt();
        
        return choiceNumber;
    }
    
    static void printBorder() {
        for(int i = 0; i < 40; i++) {
            System.out.print("=");
        }
        System.out.println();
    }
    
    
    
    static void printHeader() {
        printBorder();
        System.out.printf("|%2s|%10s|%10s|%10s|\n", "No", "Name", "Pass", "Phone");
        printBorder();
    }
    
    static void printContent(int number, String name, String pass, String phone) {
        System.out.printf("|%2s|%10s|%10s|%10s|\n", number, name, pass, phone);
        printBorder();
    }
}
