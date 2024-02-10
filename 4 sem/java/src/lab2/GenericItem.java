package lab2;

import java.awt.event.ItemEvent;

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
    public int ID;
    public String name;
    public float price;
    public Category category = Category.OTHER;
    void printAll()
    {
        System.out.println("ID: " + ID + ", Name: " + name + ", Price: " + price + ", Category: " + category);
    }
}