namespace Lab5.Application.Models;

public class Account
{
    public Account(int id, int userId, int balance)
    {
        Id = id;
        UserId = userId;
        Balance = balance;
    }

    public int Id { get; }
    public int UserId { get; }
    public int Balance { get; private set; }

    public void SetBalance(int balance)
    {
        Balance = balance;
    }
}