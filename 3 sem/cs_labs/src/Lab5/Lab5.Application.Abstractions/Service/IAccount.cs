using Lab5.Application.Models;

namespace Lab5.Application.Abstractions.Service;

public interface IAccount
{
    void AddMoney(int amount);
    void WithdrawMoney(int amount);
    int GetBalance();
    Account GetAccountByUserId(int id);
    Account GetUserAccount();
    IList<UserLog> GetUserLogs();
}