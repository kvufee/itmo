using Itmo.Dev.Platform.Postgres.Connection;
using Itmo.Dev.Platform.Postgres.Extensions;
using Lab5.Application.Models;
using Lab5.DataAccess.Abstractions;
using Npgsql;

namespace Lab5.DataAccess.Repositories;

public class AccountRepository : IAccountRepository
{
    private readonly IPostgresConnectionProvider _connectionProvider;

    public AccountRepository(IPostgresConnectionProvider connectionProvider)
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

    public Account GetUserById(int id)
    {
        const string sqlRequestForUserData =
            """
                SELECT * FROM ACCOUNTS
                WHERE user_id = $user_id
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        sqlCommand.AddParameter("user_id", id);
        using NpgsqlDataReader sqlReader = sqlCommand.ExecuteReader();

        while (sqlReader.Read())
        {
            return new Account(
                sqlReader.GetInt32(0),
                sqlReader.GetInt32(1),
                sqlReader.GetInt32(2));
        }

        return new Account(0, 0, 0);
    }

    public Account GetUserAccount(User user)
    {
        if (user is null) throw new ArgumentNullException(nameof(user));

        const string sqlRequestForUserData =
            """
                SELECT * FROM ACCOUNTS
                WHERE user_id = $user_id
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        sqlCommand.AddParameter("user_id", user.Id);
        using NpgsqlDataReader sqlReader = sqlCommand.ExecuteReader();

        while (sqlReader.Read())
        {
            return new Account(
                sqlReader.GetInt32(0),
                sqlReader.GetInt32(1),
                sqlReader.GetInt32(2));
        }

        return new Account(0, 0, 0);
    }

    public void UpdateUserBalance(Account account, int amount)
    {
        if (account == null) throw new ArgumentNullException(nameof(account));

        const string sqlRequestForUserData =
            """
                UPDATE ACCOUNTS
                SET balance = $balance
                WHERE user_id = $user_id
            """;

        using var sqlCommand = new NpgsqlCommand(sqlRequestForUserData, GetSqlConnection());
        sqlCommand.AddParameter("balance", amount);
        sqlCommand.AddParameter("user_id", account.UserId);

        sqlCommand.ExecuteNonQuery();
    }
}