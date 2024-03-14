using Lab5.Application.Models;

namespace Lab5.DataAccess.Abstractions;

public interface IUserLogRepository
{
    void AddLog(Account account, string data);
    IList<UserLog> GetLogByAccount(Account account);
}