using Lab5.Application.Abstractions.Service;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;

namespace Lab5.Application.Service;

public class AccountService : IAccount
{
    private readonly User _user;
    private readonly IAccountRepository _accountRepository;
    private readonly IUserLogRepository _userLogRepository;

    public AccountService(User user, IAccountRepository accountRepository, IUserLogRepository userLogRepository)
    {
        _user = user;
        _accountRepository = accountRepository;
        _userLogRepository = userLogRepository;
    }

    public void AddMoney(int amount)
    {
        Account account = GetUserAccount();

        int newBalance = account.Balance + amount;
        account.SetBalance(newBalance);

        _accountRepository.UpdateUserBalance(account, newBalance);
        _userLogRepository.AddLog(account, $"Add {amount}");
    }

    public void WithdrawMoney(int amount)
    {
        Account account = GetUserAccount();
        int newBalance = account.Balance - amount;

        if (newBalance >= 0)
        {
            account.SetBalance(newBalance);
        }
        else
        {
            throw new ArgumentOutOfRangeException(nameof(amount), "You don't have that much money");
        }

        _accountRepository.UpdateUserBalance(account, newBalance);
        _userLogRepository.AddLog(account, $"Removed {amount}");
    }

    public int GetBalance()
    {
        return GetUserAccount().Balance;
    }

    public Account GetAccountByUserId(int id)
    {
        return _accountRepository.GetUserById(id);
    }

    public Account GetUserAccount()
    {
        return _accountRepository.GetUserAccount(_user);
    }

    public IList<UserLog> GetUserLogs()
    {
        return _userLogRepository.GetLogByAccount(GetUserAccount());
    }
}