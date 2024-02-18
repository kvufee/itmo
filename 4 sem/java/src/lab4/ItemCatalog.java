package lab4;

import lab3.Item;

import java.util.ArrayList;
import java.util.HashMap;

public class ItemCatalog
{
    private HashMap<Integer, Item> catalog = new HashMap<Integer, Item>();
    private ArrayList<Item> ALCatalog = new ArrayList<Item>();

    public void addItem(Item item)
    {
        catalog.put(item.ID, item);
        ALCatalog.add(item);
    }
}
