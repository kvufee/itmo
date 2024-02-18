package lab3;

import java.time.LocalDate;

public class Food
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
