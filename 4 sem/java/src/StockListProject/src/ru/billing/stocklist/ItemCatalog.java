package ru.billing.stocklist;

import java.util.ArrayList;
import java.util.HashMap;

public class ItemCatalog
{
    private final HashMap<Integer, TechnicalItem> catalog = new HashMap<Integer, TechnicalItem>();
    private final ArrayList<TechnicalItem> ALCatalog = new ArrayList<TechnicalItem>();

    public void addItem(TechnicalItem item)
    {
        catalog.put(item.getID(), item);
        ALCatalog.add(item);
    }

    public void printItems()
    {
        for(TechnicalItem i : ALCatalog)
        {
            System.out.println(i);
        }
    }

    public TechnicalItem findItemById(int id)
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

    public TechnicalItem findItemByIdArray(int id)
    {
        for(TechnicalItem i : ALCatalog)
        {
            if(i.getID()==id) return i;
        }

        return null;
    }

    public static void main(String[] args)
    {
        ItemCatalog catalog = new ItemCatalog();

        for (int i = 0; i < 10; i++)
        {
            TechnicalItem item = new TechnicalItem();
            item.setID(i);
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
