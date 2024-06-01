package task4;

import task3.Item;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;

public class DAOOracleItemMain
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

        DAOOracleItem dao = new DAOOracleItem(conn);
        ArrayList<Item> items = dao.selectItems(13, 10);

        System.out.println("Items: " + items);
    }
}
