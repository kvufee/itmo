package lab6.src.ru.billing.client;

import ru.billing.stocklist.Category;
import lab6.src.ru.billing.stocklist.FoodItem;
import lab6.src.ru.billing.stocklist.GenericItem;
import ru.billing.stocklist.ItemCatalog;

import java.util.Date;

public class CatalogSubLoader implements ru.billing.client.ICatalogLoader {
    public void load(ItemCatalog cat) {
        GenericItem item1 = new GenericItem("Sony TV", 23000, Category.General);
        FoodItem item2 = new FoodItem("Bread", 12, null, new Date(), (short) 10);

        cat.addItem(item1);
        cat.addItem(item2);
    }
}