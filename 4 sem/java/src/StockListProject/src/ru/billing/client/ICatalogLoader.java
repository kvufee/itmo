package ru.billing.client;

import ru.billing.stocklist.ItemCatalog;

public interface ICatalogLoader
{
    public void load(ItemCatalog cat);
}
