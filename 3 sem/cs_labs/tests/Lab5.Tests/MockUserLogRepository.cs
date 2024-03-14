using System.Collections.Generic;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;

namespace Itmo.ObjectOrientedProgramming.Lab5.Tests;

public class MockUserLogRepository : IUserLogRepository
{
    public void AddLog(Account account, string data)
    {
        return;
    }

    public IList<UserLog> GetLogByAccount(Account account)
    {
        return new List<UserLog>();
    }
}