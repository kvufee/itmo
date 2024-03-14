using System;
using Lab5.Application.Abstractions.Service;
using Lab5.Application.Models;
using Lab5.Application.Service;
using Xunit;

namespace Itmo.ObjectOrientedProgramming.Lab5.Tests;

public class UnitTest
{
    private User _user = new User(1, "bobik", "gav123", UserRole.Default);

    [Fact]
    public void SuccessAddMoney()
    {
        var accountRepository = new MockAccountRepository();
        var userLogRepository = new MockUserLogRepository();
        IAccount accountService = new AccountService(_user, accountRepository, userLogRepository);

        accountService.AddMoney(228);

        Assert.Equal(228, accountService.GetUserAccount().Balance);
    }

    [Fact]
    public void SuccessWithdrawMoney()
    {
        var accountRepository = new MockAccountRepository();
        var userLogRepository = new MockUserLogRepository();
        IAccount accountService = new AccountService(_user, accountRepository, userLogRepository);

        accountService.AddMoney(1400);
        accountService.WithdrawMoney(63);

        Assert.Equal(1337, accountService.GetUserAccount().Balance);
    }

    [Fact]
    public void FailWithdrawMoney()
    {
        var accountRepository = new MockAccountRepository();
        var userLogRepository = new MockUserLogRepository();
        IAccount accountService = new AccountService(_user, accountRepository, userLogRepository);

        accountService.AddMoney(228);

        Exception ex = Assert.Throws<ArgumentOutOfRangeException>(() => accountService.WithdrawMoney(666));
        Assert.Equal("You don't have that much money (Parameter 'amount')", ex.Message);
    }
}