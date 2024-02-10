package lab2;

import java.awt.event.ItemEvent;
import java.util.Date;

public class GenericItem
{
    public static void main(String[] args)
    {
        Item first = new Item();
        Item second = new Item();
        Item third = new Item();

        first.ID = 1;
        first.name = "Protein";
        first.price = 100.5F;
        first.category = Category.FOOD;
        first.printAll();

        second.ID = 2;
        second.name = "HQD Titan";
        second.price = 1050F;
        second.category = Category.OTHER;
        second.printAll();

        third.ID = 3;
        third.name = "Milk";
        third.price = 120.33F;
        third.printAll();
    }
}

class Item
{
    public Item(int id, String name, float price, Category category)
    {
        ID = id;
        Name = name;
        Price = price;
        CurrentCategory = category;
    }

    public Item(int id, String name, float price, Item analog)
    {
        ID = id;
        Name = name;
        Price = price;
        CurrentCategory = analog.CurrentCategory;
    }

    public Item()
    {
        
    }

    public int ID;
    public String Name;
    public float Price;
    public Category CurrentCategory = Category.OTHER;
    void printAll()
    {
        System.out.println("ID: " + ID + ", Name: " + Name + ", Price: " + Price + ", Category: " + CurrentCategory);
    }
}

class Food
{
    public String name;
    public float price;
    public Food analog;
    public Date date;
    public short expires;
    void printAll()
    {
        System.out.println("Name: " + name + ", Price: " + price + ", Food: " + analog + ", Date: " + date + ", Expires: " + expires);
    }
}