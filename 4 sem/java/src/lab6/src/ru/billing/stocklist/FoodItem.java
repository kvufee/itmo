package lab6.src.ru.billing.stocklist;

import java.time.LocalDate;
import java.util.Date;

public class FoodItem extends ru.billing.stocklist.GenericItem {
    Date dateOfIncome;
    short expires;

    public FoodItem(String name, float price, FoodItem analog, Date date, short expires) {
        super(name, price, analog);
        this.dateOfIncome = date;
        this.expires = expires;
    }

    public FoodItem(String name, float price, short expires) {
        this(name, price, null, new Date(), expires);
    }

    public FoodItem(String name) {
        this(name, 0.0f, (short) 0);
    }

    @Override
    public void PrintAll() {
        super.PrintAll();
        System.out.printf(String.valueOf(dateOfIncome), expires);
    }
}
