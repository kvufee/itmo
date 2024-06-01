package ru.billing.exceptions;

public class CatalogLoadException extends Exception {
    public CatalogLoadException(String cause)
    {
        super(cause);
    }
}
