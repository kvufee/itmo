using System.Collections.Generic;
using System.Linq;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;

namespace Itmo.ObjectOrientedProgramming.Lab5.Tests;

public class MockAccountRepository : IAccountRepository
{
    private ICollection<Account> _accounts = new List<Account>()
    {
        new Account(1, 111, 0),
        new Account(2, 222, 0),
        new Account(3, 333, 0),
    };

    public Account GetUserById(int id)
    {
        return new Account(1, 111, 1);
    }

    public Account GetUserAccount(User user)
    {
        return _accounts.Single(x => (x.Id == user.Id));
    }

    public void UpdateUserBalance(Account account, int amount)
    {
        Account tempAccount = _accounts.First(x => (x.Id == account.Id));

        tempAccount.SetBalance(amount);
    }
}