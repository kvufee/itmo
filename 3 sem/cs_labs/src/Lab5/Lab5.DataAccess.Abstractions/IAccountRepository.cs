using Lab5.Application.Models;

namespace Lab5.DataAccess.Abstractions;

public interface IAccountRepository
{
    Account GetUserById(int id);
    Account GetUserAccount(User user);
    void UpdateUserBalance(Account account, int amount);
}