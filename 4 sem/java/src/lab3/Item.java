package lab3;

public class Item
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
