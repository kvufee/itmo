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
        Food fourth = new Food(third.getName(), third.getPrice(), third, LocalDate.now(), third.getExpires());

        first.printAll();
        second.printAll();
        third.printAll();
        fourth.printAll();
    }
}

