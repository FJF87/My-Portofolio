package com.example;

import java.time.LocalDate;

public class Account {
    private int id;
    private double balance;
    private double annualInterestRate;
    private LocalDate dateCreated;

    public Account() {
        this.id = 0;
        this.balance = 0;
        this.annualInterestRate = 0;
        this.dateCreated = LocalDate.now();
    }

    public Account(int newId, double newBalance, double newAnnualInterestRate) {
        this.id = newId;
        this.balance = newBalance;
        this.annualInterestRate = newAnnualInterestRate;
        this.dateCreated = LocalDate.now();
    }

    public int getId() {
        return this.id;
    }

    public void setId(int newId) {
        this.id = newId;
    }

    public double getBalance() {
        return this.balance;
    }

    public void setBalance(double newBalance) {
        this.balance = newBalance;
    }

    public double getAnnualInterestRate() {
        return this.annualInterestRate;
    }

    public void setAnnualInterestRate(double newAnnualInterestRate) {
        this.annualInterestRate = newAnnualInterestRate;
    }

    public LocalDate getDateCreated() {
        return this.dateCreated;
    }

    public double getMonthlyInterestRate() {
        return (this.annualInterestRate / 12);
    }

    public double getMonthlyInterest() {
        return (this.balance * getMonthlyInterestRate());
    }

    public void withdraw(double withdrawAmount) {
        this.balance -= withdrawAmount;
        System.out.printf("Here is your %f dollar", withdrawAmount);
    }

    public void deposit(double depositAmount) {
        this.balance += depositAmount;
        System.out.printf("Successfully deposit %f dollar into your account", depositAmount);
    }
}
