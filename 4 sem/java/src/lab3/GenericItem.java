package lab3;

import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Date;

public class GenericItem
{
    public static void main(String[] args)
    {
        Item first = new Item("Protein", 100.5F, Category.FOOD);
        Item second = new Item("HQD Titan", 1050F, Category.OTHER);
        Food third = new Food("Fish", 300.2F, (Food) null, LocalDate.now(), (short) 13);
        Food fourth = new Food(third.Name, third.Price, third, LocalDate.now(), third.Expires);

        first.printAll();
        second.printAll();
        third.printAll();
        fourth.printAll();
    }
}

class Item
{
    public lab3.Category Category;

    public Item(String name, float price, Category category)
    {
        this.ID = Item.CurrentID++;
        Name = name;
        Price = price;
        CurrentCategory = category;
    }

    public Item(String name, float price, Item analog)
    {
        this.ID = Item.CurrentID++;
        Name = name;
        Price = price;
        CurrentCategory = analog.CurrentCategory;
    }

    public Item()
    { }

    public static int CurrentID = 0;
    public int ID;
    public String Name;
    public float Price;
    public Category CurrentCategory = lab3.Category.OTHER;
    void printAll()
    {
        System.out.println("ID: " + CurrentID + ", Name: " + Name + ", Price: " + Price + ", Category: " + CurrentCategory);
    }
}


class Food
{
    public Food(String name, float price, Food analog, LocalDate date, short expires)
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
    public LocalDate Date;
    public short Expires;
    void printAll()
    {
        System.out.println("Name: " + Name + ", Price: " + Price + ", Food: " + Analog + ", Date: " + Date + ", Expires: " + Expires);
    }
}