package task3;

import java.sql.SQLException;
import java.sql.Connection;
import java.sql.DriverManager;

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
        catch (SQLException e)
        {
            e.printStackTrace();
        } catch (ClassNotFoundException e)
        {
            throw new RuntimeException(e);
        }

        DAOOracleItem dao = new DAOOracleItem(conn);
        Item item = dao.selectItem(1);

        System.out.println("Item: " + item);
    }
}