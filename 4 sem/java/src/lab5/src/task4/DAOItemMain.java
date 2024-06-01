package task4;

import task3.Item;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;

public class DAOItemMain
{
    public static void main(String[] args)
    {
        String url = "jdbc:postgresql://localhost:5432/postgres";
        String password = "postgres";
        String user = "postgres";
        Connection conn = null;
        try
        {
            Class.forName("org.postgresql.Driver");
            conn = DriverManager.getConnection(url, user, password);
        }
        catch (ClassNotFoundException | SQLException e)
        {
            e.printStackTrace();
        }

        DAOItem dao = new DAOItem(conn);

        ArrayList<Item> itemsOf = dao.searchByKeyword("of");
        ArrayList<Item> itemsGay = dao.searchByKeyword("key");

        System.out.println("Number of items with 'of' in the title: " + itemsOf.size());
        System.out.println("Number of items with 'key' in the title: " + itemsGay.size());

        System.out.println("Items with 'of' in the title: " + itemsOf);
        System.out.println("Items with 'key' in the title: " + itemsGay);
    }
}
