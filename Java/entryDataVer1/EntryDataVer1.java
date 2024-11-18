/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.entrydataver1;

import java.util.Scanner;
import java.util.ArrayList;

/**
 *
 * @author Jeffrey
 */
public class EntryDataVer1 {
    public static void main(String[] args) {
        ArrayList<Integer> no = new ArrayList<Integer>();
        ArrayList<String> name = new ArrayList<String>();
        ArrayList<String> pass = new ArrayList<String>();
        ArrayList<String> phone = new ArrayList<String>();
        
        int menu = 0;
        int index = 1;
        Scanner input = new Scanner(System.in);
        
        do {
            do {
                menu = chooseMenu();
            }while(menu < 0 && menu > 5);
            
            if(menu == 1) {
                System.out.print("Name : ");
                String newName = input.nextLine();
                
                System.out.print("Pass : ");
                String newPass = input.nextLine();
                
                System.out.print("Phone : ");
                String newPhone = input.nextLine();
                
                no.add(index);
                name.add(newName);
                pass.add(newPass);
                phone.add(newPhone);
                index++;
                
                System.out.println("New data is added");
            } else if(menu == 2) {
                printHeader();
                if(no.size() <= 0) {
                    System.out.println("No data exist!\n");
                } else {
                    for(int j = 0; j < no.size(); j++) {
                        printContent(no.get(j), name.get(j), pass.get(j), phone.get(j));
                    }
                }
            } else if(menu == 3) {
                printHeader();
                if(no.size() < 0) {
                    System.out.println("No data exist!");
                } else {
                    for(int j = 0; j < no.size(); j++) {
                        printContent(no.get(j), name.get(j), pass.get(j), phone.get(j));
                    }
                }
                
                System.out.print("Input data number to be deleted: ");
                int dataToBeDeleted = input.nextInt();
                
                no.remove(dataToBeDeleted-1);
                name.remove(dataToBeDeleted-1);
                pass.remove(dataToBeDeleted-1);
                phone.remove(dataToBeDeleted-1);
                
                System.out.println("Data is removed");
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
