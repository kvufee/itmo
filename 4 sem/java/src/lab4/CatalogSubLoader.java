package lab4;

import lab3.Food;
import lab3.Item;
import lab3.Category;

import java.time.LocalDate;

public class CatalogSubLoader implements ICatalogLoader
{
    @Override
    public void load(ItemCatalog cat)
    {
        Item item1 = new Item("Sony TV", 23000, Category.OTHER);
        Item item2 = new Item("Bread", 100, Category.FOOD);

        cat.addItem(item1);
        cat.addItem(item2);
    }

    public static void main(String[] args)
    {
        ItemCatalog cat = new ItemCatalog();
        ICatalogLoader loader = new CatalogSubLoader();
        loader.load(cat);
        cat.printItems();
    }
}
