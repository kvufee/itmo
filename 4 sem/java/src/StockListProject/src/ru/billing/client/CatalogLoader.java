package ru.billing.client;

import ru.billing.stocklist.Category;
import ru.billing.stocklist.ItemCatalog;
import ru.billing.stocklist.TechnicalItem;

public class CatalogLoader implements ICatalogLoader
{
    @Override
    public void load(ItemCatalog cat)
    {
        TechnicalItem item1 = new TechnicalItem("Sony TV", 23000, Category.OTHER);
        TechnicalItem item2 = new TechnicalItem("Bread", 100, Category.FOOD);

        cat.addItem(item1);
        cat.addItem(item2);
    }

    public static void main(String[] args)
    {
        ItemCatalog cat = new ItemCatalog();
        ICatalogLoader loader = new CatalogLoader();
        loader.load(cat);
        cat.printItems();
    }
}