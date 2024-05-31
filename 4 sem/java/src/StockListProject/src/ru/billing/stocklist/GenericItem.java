package ru.billing.stocklist;

import java.time.Instant;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Date;

public class GenericItem
{
    public static void main(String[] args)
    {
        TechnicalItem first = new TechnicalItem("Protein", 100.5F, Category.FOOD);
        TechnicalItem second = new TechnicalItem("HQD Titan", 1050F, Category.OTHER);
        FoodItem third = new FoodItem("Fish", 300.2F, (FoodItem) null, LocalDate.now(), (short) 13);
        FoodItem fourth = new FoodItem(third.getName(), third.getPrice(), third, LocalDate.now(), third.getExpires());

        first.printAll();
        second.printAll();
        third.printAll();
        fourth.printAll();
    }
}
