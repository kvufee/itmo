package lab3;

import java.util.Date;

public class GenericItem
{
    public static void main(String[] args)
    {
        Item first = new Item();
        Item second = new Item();
        Item third = new Item();

        first.ID = 1;
        first.Name = "Protein";
        first.Price = 100.5F;
        first.Category = Category.FOOD;
        first.printAll();

        second.ID = 2;
        second.Name = "HQD Titan";
        second.Price = 1050F;
        second.Category = Category.OTHER;
        second.printAll();

        third.ID = 3;
        third.Name = "Milk";
        third.Price = 120.33F;
        third.printAll();
    }
}

class Item
{
    public lab3.Category Category;

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
    { }

    public int ID;
    public String Name;
    public float Price;
    public Category CurrentCategory = lab3.Category.OTHER;
    public static int currentID;
    void printAll()
    {
        System.out.println("ID: " + ID + ", Name: " + Name + ", Price: " + Price + ", Category: " + CurrentCategory);
    }
}

class Food
{
    public Food(String name, float price, Food analog, Date date, short expires)
    {
        Name = name;
        Price = price;
        Analog = analog;
        Date = date;
        Expires = expires;
    }

    public Food(String name, float price, short expires)
    {
        this.Name = name;
        this.Price = price;
        this.Expires = expires;
    }

    public Food(String name)
    {
        this.Name = name;
    }

    public String Name;
    public float Price;
    public Food Analog;
    public Date Date;
    public short Expires;
    void printAll()
    {
        System.out.println("Name: " + Name + ", Price: " + Price + ", Food: " + Analog + ", Date: " + Date + ", Expires: " + Expires);
    }
}