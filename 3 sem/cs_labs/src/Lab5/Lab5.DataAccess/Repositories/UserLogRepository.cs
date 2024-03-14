using Itmo.Dev.Platform.Postgres.Connection;
using Itmo.Dev.Platform.Postgres.Extensions;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;
using Npgsql;

namespace Lab5.DataAccess;

public class UserLogRepository : IUserLogRepository
{
    private readonly IPostgresConnectionProvider _connectionProvider;

    public UserLogRepository(IPostgresConnectionProvider connectionProvider)
    {
        _connectionProvider = connectionProvider;
    }

    public NpgsqlConnection GetSqlConnection()
    {
        NpgsqlConnection sqlConnection = _connectionProvider
            .GetConnectionAsync(default)
            .AsTask()
            .GetAwaiter()
            .GetResult();

        return sqlConnection;
    }

    public void AddLog(Account account, string data)
    {
        if (account == null) throw new ArgumentNullException(nameof(account));

        const string sqlRequestForUserData =
            """
            INSERT INTO USER_LOGS (account_id, data)
            VALUES ($account_id, $data)
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        sqlCommand.AddParameter("account_id", account.Id);
        sqlCommand.AddParameter("data", data);

        sqlCommand.ExecuteNonQuery();
    }

    public IList<UserLog> GetLogByAccount(Account account)
    {
        if (account == null) throw new ArgumentNullException(nameof(account));

        const string sqlRequestForUserData =
            """
            SELECT * FROM USER_LOGS
            WHERE account_id = $id
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        sqlCommand.AddParameter("id", account.Id);
        using NpgsqlDataReader sqlReader = sqlCommand.ExecuteReader();

        var logs = new List<UserLog>();
        while (sqlReader.Read())
        {
            var log = new UserLog(
                sqlReader.GetInt32(0),
                sqlReader.GetInt32(1),
                sqlReader.GetString(2));

            logs.Add(log);
        }

        return logs;
    }
}