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
    private int ID;
    private String Name;
    private float Price;
    private Category CurrentCategory = lab3.Category.OTHER;
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

    public lab3.Category getCurrentCategory() {
        return CurrentCategory;
    }

    public void setCurrentCategory(lab3.Category currentCategory) {
        CurrentCategory = currentCategory;
    }
}
