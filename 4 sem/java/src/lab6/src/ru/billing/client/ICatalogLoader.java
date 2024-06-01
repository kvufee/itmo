package ru.billing.client;

import ru.billing.exceptions.CatalogLoadException;
import ru.billing.stocklist.ItemCatalog;

public interface ICatalogLoader {
    void load(ItemCatalog cat) throws CatalogLoadException;
}