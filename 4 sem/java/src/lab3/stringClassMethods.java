package lab3;

public class stringClassMethods
{
    public static void main(String[] args)
    {
        String line = "Конфеты 'маска';45;120";
        String[] item_fld = line.split(";");

        Food foodItem = new Food(item_fld[0], Integer.parseInt(item_fld[1]), (short) Integer.parseInt(item_fld[2]));
        foodItem.printAll();
    }
}
