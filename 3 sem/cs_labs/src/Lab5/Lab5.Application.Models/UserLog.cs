namespace Lab5.Application.Models;

public class UserLog
{
    public UserLog(int accountId, int logId, string logData)
    {
        AccountId = accountId;
        LogId = logId;
        LogData = logData;
    }

    public int AccountId { get; }
    public int LogId { get; }
    public string LogData { get; }
}