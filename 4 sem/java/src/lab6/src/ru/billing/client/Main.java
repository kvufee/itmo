package lab6.src.ru.billing.client;

import lab6.src.ru.billing.stocklist.FoodItem;
import lab6.src.ru.billing.stocklist.TechnicalItem;
import ru.billing.exceptions.CatalogLoadException;
import lab6.src.ru.billing.stocklist.GenericItem;
import ru.billing.stocklist.ItemCatalog;

import java.util.Date;

public class Main {
    public static void main(String[] args) throws CatalogLoadException {
        GenericItem item = new GenericItem();
        FoodItem foodItem = new FoodItem("-");
        TechnicalItem technicalItem = new TechnicalItem();
        ItemCatalog cat = new ItemCatalog();
        lab6.src.ru.billing.client.CatalogLoader loader = new lab6.src.ru.billing.client.CatalogLoader();

        item.ID = 1;
        item.name = "Товар 1";
        item.price = 100.0f;

        foodItem.ID = 1;
        foodItem.name = "Еда 1";
        foodItem.price = 100.0f;

        technicalItem.ID = 2;
        technicalItem.name = "Техника 1";
        technicalItem.price = 200.0f;

        GenericItem[] items = {item, foodItem, technicalItem};

        for (GenericItem currentItem : items) {
            currentItem.PrintAll();
        }

        String line = "Sweets 'Mask';45;120";
        String[] item_fld = line.split(";");

        String name = item_fld[0];
        float price = Float.parseFloat(item_fld[1]);
        short expires = Short.parseShort(item_fld[2]);

        FoodItem itemFromLine = new FoodItem(name, price, expires);
        itemFromLine.PrintAll();

        for (int i = 0; i < 10; i++) {
            GenericItem item4 = new GenericItem();
            item4.ID = i;
            item4.name = "Товар " + i;
            item.price = 100.0f + i;
            cat.addItem(item);
        }

        long begin = new Date().getTime();
        for (int i = 0; i < 100000; i++)
            cat.findItemByID(10);
        long end = new Date().getTime();
        System.out.println("In HashMap: " + (end - begin));

        begin = new Date().getTime();
        for (int i = 0; i < 100000; i++)
            cat.findItemByIDAL(10);
        end = new Date().getTime();
        System.out.println("In ArrayList: " + (end - begin));

        loader.load(cat);
        cat.printItems();
    }
}