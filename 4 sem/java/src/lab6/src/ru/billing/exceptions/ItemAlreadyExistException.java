package ru.billing.exceptions;

public class ItemAlreadyExistException extends Exception {
    public ItemAlreadyExistException(String message)
    {
        super(message);
    }
}
