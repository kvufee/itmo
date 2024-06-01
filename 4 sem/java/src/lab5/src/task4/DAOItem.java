package task4;

import task3.Item;

import java.sql.*;
import java.util.ArrayList;

public class DAOItem
{
    private Connection connection;

    public DAOItem(Connection connection)
    {
        this.connection = connection;
    }

    public ArrayList<Item> searchByKeyword(String keyword)
    {
        ArrayList<Item> items = new ArrayList<>();
        String sql = "SELECT * FROM ITEM WHERE TITLE LIKE ?";
        try
        {
            PreparedStatement pstmt = connection.prepareStatement(sql);
            pstmt.setString(1, "%" + keyword + "%");
            ResultSet rs = pstmt.executeQuery();

            while (rs.next())
            {
                Item item = new Item(rs.getInt("item_id"),
                        rs.getString("title"),
                        rs.getString("artist"),
                        rs.getDate("releasedate"),
                        rs.getBigDecimal("listprice"),
                        rs.getDouble("version"));
                items.add(item);
            }
        }
        catch (SQLException e)
        {
            e.printStackTrace();
        }

        return items;
    }
}
