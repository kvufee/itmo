package ru.billing.stocklist;

public class TechnicalItem extends GenericItem {
    short warrantlyTime;

    @Override
    public void PrintAll() {
        super.PrintAll();
        System.out.println(warrantlyTime);
    }
}
