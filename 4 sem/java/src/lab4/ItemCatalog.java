package lab4;

import lab3.Item;

import java.util.ArrayList;
import java.util.HashMap;

public class ItemCatalog
{
    private final HashMap<Integer, Item> catalog = new HashMap<Integer, Item>();
    private final ArrayList<Item> ALCatalog = new ArrayList<Item>();

    public void addItem(Item item)
    {
        catalog.put(item.ID, item);
        ALCatalog.add(item);
    }

    public void printItems()
    {
        for(Item i : ALCatalog)
        {
            System.out.println(i);
        }
    }

    public Item findItemById(int id)
    {
        if(!catalog.containsKey(id))
        {
            return null;
        }
        else
        {
            return catalog.get(id);
        }
    }

    public Item findItemByIdArray(int id)
    {
        for(Item i : ALCatalog)
        {
            if(i.ID==id) return i;
        }

        return null;
    }

    public static void main(String[] args)
    {
        ItemCatalog catalog = new ItemCatalog();

        for (int i = 0; i < 10; i++)
        {
            Item item = new Item();
            item.ID = i;
            catalog.addItem(item);
        }


        long begin1 = new java.util.Date().getTime();

        for(int i = 0; i < 10000000; ++i)
        {
            catalog.findItemById(10);
        }

        long end1 = new java.util.Date().getTime();
        System.out.println("HashMap: "+(end1-begin1));

        long begin2 = new java.util.Date().getTime();

        for(int i = 0; i < 10000000; ++i)
        {
            catalog.findItemByIdArray(10);
        }

        long end2 = new java.util.Date().getTime();
        System.out.println("ArrayList: "+(end2-begin2));
    }
}
