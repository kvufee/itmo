package ru.billing.stocklist;

public class TechnicalItem
{
    public Category Category;

    public TechnicalItem(String name, float price, Category category)
    {
        this.ID = TechnicalItem.CurrentID++;
        Name = name;
        Price = price;
        CurrentCategory = category;
    }

    public TechnicalItem(String name, float price, TechnicalItem analog)
    {
        this.ID = TechnicalItem.CurrentID++;
        Name = name;
        Price = price;
        CurrentCategory = analog.CurrentCategory;
    }

    public TechnicalItem()
    { }

    public static int CurrentID = 0;
    private int ID;
    private String Name;
    private float Price;
    private Category CurrentCategory = Category.OTHER;
    void printAll()
    {
        System.out.println("ID: " + CurrentID + ", Name: " + Name + ", Price: " + Price + ", Category: " + CurrentCategory);
    }

    public static int getCurrentID() {
        return CurrentID;
    }

    public static void setCurrentID(int currentID) {
        CurrentID = currentID;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

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

    public Category getCurrentCategory() {
        return CurrentCategory;
    }

    public void setCurrentCategory(Category currentCategory) {
        CurrentCategory = currentCategory;
    }
}
