/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.showroom;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Jeffrey
 */

 class Cars{
    public String name;
    public int capacity;
    public float speed;

    public Cars(String name, int capacity, float speed) {
        this.name = name;
        this.capacity = capacity;
        this.speed = speed;
    }
}

 class Jeep extends Cars{
    public Jeep(String name, int capacity, float speed) {
        super(name, capacity, speed);
    }
}

 class SUV extends Cars{
    public SUV(String name, int capacity, float speed) {
        super(name, capacity, speed);
    }
}

 class Sedan extends Cars{
    public Sedan(String name, int capacity, float speed) {
        super(name, capacity, speed);
    }
}

public class Showroom {

    public static void main(String[] args) {
        ArrayList<Jeep> jeepList = new ArrayList<Jeep>();
        ArrayList<SUV> suvList = new ArrayList<SUV>();
        ArrayList<Sedan> sedanList = new ArrayList<Sedan>();
        int input = 0;
        
        while(input != 3) {
            Scanner inputUser = new Scanner(System.in);
            printMenu();
            input = inputUser.nextInt();
            
            if (input == 1) {
                System.out.println("1. Jeep");
                System.out.println("2. SUV");
                System.out.println("3. Sedan");
                System.out.print("Input : ");
                int newCarType = inputUser.nextInt();
                System.out.println();
                System.out.print("Car's name : ");
                String newCarName = inputUser.next();
                
                if(newCarType == 1) {
                    Jeep newJeep = new Jeep(newCarName, 30, 120);
                    jeepList.add(newJeep);
                } else if(newCarType == 2) {
                    SUV newSUV = new SUV(newCarName, 15, 100);
                    suvList.add(newSUV);
                } else if(newCarType == 3) {
                    Sedan newSedan = new Sedan(newCarName, 10, 120);
                    sedanList.add(newSedan);
                }
            }
            else if(input == 2) {
                System.out.println("List car");
                System.out.println("================");
                System.out.println("Jeep");
                System.out.println("================");
                jeepList.forEach( (jeep) -> System.out.println(jeep.name) );
                System.out.println("\n\n");
                System.out.println("================");
                System.out.println("SUV");
                System.out.println("================");
                suvList.forEach( (suv) -> System.out.println(suv.name) );
                System.out.println("\n\n");
                System.out.println("================");
                System.out.println("Sedan");
                System.out.println("================");
                sedanList.forEach( (sedan) -> System.out.println(sedan.name) );
                System.out.println("\n\n");
                System.out.println("================");
            }
        }
    }
    
    public static void printMenu() {
        System.out.println("SHOWROOM");
        System.out.println("===============");
        System.out.println("1. Buy");
        System.out.println("2. Show");
        System.out.println("3. Exit");
        System.out.println("Input : ");
    }
}
