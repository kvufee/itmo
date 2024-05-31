package ru.billing.stocklist;

import java.time.LocalDate;

public class FoodItem {
    public FoodItem(String name, float price, FoodItem analog, LocalDate date, short expires)
    {
        Name = name;
        Price = price;
        Analog = analog;
        Date = date;
        Expires = expires;
    }

    public FoodItem(String name, float price, short expires)
    {
        this.Name = name;
        this.Price = price;
        this.Expires = expires;
    }

    public FoodItem(String name)
    {
        this.Name = name;
    }

    private String Name;
    private float Price;
    private FoodItem Analog;
    private LocalDate Date;
    private short Expires;

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public float getPrice() {
        return Price;
    }

    public void setPrice(float price) {
        Price = price;
    }

    public FoodItem getAnalog() {
        return Analog;
    }

    public void setAnalog(FoodItem analog) {
        Analog = analog;
    }

    public LocalDate getDate() {
        return Date;
    }

    public void setDate(LocalDate date) {
        Date = date;
    }

    public short getExpires() {
        return Expires;
    }

    public void setExpires(short expires) {
        Expires = expires;
    }

    void printAll()
    {
        System.out.println("Name: " + Name + ", Price: " + Price + ", Food: " + Analog + ", Date: " + Date + ", Expires: " + Expires);
    }
}
