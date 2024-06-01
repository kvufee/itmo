package lab6.src.ru.billing.stocklist;

public class TechnicalItem extends ru.billing.stocklist.GenericItem {
    short warrantlyTime;

    @Override
    public void PrintAll() {
        super.PrintAll();
        System.out.println(warrantlyTime);
    }
}