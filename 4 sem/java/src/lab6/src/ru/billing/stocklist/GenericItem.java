package lab6.src.ru.billing.stocklist;

import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Date;

public class GenericItem
{
    public int ID;
    public String name;
    public float price;
    public ru.billing.stocklist.Category category = ru.billing.stocklist.Category.General;
    public GenericItem analog;
    public static int currentID = 0;

    public GenericItem(String name, float price, ru.billing.stocklist.Category category) {
        this.ID = currentID++;
        this.name = name;
        this.price = price;
        this.category = category;
    }

    public GenericItem(String name, float price, GenericItem analog) {
        this.ID = currentID++;
        this.name = name;
        this.price = price;
        this.analog = analog;
    }

    public GenericItem() {
        this.ID = currentID++;
    }

    public void PrintAll() {
        System.out.printf("ID: %d , Name: %-20s , price:%5.2f , category: %s\n", ID, name, price, category);
    }
}
